; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>

section     .text

global      _start

_start:
    mov eax, array
    mov ebx, array + arraySz - 4

    .while:
    call swap
    add eax, 4
    sub ebx, 4
    cmp eax, ebx
    jl  .while

exit:
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

    swap:
    ; mov     ecx, [eax]
    ; mov     edx, [ebx]
    ; mov    [eax], edx
    ; mov    [ebx], ecx
    mov     ecx, [eax]  ; move val1
    xchg    ecx, [ebx]  ; exchange 
    mov     [eax], ecx  ; mov

    ret

section     .bss

section     .data
    array: dd 1,2,3,4,5,6,7,8,9
    arraySz: equ $ - array