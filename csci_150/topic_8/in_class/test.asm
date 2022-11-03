; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>

%include "../../lib.inc"

section     .text

global      _start

_start:
    mov     eax, prompt
    call    printstr

    mov     eax, buff
    mov     ebx, buff_sz
    call    get_input

    ; mov     edx, buff 
    push    buff
    call    atoi
    add     esp, 4

    push    eax
    call    factorial
    add     esp, 4

    mov     ebx, buff
    mov     ecx, buff_sz
    call    itoa

    mov     eax, buff
    call    printstr

    call    print_nl


exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

section     .bss
buff_sz:    equ 100
buff:       resb buff_sz

section     .data
prompt:     db "Enter a value for n: ", 0
