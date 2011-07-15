CXXFLAGS := -O2
OBJS = $(patsubst %.cpp,%.o,$(wildcard *.cpp))

LIBS=-lglut -lGL -lGLEW
CXX=g++
TARGET=Solskogen
LDIRS=/usr/X11R6/lib

all: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(LIBS) -L$(LDIRS)

clean:
	rm -f obj/*

run: 	all
	./Solskogen

