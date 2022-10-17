; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>

section     .text

global      _start
    extern NULL
    extern atoi
    extern get_input
    extern printstr

_start:
    call    fsm         ; call fsm procedure
    
exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

    fsm:
    mov     eax, msg        ; store the address of the msg into eax
    mov     ebx, msgSz      ; store the msg size into ebx
    call    printstr        ; call printstr procedure

    mov     eax, inputBf    ; store the address of buffer into eax
    mov     ebx, bufferSz   ; store the buffer size into ebx
    call    get_input       ; call get_input procedure

    mov     edx, inputBf    ; store the address of the string into  edx
    call atoi               ; call atoi to convert the string into integer value in eax

    ret

section     .bss
    bufferSz:   equ 255
    inputBf:    resd bufferSz

section     .data
    msg:    dd "Eneter a number: "
    msgSz:  equ $ - msg