; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>

section     .text

global      _start
    extern      atoi
    extern      get_input
    extern      printstr
    extern      NULL

_start:
    mov         eax, prompt
    call        printstr

    mov         eax, buffer
    mov         ebx, bufferSz
    call        get_input

    mov         eax, buffer
    call        atoi

exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

section     .bss
    bufferSz:   equ 100
    buffer:     resb bufferSz

section     .data
    ; valstr:     db "1024", 0
    prompt:     db "Enter an integer: ", NULL