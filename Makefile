CC = gcc 
ARGU = -Wall -pedantic -c -g 

all: hormiguero space_test enemy_test clean
hormiguero: game_loop.o command.o game.o graphic_engine.o space.o game_reader.o object.o player.o set.o enemy.o
	$(CC) -o hormiguero game_loop.o command.o game.o graphic_engine.o space.o game_reader.o object.o player.o set.o enemy.o -L. -lscreen

space_test: space_test.o space.o set.o
	$(CC) -o space_test space_test.o space.o set.o


space_test.o: space_test.c space_test.h space.h test.h
	$(CC) $(ARGU) space_test.c 


enemy_test: enemy_test.o enemy.o
	$(CC) -o enemy_test enemy_test.o enemy.o


enemy_test.o: enemy_test.c enemy_test.h enemy.h test.h
	$(CC) $(ARGU) enemy_test.c 


game_loop.o: game_loop.c graphic_engine.h game.h command.h
	$(CC) $(ARGU) game_loop.c 
	
command.o: command.c command.h 
	$(CC) $(ARGU) command.c
	
game.o: game.c game.h game_reader.h set.h enemy.h
	$(CC) $(ARGU) game.c

graphic_engine.o: graphic_engine.c graphic_engine.h libscreen.h command.h space.h types.h
	$(CC) $(ARGU) graphic_engine.c

	
space.o: space.c space.h set.h
	$(CC) $(ARGU) space.c

game_reader.o: game_reader.c game_reader.h
	$(CC) $(ARGU) game_reader.c

object.o: object.c object.h
	$(CC) $(ARGU) object.c

player.o: player.c player.h
	$(CC) $(ARGU) player.c

set.o: set.c set.h
	$(CC) $(ARGU) set.c

enemy.o: enemy.c enemy.h set.h
	$(CC) $(ARGU) enemy.c

clean:
	rm -f *.o  



