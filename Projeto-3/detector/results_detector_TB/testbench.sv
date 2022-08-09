`timescale 1ns/10ps 

module detector_tb;
  reg x, clk;
  wire y;
  wire out1, out2, out3;

  // DUT - Estrutural
  detector_estrutural DUT1 (
    .x(x),
    .clk(clk),
    .y(out1)
  );

  // DUT - Dataflow
  detector_dataflow DUT2 (
    .x(x),
    .clk(clk), 
    .y(out2)
  );

  // DUT - Comportamental
  detector_comportamental DUT3 (
    .x(x),
    .clk(clk), 
    .y(out3)
  );

  initial begin
    $dumpfile("dump.vcd");
    $dumpvars;
    #10000 $finish;
  end

  // Inputs para teste
  initial begin
    clk = 0;
    x = 0;
    display_outputs;

    toggle_clk;
    display_outputs;
    
    x = 1;
    toggle_clk;
    display_outputs;

    toggle_clk;
    display_outputs;

    // A saída deve ser 1 (Mealy)
    toggle_clk;
    display_outputs;
    
    x = 0;
    toggle_clk;
    display_outputs;

    x = 1;
    toggle_clk;
    display_outputs;

    toggle_clk;
    display_outputs;

    // A saída deve ser 1 (Mealy)
    toggle_clk;
    display_outputs;

    // A saída deve ser 1
    toggle_clk;
    display_outputs;

    // A saída deve ser 1
    toggle_clk;
    display_outputs;

    x = 0;
    toggle_clk;
    display_outputs;
  end
  
  task toggle_clk;
    begin
      #10 clk = ~clk;
      #10 clk = ~clk;
    end
  endtask

  task display_outputs;
    begin
      $display("Estrutural: %b, Dataflow: %b, Comportamental: %b", out1, out2, out3);
    end
  endtask

endmodule
