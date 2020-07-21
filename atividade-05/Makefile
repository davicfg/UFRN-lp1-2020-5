OBJS = main.o App.o Cliente.o Estabelecimento.o Produto.o Item.o Fornecedor.o
SOURCE = src/App.cpp src/main.cpp src/Cliente.cpp src/Estabelecimento.cpp src/Produto.cpp src/Item.cpp src/Fornecedor.cpp
HEADER = include/App.hpp include/Cliente.hpp include/Estabelecimento.hpp include/Produto.hpp include/vector_supermercado.hpp include/Item.hpp include/Fornecedor.hpp
OUT = supermercado
CC = g++
FLAGS = -g -c -I include -Wall
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

Item.o: src/Item.cpp
	$(CC) $(FLAGS) src/Item.cpp $(FLAGS)

Fornecedor.o: src/Fornecedor.cpp
	$(CC) $(FLAGS) src/Fornecedor.cpp $(FLAGS)

clean:
	rm -f $(OBJS) $(OUT)
	rm -rf cliente_*
	rm -rf caixa.csv