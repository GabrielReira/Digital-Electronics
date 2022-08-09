`default_nettype none
`timescale 1ns / 1ps

module top_pong ( 
    input  wire logic clk_pix,
    input  wire logic sim_rst,
    input  wire logic btn_fire,
    input  wire logic btn_up,
    input  wire logic btn_dn,
    // Outputs para saída de vídeo
    output      logic [9:0] sdl_sx,  // horizontal SDL READY
    output      logic [9:0] sdl_sy,  // vertical SDL READY
    output      logic sdl_de,        // data enable (low in blanking interval)
    output      logic [7:0] sdl_r,   // 8-bit red
    output      logic [7:0] sdl_g,   // 8-bit green
    output      logic [7:0] sdl_b    // 8-bit blue
    );


    parameter
        WIN     =  5,  // valor para ganhar o jogo
        SPEEDUP =  5,  // depois dessa quantidade de rebatidas a velocidade da bola aumenta
        B_SIZE  =  20,  // tamanho da bola
        B_VELX  =  9,  // velocidade horizontal inicial da bola
        B_VELY  =  5,  // velocidade vertical inicial da bola
        P_ALT   = 48,  // altura do paddle
        P_LARG  = 10,  // largura do paddle
        P_OFF   = 35,  // distância do paddle da borda
        P_VEL   =  7,  // velocidade vertical do paddle
        H_RES  = 640,  // resolução horizontal
        V_RES  = 480;  // resolução vertical
  
    // Variáveis para configuração de vídeo
    logic [9:0] sx, sy;
    logic de;
    simple_480p display_inst (
        .clk_pix,
        .rst_pix(sim_rst),
        .sx,
        .sy,
        .hsync(),
        .vsync(),
        .de
    );
    logic frame;
    always_comb frame = (sy == V_RES && sx == 0);

    // Placar dos jogadores
    logic [3:0] scoreEsquerda;
    logic [3:0] scoreDireita;

    // Objetos na tela
    logic bola, padEsquerda, padDireita, borda;

    // Propriedades da movimentação da bola
    logic [9:0] bolaX, bolaY;       // Posições x e y da bola
    logic [9:0] bolaVelX;           // Velocidade horizontal da bola
    logic [9:0] bolaVelY;           // Velocidade vertical da bola
    logic [3:0] contadorRebatidas;  // Número de vezes que a bola é rebatida
    logic movDireita, movBaixo;     // Direção: ativo é direita/baixo
    logic movAnterior;              // Direção da bola no tick anterior
    logic colDireita, colEsquerda;  // Indica colisão na tela

    // Propriedades dos paddles
    logic [9:0] playY, compY;

    // FSM: gerenciar o jogo
    enum {NEW_GAME, READY, PLAY, END_GAME} state, next_state;
    always_comb begin
        case (state)
            NEW_GAME: next_state = READY;
            READY: begin
				if (btn_fire==1) begin
					next_state = PLAY;
				end else begin
					next_state = READY;
				end
			end
			PLAY: begin
                if (colEsquerda || colDireita) begin
                    if ((scoreEsquerda == WIN) || (scoreDireita == WIN)) begin
						next_state = END_GAME;
					end else begin 
						next_state = READY;
					end
				end else begin
					next_state = PLAY;
				end
            end
            END_GAME: begin
				if (btn_fire==1) begin
					next_state = NEW_GAME;
				end else begin
					next_state = END_GAME;
				end
			end
            default: next_state = NEW_GAME;
        endcase
        if (sim_rst) next_state = NEW_GAME;
    end

    always @(posedge clk_pix) begin
		state <= next_state;
	end

    // Movimentação da IA
    always @(posedge clk_pix) begin
        if (state == READY)
            compY <= (V_RES - P_ALT)/2;
        else if (frame && state == PLAY) begin
            if (compY + P_ALT/2 < bolaY) begin
                if (compY + P_ALT + P_VEL >= V_RES-1)
                    compY <= V_RES - P_ALT - 1;
                else
                    compY <= compY + P_VEL;
            end
            else if (compY + P_ALT/2 > bolaY + B_SIZE) begin
                if (compY < P_VEL)
                    compY <= 0;
                else
                    compY <= compY - P_VEL;
            end
        end
    end

    // Movimentação do paddle do player
    always @(posedge clk_pix) begin
        if (state == READY)
            playY <= (V_RES - P_ALT)/2;
        else if (frame && state == PLAY) begin
            if (btn_dn) begin
                if (playY + P_ALT + P_VEL >= V_RES-1) begin
                    playY <= V_RES - P_ALT - 1;
                end
                else
                    playY <= playY + P_VEL;
            end
            else if (btn_up) begin
                if (playY < P_VEL)
                    playY <= 0;
                else
                    playY <= playY - P_VEL;
            end
        end
    end

    // FSM: controle da bola
    always @(posedge clk_pix) begin
        case (state)
            NEW_GAME: begin
                scoreEsquerda <= 0;
                scoreDireita <= 0;
            end

        READY: begin
                colEsquerda <= 0;
                colDireita <= 0;
                bolaVelX <= B_VELX;
                bolaVelY <= B_VELY;
                contadorRebatidas <= 0;

                // Centralizar bola verticalmente
                bolaY <= (V_RES - B_SIZE)/2;
                bolaX <= P_OFF + P_LARG;
                movDireita <= 1; // move para direita
            end

            PLAY: begin
                if (frame) begin
                    // Bola pronta na horizontal
                    if (movDireita == 1) begin  // movendo para a direita
                        if (bolaX + B_SIZE + bolaVelX >= H_RES-1) begin
                            bolaX <= H_RES-B_SIZE;  // movendo para o canto da tela
                            scoreEsquerda <= scoreEsquerda + 1;
                            colDireita <= 1;
                        end else bolaX <= bolaX + bolaVelX;
                    end else begin
                        if (bolaX < bolaVelX) begin
                            bolaX <= 0;  // movendo para o canto da tela
                            scoreDireita <= scoreDireita + 1;
                            colEsquerda <= 1;
                        end else bolaX <= bolaX - bolaVelX;
                    end
                    // Bola pronta na vertical
                    if (movBaixo == 1) begin  // movendo para baixo
                        if (bolaY + B_SIZE + bolaVelY >= V_RES-1)
                            movBaixo <= 0;  // mover para baixo no próximo frame
                        else bolaY <= bolaY + bolaVelY;
                    end else begin  // movendo para cima
                        if (bolaY < bolaVelY)
                            movBaixo <= 1;  // mover para baixo no próximo frame
                        else bolaY <= bolaY - bolaVelY;
                    end
                    // A velocidade da bola é aumentade após certo número de rebatidas
                    if (movAnterior != movDireita) contadorRebatidas <= contadorRebatidas + 1;
                    if (contadorRebatidas == SPEEDUP) begin
                        bolaVelX <= (bolaVelX < P_LARG) ? bolaVelX + 1 : bolaVelX;
                        bolaVelY <= (bolaVelY < 2 *B_VELY) ? bolaVelY + 1 : bolaVelY;
                        contadorRebatidas <= 0;
                    end
                end
            end
        endcase

        // Mudar direção da bola após colisão com um dos paddles
        if (bola && padEsquerda && movDireita==0) movDireita <= 1;
        if (bola && padDireita && movDireita==1) movDireita <= 0;

        // Guardar posição da bola no frame anterior
        if (frame) movAnterior <= movDireita;
    end

    // Checar posição da bola e dos paddles na tela (sx,sy)
    always_comb begin
        bola = (sx >= bolaX) && (sx < bolaX + B_SIZE) && (sy >= bolaY) && (sy < bolaY + B_SIZE);
        padEsquerda = (sx >= P_OFF) && (sx < P_OFF + P_LARG) && (sy >= playY) && (sy < playY + P_ALT);
        padDireita = (sx >= H_RES - P_OFF - P_LARG - 1) && (sx < H_RES - P_OFF - 1) && (sy >= compY) && (sy < compY + P_ALT);
        // Borda da tela
        borda = ((sx == 0) || ((sx == (H_RES- 1)) )) || (((sy == 0) ) || ((sy == (V_RES-1))));
    end

    // Desenhar placar
    logic pix_score;
    simple_score simple_score_inst (
        .clk_pix(clk_pix),
        .sx(sx),
        .sy(sy),
        .score_l(scoreEsquerda),
        .score_r(scoreDireita),
        .pix(pix_score)
    );

    // Pintar os objetos
    logic [3:0] paint_r, paint_g, paint_b;
    always_comb begin
        if (pix_score) {paint_r, paint_g, paint_b} = 12'hFFF;  // placar
        else if (bola) {paint_r, paint_g, paint_b} = 12'hFC0;  // bola
        else if (padEsquerda || padDireita) {paint_r, paint_g, paint_b} = 12'h00F;  // padles
        else if (borda) {paint_r, paint_g, paint_b} = 12'hF00;  // borda
        else {paint_r, paint_g, paint_b} = 12'h000;  // background
    end

    // Outputs de vídeo: SDL output (8 bits per colour channel)
    always @(posedge clk_pix) begin
        sdl_sx <= sx;
        sdl_sy <= sy;
        sdl_de <= de;
        sdl_r <= {2{paint_r}};
        sdl_g <= {2{paint_g}};
        sdl_b <= {2{paint_b}};
    end
endmodule
