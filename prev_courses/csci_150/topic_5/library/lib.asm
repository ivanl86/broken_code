global sum_array

; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>
;----------------------------------------------------------------------
sum_array:
;
; Descriptions: Sums the integer (dwords) elements of an array
; Receives: EAX = address of the array
;           EBX = number of elements
; Returns:  EAX = sum of the elements of the array
; Requires: nothing
; Notes:    none
; Algo:     none
;----------------------------------------------------------------------

    push    esi

    mov     esi, eax        ; mov address of array into esi
    mov     ecx, ebx        ; mov count of array elements into ecx
    xor     eax, eax        ; set eax = 0

    .loop:
    add     eax, [esi]
    add     esi, 4
    loop    .loop

    pop     esi
    ret

; End sum_array--------------------------------------------------------