all: main

CXXFLAGS+=-g -Wall
LDLIBS+=-lstdc++

# Tell make which files go into the program
main: main.o dynarray.o
