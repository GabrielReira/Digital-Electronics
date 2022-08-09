// Testbench do somador 16 bits Verilog
module adder_16_TB;
  reg [15:0] x, y;
  reg cin;
  wire [15:0] sum;
  wire cout;

  adder_16 uut(x, y, cin, sum, cout);

  initial begin
    $dumpfile("dump.vcd");
    $dumpvars;
    #10000 $finish;
  end

  initial begin
    $monitor($time," x=%d, y=%d, cin=%d, cout=%d, sum=%d",x,y,cin,cout,sum);
  end
  
  initial begin
    x=16'd0; y=16'd0; cin=0;
    
    #5 x=16'd0; y=16'd0;
    #5 x=16'd1; y=16'd1;
    #5 x=16'd200; y=16'd333; 
    
    #5 cin=1;
    #5 x=16'd0; y=16'd1;
    #5 x=16'd200; y=16'd1000;
  end
endmodule
// Passou em todos os testes
