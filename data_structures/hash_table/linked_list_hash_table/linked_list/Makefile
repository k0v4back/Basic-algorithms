COMPILE=gcc
GENERAT = *.o app

all: app	

app: linked_list.o
		$(CROSS_COMPILE)gcc $^ -o $@

%.o: %.c
		$(CROSS_COMPILE)gcc -c $< -o $@

clean:
		rm -f $(GENERAT)