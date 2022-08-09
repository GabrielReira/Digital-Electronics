// Testbench do somador 32 bits Verilog
module adder_32_TB;
  reg [31:0] x, y;
  reg cin;
  wire [31:0] sum;
  wire cout;

  adder_32 uut(x, y, cin, sum, cout);

  initial begin
    $dumpfile("dump.vcd");
    $dumpvars;
    #10000 $finish;
  end

  initial begin
    $monitor($time," x=%d, y=%d, cin=%d, cout=%d, sum=%d",x,y,cin,cout,sum);
  end
  
  initial begin
    x=32'd0; y=32'd0; cin=0;
    
    #5 x=32'd0; y=32'd0;
    #5 x=32'd1; y=32'd1;
    #5 x=32'd5000; y=32'd10200; 
    
    #5 cin=1;
    #5 x=32'd0; y=32'd1;
    #5 x=32'd5000; y=32'd10207;
  end
endmodule
// Passou em todos os testes
