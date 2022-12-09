test64b_add.out: test64b_add.o ../../lib.o
	ld -m elf_i386 test64b_add.o ../../lib.o -o test64b_add.out

test64b_add.o: test64b_add.asm
	nasm -f elf -g test64b_add.asm

../../lib.o: ../../lib.asm
	nasm -f elf -g ../../lib.asm

clean:
	rm *.o *.out ../../lib.o

run: test64b_add.out
	./test64b_add.out

debug: test64b_add.out
	gdb test64b_add.out