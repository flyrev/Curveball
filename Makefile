C_FLAGS := -O2

all:	obj/main.o obj/vector.o
	g++ -lglut -lGL -lGLEW -L/usr/X11R6/lib -o Solskogen obj/*.o
obj/vector.o: vector.cpp
	g++ $(C_FLAGS) -c -o obj/vector.o vector.cpp
obj/main.o: main.cpp
	g++ $(C_FLAGS) -c -o obj/main.o main.cpp
clean:
	rm -f obj/*

run: 	all
	./Solskogen

