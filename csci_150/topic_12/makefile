all: test fib

test: test.cpp ../lib.o
	g++ ../lib.o test.cpp -m32 -o test

../lib.o: ../lib.asm
	nasm -f elf ../lib.asm

fib.o: fib.asm
	nasm -felf64 fib.asm

fib: fib.o
	gcc fib.o -o fib

clean:
	rm -f fib test *.o test2 ../lib.o

# sudo apt-get install gcc-multilib g++-multilib