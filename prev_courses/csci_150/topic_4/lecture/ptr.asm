; who: <your name and Mt SAC username goes here>
; what: Work with pointer
; why: <the name of the lab>
; when: 9/21/2022

section     .text

global      _start

_start:
    mov     dword [arrayptr], array ; move array address to arrayptr  
    mov     ecx, len
    mov     dword [sum], 0 ;
    
    .loop:
    mov     eax, [arrayptr]
    mov     eax, [eax]
    add     [sum], eax
    add     dword [arrayptr], 4 ; declare the size dword for arrayptr and add to it
    loop    .loop

    mov     eax, [sum]
    add     eax, [val]
    mov      [sum], eax

exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

section     .bss
    arrayptr:   resd 1
    sum:        resd 1

section     .data
    array:  dd 0x20, 0x40, 0x60
    val:    dd 0x80     ; val = $
    len:    equ ($ - array) / 4