; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>
%include "lib.inc"
section     .text

global      _start

_start:

    ;push    dword buff_sz
    ;push    buff
    ;call    get_input

    call    getchar
    cmp     al, 'g'


    push    buff
    call    atoi
; exit:  
    ; mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    ; mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    ; int     80h
    push    dword 1
    call    exit

section     .bss
buff_sz:    equ 150
buff:      resb buff_sz

section     .data