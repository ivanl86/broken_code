; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>

section     .text

global      _start
    extern  swap
    extern  swap_xor

_start:
    mov     eax, array
    lea     ebx, [array + arraySz - 4]

    call    swap_xor
    _end_swap_xor:
    ; after swap_xor, array = {9,5}

    mov     eax, array
    lea     ebx, [array + arraySz - 4]

    call swap
    _end_swap:
    ; after swap, array = {5,9}

exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

section     .bss

section     .data
    array: dd 5,9
    arraySz: equ $ - array