global sum_array
global printstr

; who: Ivan Leung ileung2
; what: Library
; why: Reusable procedures
; when: Fall 2022
;-------------------------------------------------------------------------------
sum_array:
;
; Descriptions: Sums the integer (dwords) elements of an array
; Receives: EAX = address of the array
;           EBX = number of elements
; Returns:  EAX = sum of the elements of the array
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

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

; End sum_array-----------------------------------------------------------------
printstr:
;
; Descriptions: Print a string
; Receives: EAX = address of the string
;           EBX = size of the string
; Returns:  none
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    mov ecx, eax        ; mov the address of the string from eax to ebx
    mov edx, ebx        ; mov the size of the string from ebx to ecx
    mov eax, 4          ; mov 4 to eax indicates write operation
    mov ebx, 1          ; mov 1 to ebx indicates stdout
    int 0x80            ; performs syscall

    ret

; End sum_array------------------------------------------------------------------
