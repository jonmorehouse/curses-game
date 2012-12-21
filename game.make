CC = g++

LIB_FLAGS = -l ncurses 

#-l boost_thread-mt -l boost_system-mt

FLAGS = $(LIB_FLAGS)

DEPENDENCIES = window.o colored_window.o utilities.o hill.o game_ground.o character.o game_controller.o

# FINAL OUTPUTS
main: main.cpp $(DEPENDENCIES)
	$(CC) -o main.out main.cpp $(DEPENDENCIES) $(FLAGS) 

test: test.cpp $(DEPENDENCIES)
	$(CC) -o test.out test.cpp $(DEPENDENCIES) $(FLAGS)

# UTILITIES THAT COULD BE REUSED
# MODULES
window.o: main.h classes/window.cpp classes/colored_window.cpp
	$(CC) -c classes/window.cpp 

colored_window.o: main.h classes/window.cpp classes/colored_window.cpp
	$(CC) -c classes/colored_window.cpp

utilities.o: main.h classes/utilities.cpp
	$(CC) -c classes/utilities.cpp

game_ground.o: game_ground.h classes/hill.cpp classes/game_ground.cpp
	$(CC) -c classes/game_ground.cpp

hill.o: game_ground.h classes/hill.cpp
	$(CC) -c classes/hill.cpp

game_controller.o: game_controller.h classes/game_controller.cpp
	$(CC) -c classes/game_controller.cpp

character.o: character.h classes/character.cpp
	$(CC) -c classes/character.cpp



# CLEAN
clean:
	rm -rf *.o
	rm main.out