# Exam 2 notes
## Output
- output41

## Input
- input30

## Runtime Stack
- ss: stack segment
- esp: (stack pointer) holds the first byte at the top of the runtime stack

## Push
- decrements esp and stores data at new esp address
- push a value to the top of the runtime stack
- it can push reg, memory into esp
- only word and double word can be pushed into the stack

## Pop
- reads at esp and increments esp
- push and pop instructions occur in the opposite order

## PushAD
## PopAD

## PushFD
## PopFD

## Procedure
- is the ASM equvalent to the c++ functions
### Suggested documentation
- 
- receives: a list of input parameters
- returns: a desription of values returned
- requires: optional list of requirements called preconditions that must satisfied before the procedure is called

### Caller
- it calls a procedure
- if values in eax, ecx,and edx are needed after the call, then presevre them
### Caller's Rules

### Callee
- the procedure that is being called
- ebx, edi, esi only if it changes them
### Call instruction
- push eip into the stack
- mov eip, label
### Ret
- pop top of stack into eip

## Jump Instruction
- jmp: jump unconditionally
- jz: jump if operand resulted in zero (zero flag is set)
- jnz: jumpt if not zero

## Contol flow stctures
- control the flow of execution
### Structures
- loops
- selection statements
- procedures
### Four atomic types of control flow statments
- if
- if-else
- while
- do-while
### CF = carry flag
#### ADD
- CF = carry out of the MSB
- OF = CF xor MSB
-  0111
-  1100
- 10011
- CF: 1, OF 0
#### SUB
- CF = invert (carry out of the MSB)
- negate the source and add it to the destination
- OF = CF xor MSB
-  0111
-  1100
- 10011
- CF: 0, OF 0s
### IF
- if (i > 1)
-   i = 2;
- ; asm code
- cmp dword [ebp - 4], 1
- jle .endif
- mov dword [ebp - 4], 2
- endif:

### IF-ELSE
- 
- ; asm code
- cmp dword [ebp - 4], 2
- jle .else
- mov dword [ebp - 4], 2
- jmp .endif
- .else:
- mov dword [ebp - 4], 3
- .endif:
### WHILE(i > 2)
- while(i > 2)
-   --1;

- ; asm
- cmp dword [ebp - 4], 2
- jle .wend
- dec dword [ebp - 4]
- jmp .while
- .wend:

- ; GCC Implementation
- jump .while
- .loop:
- sub eax, 1
- .while:
- cmp dword [ebp - 4],2
- jg .loop
- .wend
### DO-WHILE
- int i;
- do
-   --i;
- while (i > 2)
- ; asm code (assumes i in eax)
- .do:
- dec dword [ebp - 4]
- cmp dword [ebp - 4], 2
- jg .do
- .end_do:
### SWITCH
- switch(i)
- {
-
- }
; asm cod
- mov eax, dword [ebp -4]
- .switch
- cmp eax, 1
- je .case1
- cmp eax, 2
- je .case2
- cmp eax, 3
- je .case3
- jump .default

- .case1:
- mov dword [ebp -4] , 4
- jmp .end_switch
- .case2:
- mov dword [ebp -4] , 5
- jmp .end_switch
- .case3:
- mov dword [ebp -4] , 6
- jmp .end_switch
- .default:
- mov dword [ebp -4] , 7
- jmp .end_switch
### And logic operator
- if (al > bl && bl > cl)
-   x = 1;
- ; asm code
- cmp al, bl
- ja L1
- jmp next
### Shift Right instructions
- if we shift left by n bits we divide by 2^n
### Shift Right instructions
- if we shift right by n bits we multiple by 2^n
### Rotate instructions
#### ROL rotate shifts each bit to the left
- the highest bit is copied into both the Carry flag and into the lowest bit
#### ROR rotate shifts each bit to the right