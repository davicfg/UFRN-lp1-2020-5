OBJS	= main.o Conta.o
SOURCE	= src/main.cpp src/Conta.cpp 
HEADER	= include/main.hpp include/Conta.hpp 
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

clean:
	rm -f $(OBJS) $(OUT)