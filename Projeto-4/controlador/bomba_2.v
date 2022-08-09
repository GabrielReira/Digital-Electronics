module bomba_2(alarme_b1, s1, s3, s4, clk, m2, alarme);
  input alarme_b1, s1, s3, s4, clk;
  output reg m2, alarme;

  parameter VAZIO = 2'b00;
  parameter ENCHENDO = 2'b01;
  parameter CHEIO = 2'b10;
  parameter ESVAZIANDO = 2'b11;

  reg[1:0] estado_atual, estado_futuro;

  always @(posedge clk) begin
    if (s3 == 0 & s4 == 0)
      estado_atual <= VAZIO;
    else if (s3 == 0 & s4 == 1)
      estado_atual <= ESVAZIANDO;
    else if (s3 == 1 & s4 == 0)
      estado_atual <= ENCHENDO;
    else if (s3 == 1 & s4 == 1)
      estado_atual <= CHEIO;
    else
      estado_atual <= estado_futuro;
  end

  always @(estado_atual or s1 or s3 or s4 or alarme_b1) begin
    estado_futuro = VAZIO;
    m2 = 0;
    alarme = 0;

    // Combinação impossível dos sensores da b1 ou tanque inferior abaixo de s1: desligar motor
    if (alarme_b1 | !s1)
      m2 <= 0;
    
    else begin
      case (estado_atual)
        VAZIO: begin
          // Mudar estado
          if (s3 == 1 & s4 == 0) begin
            estado_futuro <= ENCHENDO;
            m2 <= 1;
          end
          // Caso impossível: desligar motor e emitir alarme
          else if (
            (s3 == 0 & s4 == 1) | 
            (s3 == 1 & s4 == 1)
          ) begin
            estado_futuro <= VAZIO;
            m2 <= 0;
            alarme <= 1;
          end
          else if (s3 == 0 & s4 == 0) begin
            estado_futuro <= VAZIO;
            m2 <= 1;
          end
        end
        ENCHENDO: begin
          // Mudar estado
          if (s3 == 1 & s4 == 1) begin
            estado_futuro <= CHEIO;
            m2 <= 0;
          end
          // Caso impossível: desligar motor e emitir alarme
          else if (
            (s3 == 0 & s4 == 0) | 
            (s3 == 0 & s4 == 1)
          ) begin
            estado_futuro <= ENCHENDO;
            m2 <= 0;
            alarme <= 1;
          end
          else if (s3 == 1 & s4 == 0) begin
            estado_futuro <= ENCHENDO;
            m2 <= 1;
          end
        end
        CHEIO: begin
          // Mudar estado
          if (s3 == 1 & s4 == 0) begin
            estado_futuro <= ESVAZIANDO;
            m2 <= 0;
          end
          // Caso impossível: desligar motor e emitir alarme
          else if (
            (s3 == 0 & s4 == 0) | 
            (s3 == 0 & s4 == 1)
          ) begin
            estado_futuro <= CHEIO;
            m2 <= 0;
            alarme <= 1;
          end
          else if (s3 == 1 & s4 == 1) begin
            estado_futuro <= CHEIO;
            m2 <= 0;
          end
        end
        ESVAZIANDO: begin
          // Mudar estado
          if (s3 == 0 & s4 == 0) begin
            estado_futuro <= VAZIO;
            m2 <= 0;
          end
          // Caso impossível: desligar motor e emitir alarme
          else if (
            (s3 == 0 & s4 == 1) | 
            (s3 == 1 & s4 == 1)
          ) begin
            estado_futuro <= ESVAZIANDO;
            m2 <= 0;
            alarme <= 1;
          end
          else if (s3 == 1 & s4 == 0) begin
            estado_futuro <= ESVAZIANDO;
            m2 <= 0;
          end
        end
      endcase
    end
  end
endmodule
