module d_ff(d, clk, q, q_bar); 
  input d, clk;
  output reg q, q_bar;

  always @(posedge clk) begin
    q <= d;
    q_bar <= !d;
  end
endmodule

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
