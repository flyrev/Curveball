CXXFLAGS := -g
SOURCES=$(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.o,$(wildcard *.cpp))
LIBS=-lglut -lGL -lGLEW
CXX=g++
TARGET=Solskogen
LDIRS=/usr/X11R6/lib

all: $(OBJS)
	$(CXX) -g $(CXXFLAGS) $(OBJS) -o $(TARGET) $(LIBS) -L$(LDIRS)

clean:
	rm -f *.o

run: 	all
	./Solskogen

