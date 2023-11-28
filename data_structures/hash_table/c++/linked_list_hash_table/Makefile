GENERAT = *.o app linked_list/*.o
CC = g++
all: app	

app: main.o hash_table.o linked_list/linked_list.o
		$(CC) $^ -o $@

%.o: %.c
		$(CC) -c $< -o $@

clean:
		rm -f $(GENERAT)