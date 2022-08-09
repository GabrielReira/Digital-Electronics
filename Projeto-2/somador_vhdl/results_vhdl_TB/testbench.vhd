-- Testbench do somador 32 bits VHDL
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity testbench is
end testbench; 

architecture adder_32_TB of testbench is

component adder_32 is
  port (
    x, y: in std_logic_vector(31 downto 0);
    sum: out std_logic_vector(32 downto 0)
  );
end component;

signal x_in, y_in: std_logic_vector(31 downto 0);
signal sum_out: std_logic_vector(32 downto 0);

begin
  DUT: adder_32 port map(x_in, y_in, sum_out);

  process
  begin   
    x_in <= "00000000000000000000000000000001";
    y_in <= "00000000000000000000000000000000";
    wait for 50 ns;
    assert(sum_out="00000000000000000000000000000001") report "Falha na soma 1" severity error;
    wait for 50 ns;

    x_in <= "00000000000000000000000000111010";
    y_in <= "00000000000000000000000010011011";
    wait for 50 ns;
    assert(sum_out="000000000000000000000000011010101") report "Falha na soma 2" severity error;
    wait for 50 ns;
    
    x_in <= "00000000000000000000000000110011";
    y_in <= "00000000000000000000000010010000";
    wait for 50 ns;
    assert(sum_out="000000000000000000000000011000011") report "Falha na soma 3" severity error;
    wait for 50 ns;
  
    x_in <= "00000000001000000000000010111011";
    y_in <= "00000000000000000000000011010011";
    wait for 50 ns;
    assert(sum_out="000000000001000000000000110001110") report "Falha na soma 4" severity error;
    wait for 50 ns;
    
    x_in <= "10000000000000000000000001100110";
    y_in <= "10000000000000000000000010011001";
    wait for 50 ns;
    assert(sum_out="100000000000000000000000011111111") report "Falha na soma 5" severity error;
    wait for 50 ns;
    
    x_in <= "11111111001001010110101001010111";
    y_in <= "10010000000000000000111111111101";
    wait for 50 ns;
    assert(sum_out="110001111001001010111101001010100") report "Falha na soma 6" severity error;
    wait for 50 ns;
  
    assert false report "Teste realizado." severity note;
    wait;
  end process;
end adder_32_TB;
-- Passou em todos os testes
