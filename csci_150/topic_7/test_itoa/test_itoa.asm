; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>

section     .text

global      _start
    extern  itoa
    extern  printstr
    extern  NL

_start:
    mov     eax, 1024
    mov     ebx, buffer
    call    itoa
    mov     eax, buffer
    call    printstr
    mov     eax, NL
    call    printstr


exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

section     .bss

buffer:     resb 20

section     .data