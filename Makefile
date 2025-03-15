C_flag = gcc -Wall  -Wextra -g
object = ./hash/hash.o main.o cash.o ./list/list_page.o

hash: clear $(object) 
	$(C_flag) -o cash $(object)
	./cash

cash.o: cash.c 
	$(C_flag) -c cash.c 
hash.o: ./hash/hash.c 
	$(C_flag) -c ./hash/hash.c 
main.o: main.c 
	$(C_flag) -c test.c
list.o: ./list/list_page.c 
	$(C_flag) -c ./list/list_page.c 
clear: 
	rm -rf *.o
	rm -rf hash 