GENERAT = *.o prog
CC = gcc

all: prog

prog: linked_list.o main.o
	$(CC) $^ -o $@

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f $(GENERAT)
