C_flag = gcc -Wall -Werror -Wextra
object = hash.o main.o

hash: clear $(object) 
	$(C_flag) -o hash $(object)
	./hash

hash.o: hash.c 
	$(C_flag) -c hash.c 
main.o: main.c 
	$(C_flag) -c main.c
clear: 
	rm -rf *.o