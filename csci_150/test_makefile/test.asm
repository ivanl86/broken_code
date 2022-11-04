; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>

section     .text
%include "../lib.inc"

global      _start

_start:
    ; mov     eax, prompt
    ; call    printstr
    ; call print_nl
    call srand

    push prompt
    call printstr
    push prompt
    call printstr
    push prompt
    call printstr

    ; push    buffer_sz
    ; push    buffer
    ; call    get_input
    mov     eax, 8
    push    eax
    call    is_even
    test    eax, 1
    jz      not_even
    if_even:
    push    even_msg
    call    printstr
    jmp end
    not_even:
    push    not_even_msg
    call    printstr
    end:

    ; push array_element
    ; push array
    ; call sum_array
    mov eax, 9
    push eax
    push array_element
    push array
    call array_search

    ; mov     eax, 10
    push    buffer
    push    eax
    call    itoa

    ; mov     eax, buffer
    push    buffer
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
prompt:     dd "Goodbye cruel world. Hello MAKE!",NL , NULL
array:      dd 1,2,3,4,5,6,7,8,10,9
array_sz:   equ $ - array
array_element: equ array_sz / 4
even_msg:   dd "It is even",NL , NULL
not_even_msg:   dd "It is not even",NL , NULL

; push first
; arg 3 = ebp + 16
; arg 2 = ebp + 12
; arg 1 = ebp + 8
; last one 

; itoa
; atoi
; get_input
; printstr
; factorial
; strlen
; srand
; sum_array