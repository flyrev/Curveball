CXXFLAGS := -g
INCLUDE_DIR=include
OBJECT_DIR=obj

SOURCES=$(wildcard *.cpp)
OBJ = $(patsubst %.cpp,$(OBJECT_DIR)/%.o,$(wildcard *.cpp))

LIBS=-lglut -lGL -lGLEW
CXX=g++
TARGET=Solskogen
LDIRS=/usr/X11R6/lib
DEPENDENCIES = $(wildcard $(INCLUDE_DIR)/*.h)

$(OBJECT_DIR)/%.o: %.cpp $(DEPENDENCIES)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

Solskogen: $(OBJ)
	$(CXX) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -f $(OBJECT_DIR)/*.o *~ *#* */*#* core $(INCLUDE_DIR)/*~ 

run: 	Solskogen
	./Solskogen

