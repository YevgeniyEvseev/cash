CC = gcc -Wall  -Wextra -g
object = ./hash/source/hash.o cash.o ./list/source/list_page.o
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
hash.o: ./hash/source/hash.c 
	$(CC) -c ./hash/source/hash.c 
main.o: main.c 
	$(CC) -c main.c
list.o: ./list/source/list_page.c 
	$(CC) -c ./list/source/list_page.c 
clear: 
	rm -rf *.o
	rm -rf ./hash/*.o 
	rm -rf ./list/*.o
	rm -f cash 