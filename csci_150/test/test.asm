; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.

section     .text

global      _start

_start:
    mov     al, 100
    mov     esi, array
    xor     al, al
    mov     ecx, 3

    .loop:
    add     al, [esi + ecx + 3]
    loop    .loop

exit:  
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    int     80h

section     .bss

section     .data
array       db 5,6,7,8,9,10,11,12
