all: hello.out

#declare variables
CC = gcc
INSTDIR = /usr/local/bin
INCLUDE = .
CFLAGS = -g -Wall -ansi
LIBS += -framework CoreFoundation

hello.out: hello.o 2.o 3.o
	$(CC) -o hello.out hello.o 2.o 3.o
hello.o: hello.c a.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c hello.c
2.o: 2.c a.h b.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c 2.c
3.o: 3.c b.h c.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c 3.c

.PHONY: clean
clean:
	rm -f hello.o hello.out 2.o 3.o



