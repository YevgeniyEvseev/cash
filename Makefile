CC = gcc -Wall  -Wextra -g
object = ./hash/hash.o cash.o ./list/list_page.o
LDFLAGS= -lcheck -lsubunit -lrt -lpthread -lm

all: hash test

hash: clear $(object) main.o
	$(CC) -o cash $(object) main.o
	./cash

test: clear $(object)
	$(CC)  -o test $(object) test.c $(LDFLAGS)

test.o: test.c
	$(CC) $(LDFLAGS) -c test.c 

cash.o: cash.c 
	$(CC) -c cash.c 
hash.o: ./hash/hash.c 
	$(CC) -c ./hash/hash.c 
main.o: main.c 
	$(CC) -c main.c
list.o: ./list/list_page.c 
	$(CC) -c ./list/list_page.c 
clear: 
	rm -rf *.o
	rm -rf ./hash/*.o 
	rm -rf ./list/*.o
	rm -f cash 