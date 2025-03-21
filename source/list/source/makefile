CC=gcc  -Wall -Werror -Wextra -g
LDFLAGS= -lcheck -lsubunit -lrt -lpthread -lm
SOURCES=main.c list_page.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=list

all: clear $(EXECUTABLE) test
        
$(EXECUTABLE): main.o list_page.o
	$(CC) main.o list_page.o -o list
test: list_page.o
	$(CC) test.c list_page.c -o test $(LDFLAGS) 

list_page.o:
	$(CC) -c list_page.c 

main.o:
	$(CC) -c main.c


clear:
	rm -rf *.o
	rm -rf list test
