module d_ff(d, clk, q, q_bar); 
  input d, clk;
  output reg q, q_bar;

  always @(posedge clk) begin
    q <= d;
    q_bar <= !d;
  end
endmodule

// ESTRUTURAL
module detector_estrutural(x, clk, y);
  input x, clk;
  output y;
  wire a1, a2, b1, b2, c1, c1_bar, c2, c2_bar;

  d_ff ff1(b1, clk, c1, c1_bar);
  d_ff ff2(b2, clk, c2, c2_bar);

  or(a1, c1, c2);
  or(a2, c1, c2_bar);

  and(b1, x, a1);
  and(b2, x, a2);

  and(y, x, c1, c2);
endmodule


// DATAFLOW
module detector_dataflow(x, clk, y);
  input x, clk;
  output reg y;
  reg d0, d1;

  assign y = d0 & d1 & x;

  always @(posedge clk) begin
    d0 <= x & (d1 | ~d0);
    d1 <= x & (d1 | d0);
  end
endmodule


// COMPORTAMENTAL
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
