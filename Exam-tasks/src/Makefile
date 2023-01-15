CC = gcc
CFLAGS = -Wall -Werror -Wextra
P = ../build/
TASKS = Task_1 Task_2 Task_3 Task_4 Task_5 Task_6 Task_7 Task_8 Task_9
ANDRC = 1.c 6.c 8.c 11.c 16.c 17.c 18.c delete_substring.c sort_matrix_rows.c students.c polindrom.c
AEXECS = $(ANDRC:.c=)
FILE = main.c

all: $(TASKS) $(AEXECS)

$(TASKS): $(FILE)
	$(CC) $(CFLAGS) -D $@ $(FILE) -o $(P)$@

$(AEXECS): $(ANDRC)
	$(CC) $(CFLAGS) $< -o $(P)$@

clean:
	rm -rf *.o ../build/[!.gitkeep]*