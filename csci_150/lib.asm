global sum_array
global printstr
global get_input
global strlen
global atoi
global itoa
global swap
global swap_xor
global srand
global rand
global current_time

global NL
global NULL
global TRUE
global FALSE
global RAND_MAX

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
; Description: Calculates the size of a null-termainated string
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
    
; End strlen -------------------------------------------------------------------

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
    push    eax             ; preserve string address

    call strlen             ; eax has the size of the string
    mov     edx, eax        ; edx = size of the string
    pop     ecx             ; restore the address into ecx

    mov     eax, 4          ; mov 4 to eax indicates write operation
    mov     ebx, 1          ; mov 1 to ebx indicates stdout
    int     0x80            ; performs syscall

    pop     ebx             ; restore caller's base pointer
    ret

; End sum_array------------------------------------------------------------------

;------------------------------------------------------------------------------
print_array:
;
; Description:
; Receives: EAX = address of the array
;           EBX = the number of element in the array
; Returns:  none
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    .while:

    
    ret
    
; End  <procedure_label> -------------------------------------------------------

;--------------------------------------------------------------------------------
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
    cmp     byte [esi + eax - 1], NL
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
; Description: Takes a value and return 1 if even or false otherwise
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
atoi:
;
; Description: convert ascii representation of a unsigned integer to an unsigned integer
; Receives: EDX = address of a NULL terminated string
; Returns:  EAX = converted unsigned integer value
; Requires: nothing
; Notes:    none
; Algo:     use horner's method
;-------------------------------------------------------------------------------

    push    esi

    mov     esi, eax
    mov     eax, 0
    mov     ecx, 10
    movzx   edx, byte [esi]

    .while:
    test    edx, edx
    jz      .wend
    mul     ecx
    movzx   edx, byte [esi]
    add     eax, edx
    sub     eax, 48
    inc     esi
    movzx   edx, byte [esi]
    jmp     .while
    .wend:

    pop     esi

    ret
    
; End atoi ---------------------------------------------------------------------

;------------------------------------------------------------------------------
itoa:
;
; Description: converts an unsigned integer to a null-terminated string representation
; Receives: eax = unsigned integer value
;           ebx = address of the string buffer
;           ecx = size of buffer
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp             ; preserve caller's base pointer
    push    edi

    mov     ebp, esp        ; set base of frame

    sub     esp, 8          ; allocate counter var
    mov     dword [ebp - 4], 0 ; initialzing counter
    mov     dword [ebp - 8], 10; divisor

    mov     edi, ebx

    ; sub     esp, 8          ; added two vars
    ;                         ; var1 ebp - 8
    ;                         ; var2 ebp - 4
    ; mov     [ebp - 4], 0
    ; push    dword 0         ; declare a space for a local variable

    ; loop over eax (until 0)
    ; div by  10
    ; use remainder + 48 as the character
    .while:
    test    eax, eax
    jz      .wend
    mov     edx, 0
    div     dword [ebp - 8] ; div eax by 10

    add     edx, 48         ; add 48 to the remainder to convert number to char
    push    edx             ; push edx into stack
    inc     dword [ebp - 4] ; inc the counter
    jmp     .while
    .wend:

    mov     ecx, [ebp - 4]  ; mov counter into ecx
    .loop:
    pop     eax             ; pop the char into eax
    mov     [edi], al       ; mov al into edi
    inc     edi             ; inc edi to mov to next char
    loop    .loop

    mov     byte [edi], NULL; null terminate the string

    mov     esp, ebp
    pop     edi
    pop     ebp
    
    ret
    
; End  <procedure_label> -------------------------------------------------------

;-------------------------------------------------------------------------------
swap:
;
; Description: Swap the 32bit values located at the addresses passed in as args
; Receives: EAX: address of first value (val1)
;           EBX: address of second value (val2)
; Returns:  <return list>
; Requires: <requirements>
; Notes:    The registers hold the addresses of two values to be swapped, not the values themselves
; Algo:     <algorithm>
;-------------------------------------------------------------------------------

    push    ebp
    mov     ebp, esp
    sub     esp, 4

    lea     esi, [ebp - 4]  ; move address of local var into esi
    mov     esi, [eax]      ; move val1 into esi
    xchg    esi, [ebx]      ; exchange val1 in esi with val2 in ebx
    mov     [eax], esi      ; move val2 in esi into eax
    
    leave
    ret
    
; End  <procedure_label> -------------------------------------------------------

;-------------------------------------------------------------------------------
swap_xor:
;
; Description: Swap the 32bit values located at the addresses passed in as args
; Receives: EAX: address of first value (val1)
;           EBX: address of second value (val2)
; Returns:  <return list>
; Requires: <requirements>
; Notes:    The registers hold the addresses of two values to be swapped, not the values themselves
; Algo:     <algorithm>
;-------------------------------------------------------------------------------

    mov     ecx, [eax]  ; mov val1 into ecx
    mov     edx, [ebx]  ; mov val2 into edx

    xor     ecx, [ebx]  ; a ^ b
    xor     [ebx], ecx  ; b ^ a
    xor     ecx, [ebx]  ; a ^ b

    xor     edx, [eax]  ; b ^ a
    xor     [eax], edx  ; a ^ b
    xor     edx, [eax]  ; b ^ a

    ret
    
; End  <procedure_label> -------------------------------------------------------

;-------------------------------------------------------------------------------
srand:
;
; Description: Seeds the value used by rand
; Receives: EAX = seed value
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    mov     [next], eax

    ret
    
; End srand --------------------------------------------------------------------

;-------------------------------------------------------------------------------
rand:
;
; Description: generates a random unsigned integer value
; Receives: nothing
; Returns:  EAX = a random unsigned integer value
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------
  
    ; mov     eax, [next]     ; mov next to eax
    ; mov     ebx, n_0        ; mov n_0 to ebx
    ; mul     ebx             ; mul eax by ebx (eax * 1103515245)
    ; add     eax, n_1        ; add n_1 to eax (eax + 12345)

    ; mov     ebx, n_2        ; mov n_2 to ebx
    ; xor     edx, edx        ; clear edx
    ; div     ebx             ; div eax by ebx (eax / 65536 )
    ; xor     edx, edx        ; clear edx
    ; mov     ebx, n_3        ; mov n_3 to ebx
    ; div     ebx             ; div eax by ebx (eax / 32768)
    ; movzx   eax, dx         ; mov dx (remainder) to eax

    mov     eax, [next]     ; eax = next
    mov     ecx, RANDC1     ; ecx = RANDC1
    mul     ecx             ; edx:eax = eax * ecx
    add     eax, RANDC2     ; eax = eax + RANDC2
    mov     [next], eax     ; update next
    ; next = next * 1103515245 + 12345

    xor     edx, edx        ; clear edx for div
    mov     ecx, RANDC3     ; ecx = RANDC3
    div     ecx             ; edx:eax = eax / ecx

    xor     edx, edx        ; clear edx for div
    mov     ecx, RANDC4     ; ecx = RANDC4
    div     ecx             ; edx:eax = eax / ecx
    mov     eax, edx        ; move remainder from edx into eax for return
    ; return next / 65536 % 32768
    ret
    
; End rand ---------------------------------------------------------------------

;-------------------------------------------------------------------------------
current_time:
;
; Description: 
; Receives: <argument list>
; Returns:  <return list>
; Requires: <requirements>
; Notes:    <notes>
; Algo:     <algorithm>
;-------------------------------------------------------------------------------

    push    ebx             ; preserve

    mov     eax, 13         ; syscall number for time
    mov     ebx, 0          ; time location = NULL
    int     0x80            ; 32 bit time vlaue returned in EAX

    pop     ebx             ; restore
    
    ret
    
; End current_time -------------------------------------------------------------

;-------------------------------------------------------------------------------
; constant
NL:         equ 0x0a        ; a newline character
NULL:       equ 0x00        ; a zero character
TRUE:       equ 0x01        ; true = 1
FALSE:      equ 0x00        ; false = 0
; End constant------------------------------------------------------------------

section     .bss

section     .data
    next:   dd 1
    n_0:    equ 1103515245
    n_1:    equ 12345
    n_2:    equ 65536
    n_3:    equ 32768

    RANDC1: equ 1103515245
    RANDC2: equ 12345
    RANDC3: equ 65536
    RANDC4: equ 32768
    RAND_MAX: equ RANDC4 - 1