global sum_array
global printstr
global get_input
global strlen
global srand
global rand
global atoi
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
; Description: Convert numbers in a string to integer value.
; Receives: EDX = the address of the string
; Returns:  EAX = the converted integer value
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    xor     eax, eax        ; clear eax
    xor     ebx, ebx        ; clear ebx
    xor     ecx, ecx        ; clear ecx
    mov     ebx, 10         ; set ebx to 10
    mov     esi, edx        ; mov address of string from edx to esi

    .convert:
    movzx   ecx, byte [esi] ; mov the nex char to ecx
    cmp     ecx, 48         ; 0 in ASCII = 48
    jl      .endConvert     ; end if it is less than 0
    cmp     ecx, 57         ; 9 in ASCII = 57
    jg      .endConvert     ; end if it is greater than 9
    mul     ebx             ; mul eax by 10
    sub     ecx, 48         ; sub 48 to convert the char to number 
    add     eax, ecx        ; add the number to eax
    inc     esi             ; go to the nex char
    loop    .convert
    .endConvert:

    ret
    
; End atoi ---------------------------------------------------------------------

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