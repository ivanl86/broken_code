# Exam 2 Notes
## CONDITIONAL PROCESSING
- Boolean and comparison instructions, conditional jumps and loops, high level logic structures, and finite-state machines
### TEST
- performs a nondestructive AND operation in two operands
- no operands are modified
- only affects zero flag
- example: jump to a label if either bit 0 or bit 1 in AL is set
##
        test al, 0b0011 ; al == 0b0011
        jnz  valueFound

- example: jump to a label if neither bit 0 nor bit 1 in AL is set
##
        test al, 0b0011 ; al == 0b0000
        jz   valueNotFound
### COMPARE
- performs a nondestructive subtraction of source from destination
- affect zero flag and/or carry flag
##
        Syntax: cmp dst, src

- example: dst == src
##
        mov al, 5
        cmp al, 5 ; zero flag set

- example: dst < src
##
        mov al, 4
        cmp al, 5 ; carry flag set

- example: dst > src
##
        mov al, 6
        cmp al, 5 ; ZF = 0, CF = 0

- example: dst > src
##
        mov al, 5
        cmp al, -2 ; sign flag == overflow flag

- example: dst < src
##
        mov al, -1
        cmp al, 5 ; sign flag != overflow flag

### UNCONDITIONAL JUMP
- jmp is an unconditional jump to a label that is usually within the same procedure


### CONDITIONAL JUMP
- a conditional jump instruction branches to a label when specific register or flag conditions are met
#### JUMPS BASED ON FLAGS
##
    jz: jump if zero, ZF == 1
    jnz: jump if not zero, ZF == 0
    jc: jump if carry, CF == 1
    jnc: jump if not carry, CF == 0
    jo: jump if overflow, OF == 1
    jno: jump if not overflow, OF == 0
    js: jump if signed, SF == 1
    jns: jump if not signed, SF == 0
    jp: jump if parity, PF == 0
    jnp: jump if not parity, PF == 0

#### JUMPS BASED ON EQUALITY
##
    je: jump if equal (left == right)
    jne: jump if not equal (left != right)
    jecxz: jump if ECX == 0

#### JUMPS BASED ON UNSIGNED COMPARISONS
##
    ja: jump if above (if left > right)
    jnbe: jump if not below or equal (same as ja)
    jae: jump if above or equal (if left >= right)
    jnb: jump if not below (same as jae)
    jb: jump if below (if left < right)
    jnae: jump if not above or equal (same as jb)
    jbe: jump if below or equal (if left <= right)
    jna: jump if not above (same as jbe)

#### JUMPS BASED ON SIGNED COMPARISONS
##
    jg: jump if greater (if left > right)
    jnle: jump if not less or equal (same as jg)
    jge: jump if greater or equal (if left >= right)
    jnl: jump if not less (same as jge)
    jl: jump if less (if left < right)
    jnge: jump if not greater or equal (same as jl)
    jle: jump if less or equal (if left <= right)
    jng: jump if not greater (same as jle)

### FOUR BASIC CONTROL-FLOW STRUCTURES
#### IF STATEMENT
- c++ code
##
    if (i > 1)
        i = 2;
- asm code
##
    .if:
    cmp dword [ebp - 4], 1 ; compare i and 1
    jle .endif             ; if i is less than or equal to 1 jump to .endif
    mov dword [ebp - 4], 2 ; i = 2
    .endif:
#### IF-ELSE STATEMENT
- c++ code
##
    if (i > 2)
        i = 2;
    else
        i = 3;
- asm code
##
    .if:
    cmp dword [ebp - 4], 2 ; compare i and 2
    jle .else
    mov dword [ebp - 4], 2 ; if i is greater than 2, i = 2
    jmp .endif
    .else:                 
    mov dword [ebp - 4], 3 ; if i is less than or equal to 2, i = 3
    .endif:
#### WHILE LOOP
- c++ code
##
    while (i > 2)
        --i;
- asm code
##
    .while:
    cmp dword [ebp - 4], 2 ; compare i and 2
    jle .wend              ; if i is less than or equal to 2, jump to .wend
    dec dword [ebp - 4]    ; --i
    jump .while            ; jump to .while
    .wend
#### DO WHILE LOOP
- c++ code
##
    int i = 2;
    do
        --i;
    while (i > 2)
- asm code
##
    .do:
    dec dword [ebp - 4]    ; --i
    cmp dword [ebp - 4], 2 ; compare i and 2
    jg .do                 ; if i is greater than 2, jump to .do
    .end_do:
#### SWITCH
- c++ code
##
    switch(i)
    {
        case 1:
        i = 4;
        break;
        case 2:
        i = 5;
        break;
        case 3:
        i = 6;
        break;
        default:
        i = 7;
    }
- asm code
##
    mov eax, dword [ebp - 4]
    .switch
    cmp eax, 1
    je .case1
    cmp eax, 2
    je .case2
    cmp eax, 3
    je .case3
    jump .default
##
    .case1:
    mov dword [ebp - 4], 4
    jmp .end_switch
    .case2:
    mov dword [ebp - 4], 5
    jmp .end_switch
    .case3:
    mov dword [ebp - 4], 6
    jmp .end_switch
    .default:
    mov dword [ebp - 4], 7
    .end_switch
## INTEGER ARITHMETIC
- Shift and rotate instructions with useful applications, multiplication and division, extended addition and subtraction, and ASCII and packed decimal arithmetic
## PROCEFURES
- a ASM equivalent to c/c++ functions