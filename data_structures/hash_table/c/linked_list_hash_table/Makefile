GENERAT = *.o app linked_list/*.o
all: app	

app: main.o linked_list/linked_list.o
		gcc $^ -o $@

%.o: %.c
		gcc -c $< -o $@

clean:
		rm -f $(GENERAT)