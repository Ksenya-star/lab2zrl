CC = gcc
CFLAGS = -Wall -g
OBJ = main.o sed_operations.o regex_util.o
EXEC = sed_simplified

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

main.o: main.c sed_operations.h regex_util.h
	$(CC) $(CFLAGS) -c main.c

operations.o: sed_operations.c sed_operations.h regex_util.h
	$(CC) $(CFLAGS) -c sed_operations.c

file_utils.o: regex_util.c regex_util.h
	$(CC) $(CFLAGS) -c regex_util.c

clean:
	rm -f $(OBJ) $(EXEC)
