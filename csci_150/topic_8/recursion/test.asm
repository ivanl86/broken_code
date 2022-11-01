; who: Ivan Leung ileung2
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>

section     .text

global      _start
extern sum

_start:
    push dword 100
    call sum


exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

section     .bss

section     .data