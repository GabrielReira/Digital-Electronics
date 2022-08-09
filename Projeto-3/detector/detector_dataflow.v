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
