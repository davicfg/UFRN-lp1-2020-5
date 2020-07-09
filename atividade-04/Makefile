OBJS = main.o Conta.o Agencia.o Cliente.o
SOURCE = src/Conta.cpp src/Agencia src/Cliente
HEADER = include/Conta.hpp include/Agencia include/Cliente
OUT = banco
CC = g++
FLAGS = -g -c -Wall -I include
LFLAGS = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

clean:
	rm -f $(OBJS) $(OUT)