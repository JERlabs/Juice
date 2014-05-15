CC=g++
CFLAGS= -g -c -Wall

SOURCES=vectors.cpp charges.cpp
TESTS=vector_test.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
OBJTEST=$(TESTS:.cpp=.o)
EXECUTABLES=

all: $(SOURCES) $(OBJECTS)

vectors: vectors.o 
	$(CC) $(OBJECTS) $@

charges: charges.o
    $(CC) $(OBJECTS) $@ 

.cpp.o: 
	$(CC) $(CFLAGS) $< -o $@
