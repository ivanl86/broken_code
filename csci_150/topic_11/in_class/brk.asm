; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>

%include "../../lib.inc"


section     .text

global      _start

_start:
    mov     eax, 0x2d
    xor     ebx, ebx
    int     0x80

    ; push    eax
    ; call    print_unit
    ; call    print_nl

    ; mov     eax, 0x2d
    ; pop     ebx
    ; add     ebx, 4096
    ; int     0x80

    ; push    ebx
    ; call    print_unit
    ; call    print_nl
    
    ; push    dword 0
    ; call    exit

exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

section     .bss

section     .data