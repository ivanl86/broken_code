; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>

section     .text

global      _start

_start:
    ; print prompt
    mov     eax, 4              ; write operation
    mov     ebx, 1              ; stdout
    mov     ecx, prompt         ; address of the string
    mov     edx, promptLen      ; size of string
    int     0x80                ; system call


    ; get input
    mov     eax, 3              ; read operation
    mov     ebx, 0              ; stdin
    mov     ecx, inbuffer       ; address of the input buffer
    mov     edx, buffSize       ; size of the input buffer
    int     0x80                ; system call

    ; OS returns the number of characters read on eax
modStr:
    mov     edi, inbuffer       ; 
    ;add     edi, eax            ; 
    ;dec     edi                 ; 
    mov     byte [edi + eax - 1], 0       ; 

afterMod:
    mov     edx, eax            ; number of char in input buffer
    mov     eax, 4              ; write op
    mov     ebx, 1              ; stdout
    mov     ecx, inbuffer       ; input buffer
    int     0x80                ; system call

exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

section     .bss
    buffSize:   equ 8
    inbuffer:   resb buffSize

section     .data
    prompt:     db "Enter your name: "
    promptLen:  equ $ - prompt