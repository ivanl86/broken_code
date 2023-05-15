%include    "../stdio.inc"
%include    "../char.inc"
%include    "../stdlib.inc"

section     .text

global      _start

_start:
    push    dword 11
    push    dword (arraySz - 1)
    push    dword 0
    push    array
    call    bsearch
    add     esp, 12

    cmp     eax, -1
    je      notfound
    push    dword [array + (eax * 4)]
    call    putuint
    call    putnl
    add     esp, 8
    jmp     end

    notfound:
    push    string
    call    putstr
    call    putnl
    add     esp, 4

end:
    push    dword NO_ERROR
    call    exit


; exit:  
;     mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
;     mov     ebx, 0      ; return 0 status on exit - 'No Errors'
;     int     80h

section     .bss

section     .data
array:      dd 1, 2, 3, 4, 5, 6
arraySz:    equ ($ - array) / 4
string:     db "Item is not found!"