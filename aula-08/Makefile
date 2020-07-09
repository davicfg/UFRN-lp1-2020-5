OBJS	= src/App.o src/Date.o src/Diary.o src/main.o src/Time.o src/Util.o
SOURCE	= src/App.cpp src/Date.cpp src/Diary.cpp src/main.cpp src/Time.cpp src/Util.cpp
HEADER	= include/App.h include/Date.h include/Diary.h include/main.h include/Time.h include/Util.h
OUT	= diary
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

src/App.o: src/App.cpp
	$(CC) $(FLAGS) src/App.cpp -std=c++11

src/Date.o: src/Date.cpp
	$(CC) $(FLAGS) src/Date.cpp -std=c++11

src/Diary.o: src/Diary.cpp
	$(CC) $(FLAGS) src/Diary.cpp -std=c++11

src/main.o: src/main.cpp
	$(CC) $(FLAGS) src/main.cpp -std=c++11

src/Time.o: src/Time.cpp
	$(CC) $(FLAGS) src/Time.cpp -std=c++11

src/Util.o: src/Util.cpp
	$(CC) $(FLAGS) src/Util.cpp -std=c++11


clean:
	rm -f $(OBJS) $(OUT)