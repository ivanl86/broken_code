; who: Ivan Leung ileung2
; what: Takes a user input as string and print it
; why:  by calling printstr procedure to print the string
; when: 10/4/2022

section     .text

global      _start

    extern      printstr

_start:
    get_user_input:
    mov         eax, prompt
    mov         ebx, promptSz

    call        printstr

    mov         eax, 3
    mov         ebx, 0
    mov         ecx, inputBf
    mov         edx, bufferSz
    int         0x80

    print_str:
    mov         eax, inputBf
    mov         ebx, bufferSz

    call        printstr


exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

section     .bss
    bufferSz:       equ 255
    inputBf:        resd bufferSz

section     .data
    prompt:         dd "Enter a string: "
    promptSz:       equ $ - prompt