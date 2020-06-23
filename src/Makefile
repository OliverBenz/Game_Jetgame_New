CC = g++
SDLFLAGS = `sdl2-config --cflags --libs`

ALL: main

main: main.cpp player.o bullet.o entity.o app.o evHandler.o
	${CC} main.cpp player.o bullet.o entity.o app.o evHandler.o -o main ${SDLFLAGS}

entity.o: entity.cpp entity.hpp
	${CC} -c entity.cpp ${SDLFLAGS}

player.o: player.cpp player.hpp entity.o
	${CC} -c player.cpp entity.o

bullet.o: bullet.cpp bullet.hpp entity.o
	${CC} -c bullet.cpp entity.o

app.o: app.cpp app.hpp
	${CC} -c app.cpp ${SDLFLAGS}

evHandler.o: evHandler.cpp evHandler.hpp
	${CC} -c evHandler.cpp ${SDLFLAGS}

make clean:
	rm *.o
