CXXFLAGS = -g -std=c++11 -Wall -Wextra -Wpedantic -pedantic-errors
#CXXFLAGS = -g -std=c++11 -Wall -Wextra -Wpedantic -Werror -pedantic-errors


project=main

all : ${project}

${project} : image.o color.o main.o
	g++ $^ -o ${project}

image.o : image.cpp  image.hpp
color.o : color.cpp  color.hpp
main.o: main.cpp image.hpp color.hpp

clean : 
	rm -rf *.o

mrproper : clean
	rm -rf create_story
