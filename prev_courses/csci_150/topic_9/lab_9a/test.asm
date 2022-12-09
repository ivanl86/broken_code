; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>

section     .text
%include "lib.inc"

global      _start

_start:
    push    prompt
    call    printstr
    add     esp, 4

    push    prompt
    call    to_lower
    add     esp, 4

    push    prompt
    call    printstr
    add     esp, 4

    push    buffer
    push    prompt
    call    strcopy
    add     esp, 8

    push    buffer
    call    printstr
    add     esp, 4

    push    buffer
    call    to_upper
    add     esp, 4

    push    buffer
    call    printstr
    add     esp, 4

exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

section     .bss
buffer_sz:  equ 255
buffer:     resb buffer_sz

section     .data
prompt:     db "Goodbye Cruel World. Hello MAKE!",NL , NULL