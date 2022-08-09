module controlador_bombas(s1, s2, s3, s4, clk, m1, m2);
  input s1, s2, s3, s4, clk;
  output m1, m2;
  wire alarme_b1, alarme_b2;

  bomba_1 B1 (alarme_b2, s1, s2, clk, m1, alarme_b1);
  bomba_2 B2 (alarme_b1 ,s1, s3, s4, clk, m2, alarme_b2);
endmodule
