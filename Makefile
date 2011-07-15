C_FLAGS := -O2



all:	main.o
	g++ -lglut -lGL -L/usr/X11R6/lib -o Solskogen obj/*.o
main.o:	main.cpp
	g++ $(C_FLAGS) -c -o obj/main.o main.cpp
clean:
	rm -f obj/*

run: 	all
	./Solskogen

