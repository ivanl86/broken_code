; who: Ivan Leung ileung2
; what: Adding 5 integers together
; why: Use the debugger
; when: 9/13/2022

section     .text

global      _start

_start:
mov     eax, [int1]
add     eax, [int2]
add     eax, [int3]
add     eax, [int4]
add     eax, [int5]

mov     [sum], eax

exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

section     .bss
sum:        resd    1

section     .data

int1:       dd 0x09
int2:       dd 0x19
int3:       dd 0x05
int4:       dd 0x14
int5:       dd 0x22