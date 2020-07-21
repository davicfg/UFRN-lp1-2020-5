OBJS	= main.o Conta.o Agencia.o Cliente.o ClientePF.o ClientePJ.o
SOURCE	= src/main.cpp src/Conta.cpp src/Agencia src/Cliente.cpp src/ClientePF.cpp src/ClientePJ.cpp
HEADER	= include/main.hpp include/Conta.hpp include/Agencia.hpp include/Cliente.hpp include/ClientePF.hpp include/ClientePJ.hpp
OUT	= banco
CC	 = g++
FLAGS	 = -g -c -Wall -I include
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: src/main.cpp
	g++ $(FLAGS) -c src/main.cpp

Conta.o: src/Conta.cpp
	$(CC) $(FLAGS) src/Conta.cpp -std=c++11

Agencia.o: src/Agencia.cpp
	$(CC) $(FLAGS) src/Agencia.cpp -std=c++11

Cliente.o: src/Cliente.cpp
	$(CC) $(FLAGS) src/Cliente.cpp -std=c++11

ClientePF.o: src/ClientePF.cpp
	$(CC) $(FLAGS) src/ClientePF.cpp -std=c++11

ClientePJ.o: src/ClientePJ.cpp
	$(CC) $(FLAGS) src/ClientePJ.cpp -std=c++11

clean:
	rm -f $(OBJS) $(OUT)