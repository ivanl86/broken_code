; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>

section     .text

global      _start

_start:

    mov     eax, 1234h
    mov     ebx, 100h
    mul     ebx
endMul:

    mov     eax, 0ffff8760h
    mov     ebx, 100h
    imul     ebx
endIMul:

    xor     ah, ah
    mov     al, 9
    mov     bl, 2
    div     bl
endDiv:

    xor     ah, ah
    mov     al, 0x80
    cbw

endSignExtend:

exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

section     .bss

section     .data