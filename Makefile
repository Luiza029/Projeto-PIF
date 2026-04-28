CC = gcc #compilador sendo usado
CFLAGS = -Wall -Wextra -Iinclude #flags de compilação
LIBS = -lraylib -lm -ldl -lpthread # Bibliotecas a serem usadas

SRC = $(wildcard src/*.c) # {ega todos os arquivos .c da posta src/ 
OUT = build/jogo # O caminho final

all: # É o que compila todos os códigos do gcc quando roda o comando make
	$(CC) $(SRC) -o $(OUT) $(CFLAGS) $(LIBS)

clean: # Roda quando digita make clean e deleta o executável compilado
	rm -f $(OUT)