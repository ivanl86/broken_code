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

### BITWISE OPERATIONS
#### AND
##
    Syntax: and dst, src
- example:
##
    mov al, 0b00111100
    and al, 0b00001111 ; al == 0b00001100
#### OR
##
    Syntax: or dst, src
- example:
##
    mov al, 0b00110011
    or  al, 0b00011110 ; al == 0b00111111
#### XOR
##
    Syntax: xor dst, src
- example:
##
    mov al, 0b00110011
    xor al, 0b00001111 ; al = 0b00111100
#### NOT
##
    Syntax: not dst
- example:
##
    mov al, 0b00110011
    not al ; al == 0b11001100
#### BITTEST
##
    Syntax: bt bitBase, n
- example: jump if bit 9 is set in AX
##
    bt ax, 9 ; CF = bit 9
    jc .label ; jump if carry

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
    jcxz: jump if cx == 0
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

#### JUMPS BASED ON SPECIFIC REGISTER OR FLAG CONDITIONS
##
    jb, jc: jump if carry flag is set
    je, jz: jump if zero flag is set
    js: jump if sign flag is set
    jne, jnz: jump if zero flag is clear
    jecxz: jump if ECX == 0

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
### SHL INSTRUCTION
- a logical left shift
- filling the lowest bit with 0
- the highest bit is copied into carry flag
- example:
##
    mov dl, 0b10101000 ; CF == 0
    shl dl, 1          ; CF:DL == 1 0b01010000
### SHR INSTRUCTION
- a logical right shift
- filling the highest bit with 0
- the lowest bit is copied into carry flag
- example:
##
    mov dl, 0b00010101 ; CF == 0
    shr dl, 1          ; CF:DL == 1 0b00001010
### SAL INSTRUCTION
- a arithmetic left shift
- identical to SHL
### SAR INSTRUCTION
- a arithmetic right shift
- preserve the sign bit
- example:
##
    mov dl, 0b10001001 ; CF == 0
    sar dl, 1          ; CF:DL == 1 0b11000100
### ROL INSTRUCTION
- rotate (shift) bits to the left
- the highest bit is copied into the carry flag and into lowest bit
- no bit lost
- example:
##
    mov al, 0b11110000 ; CF == 0
    rol al,1           ; CF:AL == 1 0b11100001
### ROR INSTRUCTION
- rotate (shift) bits to the right
- the lowest bit is copied into the carry flag and into highest bit
- no bit lost
- example:
##
    mov al, 0b111100 ; CF == 0
    ror al, 1        ; CF:AL 0 0b01111000
### RCL INSTRUCTION
- rotate (shift) with carry bits to the left
- copies the carry flag to the lowest bit
- copies the highest bit into carry flag
- example:
##
    mov al, 0b01111000 ; CF == 1
    rcl al, 1          ; CF:AL == 0 0b11110001
### RCR INSTRUCTION
- rotate (shift) with carry bits to the right
- copies the carry flag to the highest bit
- copies the lowest bit into carry flag
- example:
    mov al, 0b11110000 ; CF == 1
    rcl al, 1          ; CF:AL == 0 0b11111000
##
### SHLD INSTRUCTION
- shift a destination operand to the left
- copies highest bit into carry flag
- the lowest bit is filled with the source operand's highest bit
- source operand is not affected
- example:
##
    mov al, 0b00001111 ; CF == 1
    mov bl, 0b10000000
    shld al, bl        ; CF:AL == 0 0b00011111
### SHRD INSTRUCTION
- shift a destination operand to the right
- copies lowest bit into carry flag
- the highest bit is filled with the source operand's lowest bit
- source operand is not affected
- example:
##
    mov al, 0b00001111 ; CF == 0
    mov bl, 0b00000001
    shrd al, bl        ; CF:AL == 1 0b10000111
### UNSIGNED MULTIPLICATION INSTRUCTION
- use same size mulitplicand as the multiplier
##
    Multiplicand Multiplier Product
        AL        reg/mem8    AX
        AX        reg/mem16   DX:AX
        EAX       reg/mem32   EDX:EAX
- carry flag is set if upper half of the product contains significant digits
- example:
##
    mov ax, 20  ; multiplicand
    mov bx, 2   ; multiplier
    mul bx      ; AX = 40, CF == 0
### SIGNED MULTIPLICATION INSTRUCTION
- preserve the sign of the product by sign extend it into upper half of the product
- affects overflow flag instead of carry flag
- overflow is set when upper half of the product is not a sign extension
- example:
##
    mov eax, 4823424; multiplicand
    mov ebx, -423   ; multiplier
    imul ebx        ; EDX:EAX == FFFFFFFF86635D80h, OF == 0
    ; OF == 0 becasue EDX is a sign extension of EAX
### DIVISION INSTRUCTION
- use same szie dividend as the divisor
##
    Dividend Divisor Quotient Remainder
    AX        r/m8      AL      AH
    DX:AX     r/m16     AX      DX
    EDX:EAX   r/m32     EAX     EDX
- example:
##
    mov dx, 0   ; clear dividend
    mov ax, 100 ; dividend, low
    mov cx, 9   ; divisor
    div cx      ; Quotient: AX = 11, Remainder: DX 1
### CBW CWD CDQ INSTRUCTIONS
- cbw, cwd, cdq provide sign extension operations:
    - cbw (convert byte to word) extends AL into AH
    - cwd (convert word to dword) extends AX into DX
    - cdq (convert dword to qword) extend EAX into EDX
- example:
##
    mov eax, -101
    cdq             ; EDX:EAX == FFFFFFFFFFFFFF9Bh
### SIGNED DIVISION INSTRUCTION
- same syntax and operands as DIV instruction
- example:
##
    mov al, -48 ; dividend
    cbw         ; extend AL into AH
    mov bl, 5   ; divisor
    idiv bl     ; Quotient: AL = -9, Remainder: AH = -3
### ADC INSTRUCTION
- add with carry
- dst = dst + src + CF
- example:
##
    mov edx, 0          ; set upper half
    mov eax, 0FFFFFFFFh ; set lower half, CF == 0
    add eax, 1          ; add lower half, CF == 1
    add edx, 0          ; add upper half
    ; EDX:EAX == 00000001 00000000
### SBB INSTRUCTION
- subtract with burrow
- dst = dest - (src + CF)
- example:
##
    mov edx, 1 ; set upper half
    mov eax, 0 ; set lower half
    sub eax, 1 ; subtract lower half
    sbb edx, 0 ; subtract upper half
    ; EDX:EAX == 00000000 FFFFFFFF
## PROCEFURES
- call instruction is a ASM equivalent to c/c++ functions
    - push EIP on the stack
    - copies the address of the called procedure into EIP
- ret instruction returns from a procefure
    - pops top of the stack into EIP
### CALLER'S RULES
- before calling a subroutine, the caller should save certain registers
- the caller-saved registers are EAX, ECX, EDX
### CALLEE'S RULES
- at the beginning of the subroutine, the function should push the value of EBP onto the stack, and then copy the value of ESP into EBP
- the function must restore any callee-saved registers before returning
- the callee saved registers are EBX, EDI, ESI
### ALLOCATE LOCAL VARIABLES
    sub     esp, 8              ; reserve two 4 bytes variables
    mov     dword [ebp - 4], 0  ; set first variable = 0
    mov     dword [ebp - 8], 1  ; set second variable = 1
### STACK OPERATIONS
- PUSH operation
    - a 32 bit operatoin decrements the stack pointer (ESP) by 4
    - copies a value into the location pointed by ESP
- POP operation
    - copies value at ESP into a register or variable
    - adds n to ESP, n usually equal to 4
- example: nested loop, push outer loop counter before entering the inner loop
##
    mov ecx, 5      ; outer loop counter = 5
    .outloop:       ; start outer loop
    push ecx        ; preserve outer loop counter
    mov ecx, 5      ; inner loop counter = 5

    .innerloop:     ; start inner loop
    call procedure  ; statement
    loop .innerloop ; loop inner loop

    pop ecx         ; restore outer loop counter
    loop .outerloop ; loop outer loop