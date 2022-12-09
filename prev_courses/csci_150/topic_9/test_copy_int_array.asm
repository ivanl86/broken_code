; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>

section     .text
%include    "../lib.inc"

global      _start

_start:
    push    dword src_array_sz
    push    dst_array
    push    src_array
    call    copy_int_array
    add     esp, 12
    mov     eax, dst_array
    mov     ebx, src_array_sz

exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

section     .bss
dst_array:   resd src_array_sz

section     .data
src_array:      dd 1,1,2,3,4,5,6,7,8,9,10
src_array_sz:   equ ($ - src_array) / 4