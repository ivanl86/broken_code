
all: test.out

test.out: test.o ../lib.o
	ld -m elf_i386 test.o ../lib.o -o test.out 

test.o: test.asm ../lib.inc
	nasm -f elf -g test.asm

../lib.o: ../lib.asm
	nasm -f elf -g ../lib.asm

clean:
	rm *.o test.out

run: test.out
	./test.out

debug: test.out
	gdb test.out