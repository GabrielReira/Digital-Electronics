// Testbench do somador 4 bits Verilog
module adder_4_TB;
  reg [3:0] x, y;
  reg cin;
  wire [3:0] sum;
  wire cout;

  adder_4 uut(x, y, cin, sum, cout);

  initial begin
    $dumpfile("dump.vcd");
    $dumpvars;
    #10000 $finish;
  end

  initial begin
    $monitor($time," x=%b, y=%b, cin=%b, cout=%b, sum=%b",x,y,cin,cout,sum);
  end
  
  initial begin
    x=4'd0; y=4'd0; cin=0;
    
    #5 x=4'd0; y=4'd0;
    #5 x=4'd1; y=4'd1;
    #5 x=4'd7; y=4'd8; 
    
    #5 cin=1;
    #5 x=4'd0; y=4'd1;
    #5 x=4'd7; y=4'd9;
  end
endmodule
// Passou em todos os testes
