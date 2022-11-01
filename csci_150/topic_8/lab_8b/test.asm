; who: Ivan Leung
; what:Factorial
; why: Lab 8b
; when: 10/31/2022

section     .text

global      _start
extern factorial
extern get_input
extern printstr
extern atoi
extern itoa

_start:
    push dword 5
    call factorial


exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

section     .bss

bufferSz:   equ 255
inputBf:    resd bufferSz

section     .data

input_msg:      dd "Eneter a value for n: "
intput_msgSz:   equ $ - input_msg
output_msg:     dd " n! = "
output_msgSz:   equ & - output_msg