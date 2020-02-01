# autobuild example 3 and example 4,


CC = gcc
SOURCES = file_IO_ex3.c file_IO_ex4.c 
EXE = fwrite fread

%.out: %.c
	$(CC) $< -o $@ 

.PHONY: clean

clean:
	-rm -rf $(EXE) program.bin
	
