; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>

section     .text

global      _start

_start:
    cld
    mov     ecx, (array_len - 1) ; ECX = number of element in array
    lea     esi, [array + 4]     ; ESI = second element in array
    mov     edi, array           ; EDI = first element in array
    rep     movsd                ; mov ESI to EDI until ECX = 0

exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

section     .bss

section     .data
array:      dd 1,2,3,4,5,6,7,8,9,10
array_len:  equ ($ - array) /4