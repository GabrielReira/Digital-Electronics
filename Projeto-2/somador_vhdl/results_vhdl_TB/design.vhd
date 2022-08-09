-- Somador 32 bits
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_signed.all;

entity adder_32 is
  port (
    x, y: in std_logic_vector(31 downto 0);
    sum: out std_logic_vector(32 downto 0)
  );
end adder_32;

architecture equation of adder_32 is
begin
  sum <= ('0' & x) + ('0' & y);
end equation;
