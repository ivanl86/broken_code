global sum_array
global printstr
global get_input
global NL
global NULL
global TRUE
global FALSE


;-------------------------------------------------------------------------------
; who: Ivan Leung ileung2
; what: Library
; why: Reusable procedures
; when: Fall 2022
;-------------------------------------------------------------------------------


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


;-------------------------------------------------------------------------------
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

    mov     ecx, eax        ; mov the address of the string from eax to ebx
    mov     edx, ebx        ; mov the size of the string from ebx to ecx
    mov     eax, 4          ; mov 4 to eax indicates write operation
    mov     ebx, 1          ; mov 1 to ebx indicates stdout
    int     0x80            ; performs syscall

    ret

; End sum_array------------------------------------------------------------------


;-------------------------------------------------------------------------------
get_input:
;
; Descriptions: Get an input from the user
; Receives: EAX = address of the input buffer
;           EBX = size of the input buffer
; Returns:  none
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    mov     ecx, eax        ; mov the address of the input buffer from eax to ebx
    mov     edx, ebx        ; mov the size of the input buffer from ebx to ecx
    mov     eax, 3          ; mov 4 to eax indicates write operation
    mov     ebx, 0          ; mov 1 to ebx indicates stdout
    int     0x80            ; performs syscall

    ret eax             ; return the number of characters enetered

; End get_input------------------------------------------------------------------


;-------------------------------------------------------------------------------
is_even:
;
; Takes a value and return 1 if even or false otherwise
; Receives: EAX = the value will be checked
; Returns:  EAX = TRUE or FALSE
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    and     eax, 1          ; use AND instruction on EAX with 1
    xor     eax, 1          ; use XOR instruction on EAX to clear other bits
    ; EAX = 1 if even
    ; EAX = 0 if odd
    ret     eax             ; return EAX
    
; End  is_even -----------------------------------------------------------------


;-------------------------------------------------------------------------------
; constant
NL:         equ 0x0a        ; a newline character
NULL:       equ 0x00        ; a zero character
TRUE:       equ 0x01        ; true = 1
FALSE:      equ 0x00        ; false = 0
; End constant------------------------------------------------------------------