# autobuild and clean fileIO_ex1.c fileIO_ex2.c

CC = gcc
all:
	@echo "building..."
	$(CC) file_IO_ex1.c -o generate
	$(CC) file_IO_ex2.c -o read
.PHONY: clean
clean:
	@echo "clean all files..."
	-rm generate program.txt read # "-" in "-rm" will ignore the error and continue.
	@echo "clean complete." # if we se "rm" not "-rm" 
				# when error occured, this line won't execute.	
