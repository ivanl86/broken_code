; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>

section     .text

global      _start
    extern          printstr
    extern          NL

_start:
    mov         eax, msg1
    mov         ebx, msg1Sz
    call        printstr

    mov         bl, [value]
    mov         bh, [mask]  ; test bl, mask
    test        bl, bh

    jnz         .endif

    .if:
    mov         eax, msgNot
    mov         ebx, msgNotSz
    call        printstr
    .endif:
    mov         eax, msg2
    mov         ebx, msg2Sz
    call        printstr

exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

section     .bss

section     .data
    value       db 0b1011_0101
    mask        db 0b0011_1000 ; mask equ db 0b0011_1000

    msg1:       db "The bit 4, 5, or 6 was "
    msg1Sz:     equ $ - msg1

    msgNot:     db "not "
    msgNotSz:   equ $ - msgNot

    msg2:       db "set", NL
    msg2Sz:     equ $ - msg2