all:
	g++ ./src/*.cpp -o ./build/main.exe -O2 -Wall -Wno-missing-braces -I ./include/ -L ./lib/ -lraylib -lopengl32 -lgdi32 -lwinmm

compile-and-run:
	g++ ./src/*.cpp -o ./build/main.exe -O2 -Wall -Wno-missing-braces -I ./include/ -L ./lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
	./build/main.exe