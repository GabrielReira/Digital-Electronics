`timescale 1ns/10ps 

module controlador_TB;
  reg s1, s2, s3, s4, clk;
  wire m1, m2;

  // DUT - Controlador Bombas
  controlador_bombas DUT (
    .s1(s1),
    .s2(s2),
    .s3(s3),
    .s4(s4),
    .clk(clk),
    .m1(m1),
    .m2(m2)
  );

  initial begin
    $dumpfile("dump.vcd");
    $dumpvars;
    #10000 $finish;
  end

  // Inputs para teste
  initial begin
    // Todos sinais em 0
    s1 = 0;
    s2 = 0;
    s3 = 0;
    s4 = 0;
    clk = 0;
    display_outputs;

    // TANQUE INFERIOR VAZIO
    // Acionado o clock, m1 deve ir para 1
    toggle_clk;
    display_outputs;

    // CASO IMPOSSÍVEL (TANQUE VAZIO)
    // Acionando s2 com s1 em 0, m1 e m2 devem ir para 0
    s2 = 1;
    toggle_clk;
    display_outputs;

    // TANQUE INFERIOR ENCHENDO
    // Acionando s1, m1 e m2 devem ir para 1
    s2 = 0;
    s1 = 1;
    toggle_clk;
    display_outputs;

    // TANQUE INFERIOR CHEIO
    // Acionando s2, m1 deve ir para 0, m2 deve permanecer em 1
    s2 = 1;
    toggle_clk;
    display_outputs;

    // TANQUE SUPERIOR ENCHENDO
    // Acionando s3, m2 deve permanecer em 1
    s3 = 1;
    toggle_clk;
    display_outputs;

    // CASO IMPOSSÍVEL (TANQUE ENCHENDO)
    // Acionando s4 com s3 em 0, m1 e m2 devem ir para 0
    s3 = 0;
    s4 = 1;
    toggle_clk;
    display_outputs;
    
    // TANQUE SUPERIOR CHEIO
    // Acionando s4, m2 deve ir para 0
    s3 = 1;
    s4 = 1;
    toggle_clk;
    display_outputs;

    // TANQUE INFERIOR ESVAZIANDO
    // s2 indo para 0, m1 deve ser acionado
    s2 = 0;
    toggle_clk;
    display_outputs;

    // TANQUE SUPERIOR ESVAZIANDO
    // s4 indo para 0, m2 deve ser acionado
    s4 = 0;
    toggle_clk;
    display_outputs;

    // TANQUE INFERIOR VAZIO
    // s1 indo para 0, m2 deve ir para 0
    s1 = 0;
    toggle_clk;
    display_outputs;

    // TANQUE INFERIOR E SUPERIOR ENCHENDO
    // m1 e m2 devem ir para 1
    s1 = 1;
    s2 = 0;
    s3 = 1;
    s4 = 0;
    toggle_clk;
    display_outputs;

    // TESTAR CASOS IMPOSSÍVEIS
    // m1 e m2 devem ir para 0
    s1 = 0;
    s2 = 1;
    toggle_clk;
    display_outputs;
    s1 = 1;
    s2 = 0;
    s3 = 0;
    s4 = 1;
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
      $display(
        "s1: %b, s2: %b, s3: %b, s4: %b, Motor 1: %b, Motor 2: %b"
        , s1, s2, s3, s4, m1, m2
      );
    end
  endtask

endmodule
