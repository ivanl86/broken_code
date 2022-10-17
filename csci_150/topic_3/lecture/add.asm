; who: Ivan Leung ileung2
; what: Addition
; why: Work in debug
; when: 9/12/2022

section     .text

global      _start

_start:
    mov     eax, [int1]
    add     eax, [int2]
    mov     [sum], eax

exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

section     .bss
sum:        resd    1   ; memory allocation to store the sum

section     .data

int1:       dd  100 ; dd = define double word 32 bit
int2:       dd  150