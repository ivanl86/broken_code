; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>
%include "lib.inc"
section     .text

global      _start

_start:
    ; call    get_uint
    ; mov     [val], eax

    ; add     esp, 4

    ; push    eax
    ; call    print_uint
    ; add     esp, 4

    push    dword [buff_comma]
    call    printchar
    add     esp, 4

; break:
;     call    getchar
;     mov     ecx, eax

;     push    eax
;     call    printchar
;     add     esp, 4

;     call    print_nl
;     add     esp, 4

    ; push    array_sz
    ; push    int_array
    ; call    print_intarray
    ; add     esp, 8

    ;push    dword buff_sz
    ;push    buff
    ;call    get_input

    ; call    getchar
    ; cmp     al, 'g'


    ; push    buff
    ; call    atoi
; exit:  
    ; mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    ; mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    ; int     80h
    push    dword 1
    call    exit

section     .bss
buff_sz:    equ 150
buff:       resb buff_sz
val_sz:     equ 1
val:        resd val_sz

section     .data
int_array:  dd 89, 34, 56, 12, 90, 89
array_sz:   equ ($ - int_array) / 4

buff_comma:     db 44