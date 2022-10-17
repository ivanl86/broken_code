global sum_array
global printstr
global get_input
global strlen

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
strlen:
;
; Calculates the size of a null-termainated string
; Receives: EAX = address of the string
; Returns:  EAX = the size of the string
; Requires: The string must be null-terminated
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    esi             ; perserve esi
    mov     esi, eax        ; set esi to the address of the string
    xor     eax, eax        ; eax will be the counter of none-null chars

    .while:
    cmp     byte [esi], NULL
    je      .wend
    inc     eax
    inc     esi
    jmp     .while

    .wend:

    pop     esi
    ret
    
; End  <procedure_label> -------------------------------------------------------

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

    push    ebx             ; preserve caller's base pointer

    mov     ecx, eax        ; mov the address of the string from eax to ebx
    mov     edx, ebx        ; mov the size of the string from ebx to ecx
    mov     eax, 4          ; mov 4 to eax indicates write operation
    mov     ebx, 1          ; mov 1 to ebx indicates stdout
    int     0x80            ; performs syscall

    pop     ebx             ; restore caller's base pointer
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
; Notes:    remove newline char if it exists
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebx             ; preserve caller's base pointer
    push    esi             ; preserve esi

    mov     esi, eax        ;

    mov     ecx, eax        ; mov the address of the input buffer from eax to ebx
    mov     edx, ebx        ; mov the size of the input buffer from ebx to ecx
    mov     eax, 3          ; mov 4 to eax indicates write operation
    mov     ebx, 0          ; mov 1 to ebx indicates stdout
    int     0x80            ; performs syscall

    ; esi holds the address of the buffer
    cmp    byte [esi + eax - 1], NL
    jnz     .endif

    .if:
    mov     byte [esi + eax - 1], NULL
    dec     eax
    .endif:

    pop     esi
    pop     ebx             ; restore caller's base pointer
    ret                     ; return the number of characters enetered

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
    ret                     ; return EAX
    
; End  is_even -----------------------------------------------------------------


;-------------------------------------------------------------------------------
; constant
NL:         equ 0x0a        ; a newline character
NULL:       equ 0x00        ; a zero character
TRUE:       equ 0x01        ; true = 1
FALSE:      equ 0x00        ; false = 0
; End constant------------------------------------------------------------------