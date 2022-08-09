// Testbench do full adder Verilog
module full_adder_TB;
  reg x, y;
  reg cin;
  wire sum;
  wire cout;

  full_adder uut(x, y, cin, sum, cout);

  initial begin
    $dumpfile("dump.vcd");
    $dumpvars;
    #10000 $finish;
  end

  initial begin
    $monitor($time," x=%b, y=%b, cin=%b, cout=%b, sum=%b",x,y,cin,cout,sum);
  end
  
  initial begin
    x=1'd0; y=1'd0; cin=0;
    
    #5 x=1'd0; y=1'd0; 
    #5 x=1'd0; y=1'd1;
    #5 x=1'd1; y=1'd1; 
    
    #5 cin=1;
    #5 x=1'd0; y=1'd1;
    #5 x=1'd1; y=1'd1;
  end
endmodule
// Passou em todos os testes
