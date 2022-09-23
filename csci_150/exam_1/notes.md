# Exam notes
## Order of Operations
- know the order of operations
- -rVal = - xVal + (yVal - zVal)

## Find the range of signed and unsigned integer in n bits
- unsigned: [0,2^(n)-1]
- signed:   [-2^(n-1),2^(n-1)-1]

## registers
- eax
- ebx
- ecx
- edx

## lablel
- symbols for memory addresses

## Status Flags
- reflect the outcome of arithmetic and bitwise operations
- mov never affect flags
### zero flag
- set when destination equal zero
### sign flag
- set when destination is negative
### carry flag
- set when unsigned value is out of range
### overflow flag
- set when signed value is out of range

## Memory Address
- find out where a lable's memory address is

## Define Label Size
### byte size
- byte  start
- resb  BSS
- db    text
### word size (2 byte)
- word  start
- resw  BSS
- dw    text
### double word size (4 byte)
- dword start
- resd  BSS
- dd    text
### quad word size (8 byte)
- qword start
- resq  BSS
- dq    text

## Operators
### mov
- move a value from a reg/memory/immediate value to another label/reg
### movzx
- move with zero-extend: all new bits will filled with zero
### xchg
- exchange reg/memory with reg
### inc
- increment by 1
### dec
- decrement by 1
### add
- add second operand to first operand
### sub
- subtract second operand from first operand
### $
- refer to the current address
### [ ]
- dereference memory
## Loop
- mov ecx, 5    ; set the counter to 5
- .loop:        ; a local label
- do something  ; instructions in the loop
- loop .loop    ; loop back to the start of .looop

## Number Conversion
- decimal to binary
- 2's compilment
- binary to hexadecimal
- binary to octval
- write out the correct size

## Arithmetic
- addition and subtraction with binary numbers
- show carry flag/ overflow flag

## Layout of memory
### highest address
#### stack
- local variables
- function calls
#### heap
- dynamic memory allocation
#### BSS
- uninitialized global variables
#### data
- initialized global variables
#### text
- machine code
### lowest address

## Three Stages of CPU
### fetch
- fetch the next instruction
### decode
- decode the instruction
### execute
- execute the instruction

## How to assemble, link, and debug asm file
- nasm -f elf -g file.asm
- ld -m elf_i386 -o file file.o
- gdb file

## Some True or False Questions

the size of various elements: db, dw, dd, dq
true or false

offset
memory lablel
three instruction on how to assmeble, link, execute, and debug
petcat
id-10t

a value
ask to convert to memory representation
2's compilment
make sure use the corret size 16 bits etc
additin and subtraction on binary
show carry flag/ overflow flag
convert to hexdecimal from binary
know the layout of the memory
five section (name and what store in each section)
three things CPU does
four main registers
