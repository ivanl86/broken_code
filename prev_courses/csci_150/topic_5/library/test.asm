; who: Ivan Leung ileung2
; what: Test library
; why: Link library
; when: 10/03/2022

section     .text

global      _start

    extern      sum_array

_start:
    mov         eax, array
    mov         ebx, qty
    call        sum_array

    mov         [sum], eax

exit:  
    mov         eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov         ebx, 0      ; return 0 status on exit - 'No Errors'
    int         80h

section     .bss
    sum         resd 1

section     .data
    array:      dd 1, 2, 3, 4, 5, 6, 7, 8 ,9
    qty:        equ ($ - array) / 4