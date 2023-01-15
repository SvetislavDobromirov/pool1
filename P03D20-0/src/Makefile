CC = gcc
CFLAGS = -Wall -Werror -Wextra
OBJECTS = string_analysis.o stack.o
EXEC = graph
PATH = ../build/

all: $(EXEC)

$(EXEC): graph.c $(OBJECTS)
	$(CC) $(CFLAGS) graph.c $(OBJECTS) -o $(PATH)$(EXEC)

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

string_analysis.o: string_analysis.c string_analysis.h
	$(CC) $(CFLAGS) -c string_analysis.c

clean:
	rm -rf *.o *.a *.out $(PATH)$(EXEC)