; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>

section     .text

global      _start

_start:

    ; mov         edx, 0x0ffbdfff1
    ; mov         eax, 0x0ffbdffff

    ; add         eax, 0x0f0000000
    ; adc         edx, 0x0f

    mov         edx, 0x01
    mov         eax, 0x00

    sub         eax, 0x01
    sbb         edx, 0

exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

section     .bss

section     .data