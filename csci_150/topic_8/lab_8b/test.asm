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
extern print_nl

_start:
    mov eax, input_msg
    call printstr

    mov eax, inputBf
    mov ebx, bufferSz
    call get_input

    mov edx, inputBf
    call atoi

    push dword eax
    call factorial ; in eax

    mov ebx, inputBf
    mov ecx, bufferSz
    call itoa

    mov eax, output_msg
    call printstr

    mov eax, inputBf
    call printstr

    call print_nl
exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

section     .bss

bufferSz:   equ 255
inputBf:    resd bufferSz

section     .data

input_msg:      dd "Eneter a value for n: "
input_msgSz:   equ $ - input_msg
output_msg:     dd "n! = "
output_msgSz:   equ $ - output_msg