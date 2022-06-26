snakegame: main.o game.o snake.o myrandom.o
	g++ -o snakegame main.o game.o snake.o myrandom.o -lcurses
main.o: main.cpp game.h
	g++ -c main.cpp
game.o: game.cpp snake.h
	g++ -c game.cpp
snake.o: snake.cpp
	g++ -c snake.cpp
myrandom.o: myrandom.cpp
	g++ -c myrandom.cpp
clean:
	rm *.o 
	rm snakegame
	rm record.dat
