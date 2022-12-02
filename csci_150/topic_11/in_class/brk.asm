; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>

%include "../../lib.inc"


section     .text

global      _start

_start:
    ; get mem address of the top of heap
    mov     eax, 0x2d   ; sys_brk
    xor     ebx, ebx    ; EBX = 0
    int     0x80        ; perform sys_call
    ; return EAX = mem address of the top of heap

    push    eax         ; holds the top of heap mem address
    call    print_uint
    call    print_nl

    ; allocate 4096 bytes
    mov     eax, 0x2d   ; sys_brk
    pop     ebx         ; EBX = ? EAX = the top of heap
    add     ebx, 4096   ; allocate 4096 bytes on the heap
    int     0x80        ; perform sys_call

    push    ebx         ; holds the top of heap mem address + 4096
    call    print_uint
    call    print_nl

    ; deallocate 4096 bytes
    mov     eax, 0x2d   ; sys_brk
    pop     ebx         ; EBX = the top of heap
    sub     ebx, 4096   ; ? deallocate 4096 bytes
    int     0x80        ; perform sys_call

    ; get the mem address of the top of heap
    mov     eax, 0x2d   ; sys_brk
    xor     ebx, ebx    ; EBX = 0
    int     0x80        ; perform sys_call

    push    eax         ; holds the top of heap mem address
    call    print_uint
    call    print_nl
    
    push    dword 0
    call    exit

section     .bss

section     .data

; lea esi, [ebp - 4]