; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>

section     .text
;------------------------------------------------------------------------------
array_swap:
;
; Description:
; Receives: <argument list>
; Returns:  <return list>
; Requires: <requirements>
; Notes:    <notes>
; Algo:     <algorithm>
;-------------------------------------------------------------------------------

    push    ebp
    mov     ebp, esp

    push    ebx
    push    esi
    push    edi

    mov     esi, array                 ; esi = front iterator
    lea     edi, [array + arraySz - 4] ; edi = back iterator
    ; mov     edi, array + arraySz - 4
    ; lea calculates the last address of the array

    .while:

    cmp     esi, edi    ; check if esi is less than edi
    jae     .wend       ; if false, exit loop

    ; mov     eax, esi    ; move front to eax
    ; mov     ebx, edi    ; move back to ebx
    push    edi         ; push second param
    push    esi         ; push first param
    call    swap        ; swap values in those iterators
    add     esp, 8      ; deallocate two param

    add     esi, 4      ; increment front iterator
    sub     edi, 4      ; decrement back iterator
    jmp     .while      ; next set of iterators

    .wend:

    pop     edi
    pop     esi
    pop     ebx

    mov     esp, ebp
    pop     ebp

    ret
    
; End  array_swap -------------------------------------------------------


global      _start

    extern  swap

_start:
    call array_swap


exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

section     .bss

section     .data
    array: dd 1,2,3,4,5,6,7,8,9
    arraySz: equ $ - array