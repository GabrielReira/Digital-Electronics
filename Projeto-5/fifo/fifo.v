module fifo(clk, reset, data_in, write, read, empty, full, data_out);
  input clk, reset;
  input [19:0] data_in;
  input write, read;
  output reg empty, full;
  output reg [19:0] data_out;

  // 20 bits de largura e 16 bits de profundidade
  reg [19:0] fifo_memory [0:15];
  reg [3:0] read_address, write_address;
  reg [3:0] count;  // contador de operações

  // Operação de escrita
  always @(posedge clk) begin
    if ((write & !full) | (write & read)) begin
      fifo_memory[write_address] <= data_in;
    end
  end

  // Operação de leitura
  always @(posedge clk) begin
    if ((read & !empty) | (read & write)) begin
      data_out <= fifo_memory[read_address];
    end
    else begin
      data_out <= 20'bz;  // alta impedância
    end
  end

  // Controlador dos endereços de escrita e leitura
  always @(posedge clk) begin
    if (reset) begin
      write_address <= 0;
      read_address <= 0;
    end
    else begin
      if ((write & !full) | (write & read)) begin
        write_address <= write_address + 4'b0001;
      end
      if ((read & !empty) | (read & write)) begin
        read_address <= read_address + 4'b0001;
      end
    end
  end

  // Controlador do contador de operações
  always @(posedge clk) begin
    if (reset) begin
      count <= 0;
    end
    else begin
      case ({write, read})
        2'b00: begin
          count <= count;
        end
        2'b01: begin
          if (count != 4'b0000)
            count <= count - 4'b0001;
        end
        2'b10: begin
          if (count != 4'b1111)
            count <= count + 4'b0001;
        end
        2'b11: begin
          count <= count;
        end
        default:
          count <= count;
      endcase
    end
  end

  // Controlador do estado vazio da memória
  always @(count) begin
    if (count == 4'b0000) begin
      empty <= 1;
    end
    else begin
      empty <= 0;
    end
  end
  // Controlador do estado cheio da memória
  always @(count) begin
    if (count == 4'b1111) begin
      full <= 1;
    end
    else begin
      full <= 0;
    end
  end
endmodule
