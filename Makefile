#Makefile

TicTacToe: TicTacToe.cpp
	g++ $^ -o $@
clean: 
	rm -f *.o
