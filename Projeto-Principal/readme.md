## Projeto Principal

### Introdução

Pong é um jogo eletrônico lançado em 1972 pela Atari, empresa americana produtora de jogos arcade. Ele é normalmente descrito como um jogo de esporte com a temática de tênis de mesa, sendo o mesmo um dos primeiros jogos eletrônicos. O sucesso do **Pong Game** o consagrou como um jogo pioneiro que incentivou a indústria de jogos a começar. Em suma, Pong é constituído por duas raquetes, representadas como barras com mobilidade vertical, que tentam impedir uma bola de atingir as bordas laterais.

A proposta principal deste trabalho é desenvolver um jogo similar ao Pong em um FPGA através de **SystemVerilog HDL**.


### Definição do Problema de Estudo

O objetivo deste projeto é desenvolver um Pong Game em hardware.

A escolha do tema se deu a partir do interesse em entender a criação e funcionamento deste jogo tão popular. Ademais, a partir desse projeto, será possível compreender, ao menos o básico, do desenvolvimento de jogos e uso de FPGAs para sistemas digitais.

#### Objetivo Geral

O objetivo geral é implementar em hardware, a partir do uso de **FPGA**, um Pong Game desenvolvido inteiramente em Verilog/SystemVerilog com exibição gráfica e interação humano-computador.

Dessa forma, ao fim do projeto, qualquer usuário será capaz de simular uma partida de Pong contra uma máquina.

#### Objetivos Específicos

O trabalho se iniciará a partir do desenvolvimento da lógica por trás de um Pong Game, em seguida ao entendimento da exibição gráfica para VGA a partir do FPGA, depois a criação de uma inteligência capaz de enfrentar o jogador, e por último a integração de todos os módulos citados.

Assim, será aprendido a fundo a linguagem de descrição de hardware Verilog/SystemVerilog, como utilizar FPGAs na prática e a familizarização com os conceitos de eletrônica digital.


### Revisão Bibliográfica

Para o embasamento teórico do projeto será utilizado como livro base o *Introduction to Logic Circuits & Logic Design with Verilog*, do autor LaMeres. Além disso, com o objetivo de servir como fonte de pesquisas para determinados conceitos fundamentais de sistemas digitais, também será usado o livro *Digital Systems: Principles and Applications*, do Tocci.

Ademais, também será útil o uso de algumas abordagens encontradas nos sites [fpga4fun](https://www.fpga4fun.com/) e [projectf](https://projectf.io/), pois os mesmos trazem exemplos sobre aplicações de sistemas digitais aplicados a FPGAs e uso do Quartus, à exemplo do módulo [Display Signals](https://projectf.io/posts/display-signals/) e uso do [Verilator](https://projectf.io/posts/verilog-lint-with-verilator/).


---

Arquivo principal do projeto: [top_pong](https://github.com/GabrielReira/Digital-Electronics/blob/main/Projeto-Principal/projeto/pong/top_pong.sv).

Pré-requisitos para executar a simulação do Pong Game no computador: C++ Toolchain, Verilator, SDL. Para simular o jogo:

```sh
    $ cd projeto/pong
    $ make pong
    $ ./obj_dir/pong
```
