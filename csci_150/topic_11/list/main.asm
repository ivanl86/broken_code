%include "list.inc"
%include "../../lib.inc"

section     .text

global      _start

_start:
    call    calloc

    push    eax
    call    print_uint
    call    print_nl
    
    push    dword list_size
    call    malloc

    push    eax
    call    print_uint
    call    print_nl

    ; pop     ebx
    ; sub     ebx, 4
    ; mov     eax, 0x2d
    ; int     0x80

    ; call    calloc

    ; push    eax
    ; call    print_uint
    ; call    print_nl
    
    push    dword 0
    call    exit

section     .bss
    head:   resb list_size
section     .data

; STRUC list
;     .val:   resd 1
;     .next:  resd 1
; ENDSTRUC