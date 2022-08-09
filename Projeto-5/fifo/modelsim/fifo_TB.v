`timescale 1ns/10ps 

module fifo_TB;
  reg clk, reset, write, read;
  reg [19:0] data_in;
  wire empty, full;
  wire [19:0] data_out;

  // DUT - Memória FIFO
  fifo DUT (
    .clk(clk),
    .reset(reset),
    .data_in(data_in),
    .write(write),
    .read(read),
    .empty(empty),
    .full(full),
    .data_out(data_out)
  );

  initial begin
    $dumpfile("dump.vcd");
    $dumpvars;
    #10000 $finish;
  end

  // Inputs para teste
  initial begin
    // Sinais em 0 e reset em 1
    clk = 0;
    reset = 1;
    data_in = 20'b0;
    write = 0;
    read = 0;
    display_outputs;
    toggle_clk;
    // A saída (data_out) deve ser alta impedância
    display_outputs;

    // Escrevendo registros
    reset = 0;
    write = 1;
    data_in = 20'b00000000000000000001;
    toggle_clk;
    display_outputs;
    data_in = 20'b00000000000000000011;
    toggle_clk;
    display_outputs;
    data_in = 20'b00000000000000000101;
    toggle_clk;
    display_outputs;
    
    // Ativando sinal de leitura
    // A saída do FIFO não deve ser mais alta impedância
    read = 1;
    toggle_clk;
    display_outputs;
    data_in = 20'b00000000000000001101;
    toggle_clk;
    display_outputs;

    // Desativando escrita
    write = 0;
    toggle_clk;
    display_outputs;
    // Essa entrada não deve ir para saída
    data_in = 20'b00111000000000001101;
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
      #20 $display(
        "data_in=%b, read=%b, write=%b, empty=%b ,full=%b, data_out=%b",
        data_in, read, write, empty, full, data_out
      );
    end
  endtask
endmodule

