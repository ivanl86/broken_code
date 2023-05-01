
; character conversion
global  tolower
global  toupper

; character validations
global  isalpha
global  isdigit
global  islower
global  isspace
global  isupper

; character conversion
; 
;-------------------------------------------------------------------------------
tolower:
;
; Description: Convert uppercase alphabet character to lowercase alphabet character
; Receives: arg1 = character
; Returns:  EAX = lowercase alphabet character
; Requires: nothing
; Notes:    It does nothing if not uppercase alphabet character
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp     ; setup frame
    mov     ebp, esp

    .if:
    mov     eax, [ebp + 8]
    cmp     eax, 'A'  ; check if less than 'A'
    jl      .endif              ; jump to .endif if less
    cmp     eax, 'Z'  ; check if greater than 'Z'
    jg      .endif              ; jump to .endif if greater
    add     eax, 32       ; convert to lowercase alphabet character
    .endif:

    leave           ; tear down frame
    ret
    
; End  tolower -------------------------------------------------------

;-------------------------------------------------------------------------------
toupper:
;
; Description: Convert lowercase alphabet character to uppercase alphabet character
; Receives: arg1 = character
; Returns:  EAX = uppercase alphabet character
; Requires: nothing
; Notes:    It does nothing if not lowercase alphabet character
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp     ; setup frame
    mov     ebp, esp

    .if:
    push    dword [ebp + 8]
    call    islower
    add     esp, 4
    test    eax, eax
    jz      .endif
    sub     byte [ebp + 8], 32
    .endif:
    mov     eax, [ebp + 8]

    ; .if:
    ; mov     eax, [ebp + 8]
    ; cmp     eax, 'a'  ; check if less than 'a'
    ; jl      .endif              ; jump to .endif if less
    ; cmp     eax, 'z'  ; check if greater than 'z'
    ; jg      .endif              ; jump to .endif if greater
    ; sub     eax, 32       ; convert to uppercase alphabet character
    ; .endif:

    leave           ; tear down frame
    ret
    
; End  toupper -------------------------------------------------------

; character validations
; 
;-------------------------------------------------------------------------------
isalpha:
;
; Description: Check if character is alphabetic
; Receives: arg1 = character
; Returns:  EAX = TRUE if alphabetic, FALSE otherwise
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp     ; setup frame
    mov     ebp, esp

    ; if arg1 >= 'a' and <= 'z'
    ; eax = true
    ; else if arg1 >= 'A' and <= 'Z'
    ; eax = true
    ; else
    ; eax = false

    .if:
    cmp     byte [ebp + 8], 'a'
    jl      .or
    cmp     byte [ebp + 8], 'z'
    jg      .or
    mov     eax, TRUE
    jmp     .endif
    .or:
    cmp     byte [ebp + 8], 'A'
    jl      .else
    cmp     byte [ebp + 8], 'Z'
    jg      .else
    mov     eax, TRUE
    jmp     .endif
    .else:
    mov     eax, FALSE
    .endif:

    leave           ; tear down frame
    ret
    
; End  isalpha -------------------------------------------------------

;-------------------------------------------------------------------------------
isdigit:
;
; Description: Check if character is decimal digit character
; Receives: arg1 = character
; Returns:  EAX = TRUE if numeric, FALSE otherwise
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp     ; setup frame
    mov     ebp, esp

    .if:
    cmp     byte [ebp + 8], '0'
    jl      .else
    cmp     byte [ebp + 8], '9'
    jg      .else
    mov     eax, TRUE
    jmp     .endif
    .else:
    mov     eax, FALSE
    .endif:

    leave           ; tear down frame
    ret

; End  isdigit -------------------------------------------------------

;-------------------------------------------------------------------------------
islower:
;
; Description: Check if character is lowercase alphabetic character
; Receives: arg1 = character
; Returns:  EAX = TRUE if lowercase, FALSE otherwise
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp     ; setup frame
    mov     ebp, esp

    .if:
    cmp     byte [ebp + 8], 'a'
    jl      .else
    cmp     byte [ebp + 8], 'z'
    jg      .else
    mov     eax, TRUE
    jmp     .endif
    .else:
    mov     eax, FALSE
    .endif:

    leave           ; tear down frame
    ret

; End  islower -------------------------------------------------------

;-------------------------------------------------------------------------------
isspace:
;
; Description: Check if character is whitespace
; Receives: arg1 = character
; Returns:  EAX = TRUE if whitespace character, FALSE otherwise
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp     ; setup frame
    mov     ebp, esp

    .if:
    cmp     byte [ebp + 8], SPACE
    jne     .else
    mov     eax, TRUE
    jmp     .endif
    .else:
    mov     eax, FALSE
    .endif:

    leave           ; tear down frame
    ret

; End  isspace -------------------------------------------------------

;-------------------------------------------------------------------------------
isupper:
;
; Description: Check if character is uppercase alphabetic character
; Receives: arg1 = character
; Returns:  EAX = TRUE if uppercase, FALSE otherwise
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp     ; setup frame
    mov     ebp, esp

    .if:
    cmp     byte [ebp + 8], 'A'
    jl      .else
    cmp     byte [ebp + 8], 'Z'
    jg      .else
    mov     eax, TRUE
    jmp     .endif
    .else:
    mov     eax, FALSE
    .endif:

    leave           ; tear down frame
    ret

; End  isupper -------------------------------------------------------



section     .data
; boolean constant
TRUE:       equ 1
FALSE:      equ 0