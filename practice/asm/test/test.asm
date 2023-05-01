%include    "../stdio.inc"
%include    "../char.inc"
%include    "../stdlib.inc"

section     .text

global      _start

_start:
    ; push    str1
    ; call    putstr      ; prompt get char input
    ; call    getchar     ; get char input

    ; .if1:
    ; push    eax         ; push char to stack
    ; call    isalpha
    ; test    eax, eax    ; check if alpha
    ; jz      .else1
    ; push    str2        ; True
    ; call    putstr
    ; add     esp, 4
    ; call    putchar
    ; call    putnl
    ; jmp     .endif1
    ; .else1:
    ; push    str3        ; False
    ; call    putstr
    ; call    putnl
    ; add     esp, 4
    ; .endif1:

    ; .if2:
    ; call    isdigit     ; check if digit
    ; test    eax, eax
    ; jz      .else2
    ; push    str2        ; True
    ; call    putstr
    ; add     esp, 4
    ; call    putchar
    ; call    putnl
    ; jmp     .endif2
    ; .else2:
    ; push    str4        ; False
    ; call    putstr
    ; call    putnl
    ; add     esp, 4
    ; .endif2:

    ; .if3:
    ; call    isupper     ; check if uppercase
    ; test    eax, eax
    ; jz      .else3
    ; push    str5        ; True
    ; call    putstr
    ; call    putnl
    ; jmp     .endif3
    ; .else3:
    ; push    str6        ; False
    ; call    putstr
    ; call    putnl
    ; .endif3:
    ; add     esp, 4

    ; .if4:
    ; call    islower     ; check if lowercase
    ; test    eax, eax
    ; jz      .else4
    ; push    str7        ; True
    ; call    putstr
    ; call    putnl
    ; jmp     .endif4
    ; .else4:
    ; push    str8        ; False
    ; call    putstr
    ; call    putnl
    ; .endif4:
    ; add     esp, 4

; ----------------------------

    ; push    str
    ; call    putstr
    ; call    putnl
    ; add     esp, 4

    ; mov     esi, str
    ; mov     edi, str
    ; cld 

    ; .while:
    ; lodsb
    ; test    al, al
    ; jz      .wend
    ; push    eax
    ; call    toupper
    ; add     esp, 4
    ; stosb
    ; jmp     .while
    ; .wend:

    ; push    str
    ; call    putstr
    ; call    putnl
    ; add     esp, 4
; --------------------------

    ; call    time
    ; push    eax
    ; call    srand
    ; call    rand
    ; push    eax
    ; call    putuint
    ; call    putnl
    ; add     esp, 8

    call    time
    push    eax
    call    putuint
    call    putnl
    add     esp, 4


break:
    push    dword NO_ERROR
    call    exit
; exit:  
;     mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
;     mov     ebx, 0      ; return 0 status on exit - 'No Errors'
;     int     80h

section     .bss
buffer_sz   equ 255
buffer      resb buffer_sz
section     .data
str:        db "heLlo", 0x0
strsz:      equ $ - str
str1:       db "Enter a character: ", 0x0
str1sz:     equ $ - str1
str2:       db "You entered: ", 0x0
str2sz:     equ $ - str2
str3:       db "It is not alphabetic", 0x0
str3sz:     equ $ - str3
str4:       db "It is not numeric", 0x0
str4sz:     equ $ - str4
str5:       db "It is uppercase", 0x0
str5sz:     equ $ - str5
str6:       db "It is not uppercase", 0x0
str6sz:     equ $ - str6
str7:       db "It is lowercase", 0x0
str7sz:     equ $ - str7
str8:       db "It is not lowercase", 0x0
str8sz:     equ $ - str8