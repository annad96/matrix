TARGET = matrix
CC = g++
CFLAGS = -g -Wall -std=c++11

.PHONY: default all clean run $(TARGET)

default: $(TARGET)
all: default

SOURCES = Matrix/matrix.cc Matrix/testmatrix.cc
HEADERS = Matrix/matrix.h

$(TARGET):
	$(CC) $(SOURCES) $(CFLAGS) -o Matrix/$@

run:
	./$(TARGET)
	
clean:
	-rm -f $(TARGET)
	
