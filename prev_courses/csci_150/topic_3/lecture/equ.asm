; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>

DWORD_SIZE:     equ 4

section     .text

global      _start

_start:
    mov     al, [array]


exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h
    movzx   eax, BYTE [bval]

section     .bss

section     .data
ELEMENT_SIZE:       equ 4

array:      dd  10,11,12,13,14
len:        equ ($ - array) / ELEMENT_SIZE
