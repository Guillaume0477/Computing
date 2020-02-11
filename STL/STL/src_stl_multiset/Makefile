CXXFLAGS = -g -std=c++11 -Wall -Wextra -Wpedantic -pedantic-errors
#CXXFLAGS = -g -std=c++11 -Wall -Wextra -Wpedantic -Werror -pedantic-errors


project=main

all : ${project}

${project} : main.o
	g++ $^ -o ${project}

main.o: main.cpp

clean : 
	rm -rf *.o

mrproper : clean
	rm -rf create_story
