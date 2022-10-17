; who: Ivan Leung ileung2
; what: rearrange an array
; why: In class exercise
; when: 9/14/22



section     .text

global      _start

_start:
    mov     ax, [array]        ; ax = 1
    xchg    ax, [array + 2]    ; ax = 2, array[1] = 1
    xchg    ax, [array + 4]    ; ax = 3, array[2] = 2
    mov     [array], ax        ; array[0] = 3

exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

section     .bss

section     .data

array:      dw 1,2,3