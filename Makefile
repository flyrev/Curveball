CXXFLAGS := -O2
SOURCES=$(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.o,$(wildcard *.cpp))
LIBS=-lglut -lGL -lGLEW
CXX=g++
TARGET=Solskogen
LDIRS=/usr/X11R6/lib

echo:
	echo $(OBJS)
	echo	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(LIBS) -L$(LDIRS)

all: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -c $(LIBS) -L$(LDIRS)
	mv $(OBJS) obj/

compiles:
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(LIBS) -L$(LDIRS)

clean:
	rm -f obj/*

run: 	all
	./Solskogen

