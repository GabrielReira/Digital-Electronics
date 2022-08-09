## Projeto 1 - Revisão de FSM

Diversos protocolos de comunicação serial implementam uma técnica denominada em inglês por bit stuffing, responsável pela manutenção da integridade das mensagens do usuário. Com esta técnica, um bit oposto é inserido na mensagem sempre que uma sequência de k bits idênticos necessita ser enviado. Na recepção, este bit adicional é removido e o dado do usuário é recuperado.

A figura a seguir ilustra um exemplo do procedimento de bit stuffing para 4 bits de dados idênticos a “0”:

<p align="center">
  <img src="image.png" width="50%">
</p>

Projete um hardware responsável pela detecção de 4 bits “0” ou "1" consecutivos, de acordo com o bit de paridade associado ao seu número de matrícula ("0" se paridade par ou "1" se paridade ímpar) e que apenas sinalize através de uma saı́da em nı́vel alto para um subsistema responsável pela inserção do bit adicional.

Entregar arquivo de projeto ou link (usar qualquer simulador e testar com seu número de matrícula) e relatório simplficado em pdf.


---

Link do Projeto: https://circuitverse.org/simulator/projeto-1-engc40-t03
