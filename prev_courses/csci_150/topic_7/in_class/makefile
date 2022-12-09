testatoi.out: testatoi.o ../../lib.o
	ld -m elf_i386 testatoi.o ../../lib.o -o testatoi.out

testatoi.o: testatoi.asm
	nasm -f elf -g testatoi.asm

../../lib.o: ../../lib.asm
	nasm -f elf -g ../../lib.asm

clean:
	rm *.o *.out testatoi.o testatoi.out ../../lib.o

run: testatoi.out
	./testatoi.out

debug: testatoi.out
	gdb testatoi.out