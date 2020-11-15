# set compiler
CC = g++
# include files
INCLUDE = -I ./include
#compilers flags for compiling object files
CFLAGSO = -std=c++14 -Wall -m64 -O3 -c ${INCLUDE}
# libraries
LIBS = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
#compilers flags for compiling binary file
CFLAGSB = -s ${LIBS}

default: objCompile
	mkdir -p ./make/bin
	${CC} ./make/build/*.o -o ./make/bin/main ${CFLAGSB}
	cp -r ./res ./make/bin/res

objCompile: 
	mkdir -p ./make/build
	${CC} ./src/*.cpp ${CFLAGSO}
	# laymans way to move object files to make/build folder 
	mv *.o ./make/build
windows: winObjCompile
	mkdir -p ./make/bin
	${CC} ./make/build/*.o -o ./make/bin/main ${CFLAGSB} -mwindows
	cp -r ./res ./make/bin/res

winObjCompile: 
	mkdir -p ./make/build
	${CC} ./src/*.cpp ${CFLAGSO} -mwindows
	# laymans way to move object files to make/build folder 
	mv *.o ./make/build

web:
	em++ -std=c++14 -Wall src/main.cpp src/entity.cpp src/renderwindow.cpp src/player.cpp src/ground.cpp src/groundtile.cpp -I include -O2 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS=\['png'\] -s USE_SDL_TTF=2 -s USE_SDL_MIXER=2 --preload-file res -o index.html

