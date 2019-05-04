CC = gcc
CFLAGS = -Wall 
TARGET = frontEnd 
OBJ = main.o testTree.o parser.o scanner.o
SRC = main.c testTree.c parser.c scanner.c

all: $(TARGET) 
	
$(TARGET):$(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	/bin/rm -f *.o $(TARGET) 
