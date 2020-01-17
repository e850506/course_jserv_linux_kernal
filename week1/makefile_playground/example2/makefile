# it is a test 

hello.out: hello.o 2.o 3.o
	gcc -o hello.out hello.o 2.o 3.o
hello.o: hello.c a.h
	gcc -c hello.c
2.o: 2.c b.h
	gcc -c 2.c
3.o: 3.c a.h b.h c.h
	gcc -c 3.c

clean:
	rm -f *.o *.out

