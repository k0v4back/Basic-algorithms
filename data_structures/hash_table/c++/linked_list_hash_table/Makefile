GENERAT = *.o app linked_list/*.o
CC = g++
CXXFLAGS = -g -Wall

all: app	

app: main.o hash_table.o linked_list/linked_list.o
		$(CC) $^ -o $@

%.o: %.c
		$(CC) -c $< -o $@ $(CXXFLAGS)

clean:
		rm -f $(GENERAT)