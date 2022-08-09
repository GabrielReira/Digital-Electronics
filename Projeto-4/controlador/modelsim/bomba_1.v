module bomba_1(alarme_b2, s1, s2, clk, m1, alarme);
  input alarme_b2, s1, s2, clk;
  output reg m1, alarme;

  parameter VAZIO = 2'b00;
  parameter ENCHENDO = 2'b01;
  parameter CHEIO = 2'b10;
  parameter ESVAZIANDO = 2'b11;

  reg[1:0] estado_atual, estado_futuro;

  always @(posedge clk) begin
    if (s1 == 0 & s2 == 0)
      estado_atual <= VAZIO;
    else if (s1 == 0 & s2 == 1)
      estado_atual <= ESVAZIANDO;
    else if (s1 == 1 & s2 == 0)
      estado_atual <= ENCHENDO;
    else if (s1 == 1 & s2 == 1)
      estado_atual <= CHEIO;
    else
      estado_atual <= estado_futuro;
  end

  always @(estado_atual or s1 or s2 or alarme_b2) begin
    estado_futuro = VAZIO;
    m1 = 0;
    alarme = 0;

    // Combinação impossível dos sensores da b2: desligar motor
    if (alarme_b2)
      m1 <= 0;
    
    else begin
      case (estado_atual)
        VAZIO: begin
          // Mudar estado
          if (s1 == 1 & s2 == 0) begin
            estado_futuro <= ENCHENDO;
            m1 <= 1;
          end
          // Caso impossível: desligar motor e emitir alarme
          else if (
            (s1 == 0 & s2 == 1) | 
            (s1 == 1 & s2 == 1)
          ) begin
            estado_futuro <= VAZIO;
            m1 <= 0;
            alarme <= 1;
          end
          else if (s1 == 0 & s2 == 0) begin
            estado_futuro <= VAZIO;
            m1 <= 1;
          end
        end
        ENCHENDO: begin
          // Mudar estado
          if (s1 == 1 & s2 == 1) begin
            estado_futuro <= CHEIO;
            m1 <= 0;
          end
          // Caso impossível: desligar motor e emitir alarme
          else if (
            (s1 == 0 & s2 == 0) | 
            (s1 == 0 & s2 == 1)
          ) begin
            estado_futuro <= ENCHENDO;
            m1 <= 0;
            alarme <= 1;
          end
          else if (s1 == 1 & s2 == 0) begin
            estado_futuro <= ENCHENDO;
            m1 <= 1;
          end
        end
        CHEIO: begin
          // Mudar estado
          if (s1 == 1 & s2 == 0) begin
            estado_futuro <= ESVAZIANDO;
            m1 <= 0;
          end
          // Caso impossível: desligar motor e emitir alarme
          else if (
            (s1 == 0 & s2 == 0) | 
            (s1 == 0 & s2 == 1)
          ) begin
            estado_futuro <= CHEIO;
            m1 <= 0;
            alarme <= 1;
          end
          else if (s1 == 1 & s2 == 1) begin
            estado_futuro <= CHEIO;
            m1 <= 0;
          end
        end
        ESVAZIANDO: begin
          // Mudar estado
          if (s1 == 0 & s2 == 0) begin
            estado_futuro <= VAZIO;
            m1 <= 0;
          end
          // Caso impossível: desligar motor e emitir alarme
          else if (
            (s1 == 0 & s2 == 1) | 
            (s1 == 1 & s2 == 1)
          ) begin
            estado_futuro <= ESVAZIANDO;
            m1 <= 0;
            alarme <= 1;
          end
          else if (s1 == 1 & s2 == 0) begin
            estado_futuro <= ESVAZIANDO;
            m1 <= 0;
          end
        end
      endcase
    end
  end
endmodule
