CC=g++
CFLAGS= -g -c

SOURCES=vectors.cpp charges.cpp iterativeField.cpp Point.cpp
TESTS=vtest.cpp ctest.cpp itest.cpp
OBJECTS=$(SOURCES:.cpp=.o)


all: charges.o vectors.o iterativeField.o Point.o
tests: itest vtest ctest

itest: $(OBJECTS) itest.cpp
	$(CC) $(OBJECTS) itest.cpp -o itest

vtest: $(OBJECTS) vtest.cpp
	$(CC) $(OBJECTS) vtest.cpp -o vtest

ctest: $(OBJECTS) ctest.cpp
	$(CC) $(OBJECTS) ctest.cpp -o ctest

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o $(TESTS:.cpp=)
