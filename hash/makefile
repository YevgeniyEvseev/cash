C_flag = gcc -Wall -Werror -Wextra
object = hash.o main.o

hash: $(object)
	$(C_flag) -o hash $(object)

hash.o: hash.c 
	$(C_flag) -c hash.c 
main.o: main.c 
	$(C_flag) -c main.c 