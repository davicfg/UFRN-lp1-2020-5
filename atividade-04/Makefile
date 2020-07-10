OBJS = main.o App.o Cliente.o Estabelecimento.o Produto.o
SOURCE = src/App.cpp src/main.cpp src/Cliente.cpp src/Estabelecimento.cpp src/Produto.cpp
HEADER = include/App.hpp include/Cliente.hpp include/Estabelecimento.hpp include/Produto.hpp
OUT = loja-lp1
CC = g++
FLAGS = -g -c -Wall -I include
LFLAGS = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: src/main.cpp
	$(CC) $(FLAGS) src/main.cpp $(FLAGS)

App.o: src/App.cpp
	$(CC) $(FLAGS) src/App.cpp $(FLAGS)

Cliente.o: src/Cliente.cpp
	$(CC) $(FLAGS) src/Cliente.cpp $(FLAGS)

Estabelecimento.o: src/Estabelecimento.cpp
	$(CC) $(FLAGS) src/Estabelecimento.cpp $(FLAGS)

Produto.o: src/Produto.cpp
	$(CC) $(FLAGS) src/Produto.cpp $(FLAGS)

clean:
	rm -f $(OBJS) $(OUT)