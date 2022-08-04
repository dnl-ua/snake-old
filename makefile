all: main.o
	g++ board.cpp main.cpp -lncursesw -o main.o
