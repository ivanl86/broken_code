; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>

section     .text
%include "../lib.inc"

global      _start

_start:
    mov     eax, prompt
    call    printstr


    mov     eax, 10
    push    buffer
    push    eax
    call    itoa

    mov     eax, buffer
    call    printstr

    call    print_nl

exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

section     .bss
buffer_sz:  equ 255
buffer:     resb buffer_sz

section     .data
prompt:     db "Goodbye cruel world. Hello MAKE!", NL, NULL

; arg 3 = ebp + 16
; arg 2 = ebp + 12
; arg 1 = ebp + 8
; last one 
; 
; 
; 