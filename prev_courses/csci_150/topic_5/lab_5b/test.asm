; who: Ivan Leung ileung2
; what: print a string that is declared in data
; why:  by calling printstr procedure to print the string
; when: 10/4/2022

section     .text

global      _start

    extern      printstr

_start:
    mov         eax, str
    mov         ebx, strSz

    call        printstr

exit:  
    mov         eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov         ebx, 0      ; return 0 status on exit - 'No Errors'
    int         0x80

section     .bss

section     .data
    str:        dd "A string has been outputted to the terminal"
    nl:         dd 0x0a
    strSz:      equ $ - str
