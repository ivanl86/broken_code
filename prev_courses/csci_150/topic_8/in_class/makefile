BIN=test.out
ASM=nasm
ASM_FLAGS=-f elf -g
LD=ld
LD_FLAGS=-m elf_i386 -o $(BIN)

all: $(BIN)

$(BIN): test.o ../../lib.o
	$(LD) $(LD_FLAGS) test.o ../../lib.o

test.o: test.asm ../../lib.inc
	$(ASM) $(ASM_FLAGS) test.asm

../../lib.o: ../../lib.asm
	$(ASM) $(ASM_FLAGS) ../../lib.asm

clean:
	rm ../../lib.o test.o $(BIN)

run: $(BIN)
	./$(BIN)

debug: $(BIN)
	gdb $(BIN)