; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>

section     .text

global      _start

_start:
    mov     al, -128
    neg     al          ; CF = 1, OF = 1

    mov     ax, 8000h
    add     ax, 2       ; CF = 0, OF = 0

    mov     ax, 0
    sub     ax, 2       ; CF = 1, OF = 0

    mov     al, -125
    sub     al, 5
    add     al, 1       ; CF = 0, OF = 0

exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

section     .bss

section     .data