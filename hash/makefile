C_flag = gcc -Wall  -Wextra -g
object = hash.o test.o ../list/list_page.o

hash: clear $(object) 
	$(C_flag) -o hash $(object)
	./hash

hash.o: hash.c 
	$(C_flag) -c hash.c 
main.o: main.c 
	$(C_flag) -c test.c
list.o: ../list/list_page.c 
	$(C_flag) -c ../list/list_page.c 
clear: 
	rm -rf *.o