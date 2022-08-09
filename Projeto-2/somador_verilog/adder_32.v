// Full adder
module full_adder(x, y, cin, sum, cout);
  input x, y, cin;
  output sum, cout;

  assign sum = x ^ y ^ cin;
  assign cout = (x & y) | (x & cin) | (y & cin);
endmodule

// Somador 4 bits
module adder_4(x, y, cin, sum, cout);
  input [3:0] x, y;
  input cin;
  output [3:0] sum;
  output cout;
  // Fio para ligar o carry-out de um full-adder com o carry-in do outro full-adder
  wire [2:0] cout_cin;

  full_adder adder1(x[0], y[0], cin, sum[0], cout_cin[0]);
  full_adder adder2(x[1], y[1], cout_cin[0], sum[1], cout_cin[1]);
  full_adder adder3(x[2], y[2], cout_cin[1], sum[2], cout_cin[2]);
  full_adder adder4(x[3], y[3], cout_cin[2], sum[3], cout);
endmodule

// Somador 16 bits
module adder_16(x, y, cin, sum, cout);
  input [15:0] x, y;
  input cin;
  output [15:0] sum;
  output cout;
  // Fio para fazer as ligações dos módulos
  wire [2:0] cout_cin;

  adder_4 adder1(x[3:0], y[3:0], cin, sum[3:0], cout_cin[0]);
  adder_4 adder2(x[7:4], y[7:4], cout_cin[0], sum[7:4], cout_cin[1]);
  adder_4 adder3(x[11:8], y[11:8], cout_cin[1], sum[11:8], cout_cin[2]);
  adder_4 adder4(x[15:12], y[15:12], cout_cin[2], sum[15:12], cout);
endmodule

// Somador 32 bits
module adder_32(x, y, cin, sum, cout);
  input [31:0] x, y;
  input cin;
  output [31:0] sum;
  output cout;
  // Fio para fazer as ligações dos módulos
  wire cout_cin;

  adder_16 adder1(x[15:0], y[15:0], cin, sum[15:0], cout_cin);
  adder_16 adder2(x[31:16], y[31:16], cout_cin, sum[31:16], cout);
endmodule
