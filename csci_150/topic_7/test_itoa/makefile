test_itoa.out: test_itoa.o ../../lib.o
	ld -m elf_i386 test_itoa.o ../../lib.o -o test_itoa.out

test_itoa.o: test_itoa.asm
	nasm -f elf -g test_itoa.asm

../../lib.o: ../../lib.asm
	nasm -f elf -g ../../lib.asm

clean:
	rm *.o *.out test_itoa.o test_itoa.out ../../lib.o

run: test_itoa.out
	./test_itoa.out

debug: test_itoa.out
	gdb test_itoa.out