OBJS	= App.o Date.o Diary.o main.o Time.o Util.o
SOURCE	= src/App.cpp src/Date.cpp src/Diary.cpp src/main.cpp src/Time.cpp src/Util.cpp
HEADER	= include/App.h include/Date.h include/Diary.h include/main.h include/Time.h include/Util.h
OUT	= diary
CC	 = g++
FLAGS	 = -g -c -Wall -I include
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

App.o: src/App.cpp
	$(CC) $(FLAGS) src/App.cpp -std=c++11

Date.o: src/Date.cpp
	$(CC) $(FLAGS) src/Date.cpp -std=c++11

Diary.o: src/Diary.cpp
	$(CC) $(FLAGS) src/Diary.cpp -std=c++11

main.o: src/main.cpp
	$(CC) $(FLAGS) src/main.cpp -std=c++11

Time.o: src/Time.cpp
	$(CC) $(FLAGS) src/Time.cpp -std=c++11

Util.o: src/Util.cpp
	$(CC) $(FLAGS) src/Util.cpp -std=c++11

clean:
	rm -f $(OBJS) $(OUT)
	rm -f diary