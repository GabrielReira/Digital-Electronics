module detector_comportamental(x, clk, y);
  input x, clk;
  output reg y;

  parameter S0 = 2'b00;
  parameter S1 = 2'b01;
  parameter S2 = 2'b10;
  parameter S3 = 2'b11;

  reg[1:0] estado_atual, estado_futuro;

  assign y = (estado_atual == S3 ? 1 : 0);

  always @(posedge clk) begin
    if (x == 0) begin
      estado_atual <= S0;
    end
    else begin
      estado_atual <= estado_futuro;
    end
  end

  always @(estado_atual or x) begin
    case (estado_atual)
      S0: begin
        if (x == 1)
          estado_futuro <= S1;
      end
      S1: begin
        if (x == 1)
          estado_futuro <= S2;
      end
      S2: begin
        if (x == 1)
          estado_futuro <= S3;
      end
      S3: begin
        // Se a entrada continuar sendo 1 continuará no estado S3
        if (x == 1)
          estado_futuro <= S3;
      end
    endcase
  end
endmodule
