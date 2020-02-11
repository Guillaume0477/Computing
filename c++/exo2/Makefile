CXXFLAGS = -g -std=c++11 -Wall -Wextra -Wpedantic -pedantic-errors

all : create_story

create_story : create_story.o main.o
	g++ $^ -o $@

create_story.o : create_story.cpp  create_story.hpp
main.o: main.cpp create_story.hpp

clean : 
	rm -rf *.o

mrproper : clean
	rm -rf create_story
