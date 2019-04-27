all: main

CXXFLAGS+=-g -Wall
LDLIBS+=-lstdc++

# Tell make which files go into the program
main: main.o

main.o: main.cpp dynarray.h

