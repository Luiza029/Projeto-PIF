CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
LIBS = -lraylib -lm -ldl -lpthread

SRC = $(wildcard src/*.c)
OUT = build/jogo

all:
	$(CC) $(SRC) -o $(OUT) $(CFLAGS) $(LIBS)

clean:
	rm -f $(OUT)