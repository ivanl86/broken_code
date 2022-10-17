; who: Ivan Leung ileung2
; what: Sum 10 values from an array
; why: Topic 4 Exercise
; when: 9/21/2022

section     .text

global      _start

_start:
    mov     ecx, arraySize  ; set counter = arraySize
    mov     ebx, 0          ; initialize ebx = 0

    .loop:
    add     eax, [intArray + ebx] ; add intArray to eax
    add     ebx, 4          ; double word = 4, add 4 to intArray
    loop    .loop

    mov     [arraySum], eax ; store the sum in arraySum

exit:  
    mov     eax, 1          ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0          ; return 0 status on exit - 'No Errors'
    int     80h

section     .bss
    arraySum:   resd 1

section     .data
    intArray:   dd 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a
    arraySize:  equ ($ - intArray) / 4