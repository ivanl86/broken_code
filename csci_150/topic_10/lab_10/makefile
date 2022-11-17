
all: struct.out

struct.out: struct.o ../../lib.o
	ld -m elf_i386 struct.o ../../lib.o -o struct.out 

struct.o: struct.asm ../../lib.inc
	nasm -f elf -g struct.asm

../lib.o: ../../lib.asm
	nasm -f elf -g ../../lib.asm

clean:
	rm *.o struct.out

run: struct.out
	./struct.out

debug: struct.out
	gdb struct.out