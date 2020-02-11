CXXFLAGS=-g -O2 -Wall -Wextra -std=c++11
CXX=g++

all: main

main: main.o export_matlab.o bezier.o
	${CXX} $^ -o $@

main.o: main.cpp export_matlab.hpp bezier.hpp
export_matlab.o: export_matlab.cpp export_matlab.hpp bezier.hpp
bezier.o: bezier.cpp bezier.hpp

clean:
	rm -f *.o *~ main