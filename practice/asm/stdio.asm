; uint io
global  getuint
global  putuint

; sint io
global  getsint
global  putsint

; char io
global  getchar
global  putchar
global  putcomma
global  putnl
global  putspace

; str io
global  getstr
global  putstr

; file io
global  fread
global  fwrite

; file access
global  fclose
global  fcreat
global  fopen


; uint io
; 
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
getuint:
;
; Description: Get unsigned integer from user input
; Receives: nothing
; Returns:  EAX = unsigned integer
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    BUFSZ
    push    BUFF
    call    getstr  ; BUFF = user input

    push    BUFF
    call    atoi    ; convert string to unsigned integer
    add     esp, 12
    ; EAX = unsigned integer

    ret

; End  getuint -------------------------------------------------------

;--------------------------------------------------------------------------------
putuint:
;
; Description: Print unsigned integer
; Receives: arg1 = unsigned integer
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp     ; setup frame
    mov     ebp, esp

    push    BUFF
    push    dword [ebp + 8]
    call    itoa    ; convert unsigned integer to string
    
    push    BUFF
    call    putstr  ; print string
    add     esp, 12

    leave           ; tear down frame
    ret
    
; End  putuint -------------------------------------------------------

; sint io
; 
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
getsint:
;
; Description: Get signed integer from user input
; Receives: nothing
; Returns:  EAX = signed integer
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp     ; setup frame
    mov     ebp, esp
    push    esi     ; preserve ESI

    push    BUFSZ
    push    BUFF
    call    getstr

    mov     esi, BUFF
    cmp     byte [esi], NEG_SIGN
    jne     .else

    ; if negative
    ; remove negative sign
    ; call atoi to convert from string to integer
    ; negate the ineteger
    ; return in EAX

    .if:            ; if negative
    inc     esi     ; inc ESI to remove negative sign
    push    esi
    call    atoi    ; convert from string to integer
    neg     eax     ; negate integer
    jmp     .endif
    .else:          ; if positive
    push    BUFF
    call    atoi    ; convert from string to integer
    .endif:         ; end if
    add     esp, 4
    ; EAX = signed integer

    pop     esi     ; restore ESI
    leave           ; tear down frame
    ret
    
; End  getsint -------------------------------------------------------

;-------------------------------------------------------------------------------
putsint:
;
; Description: Print signed integer
; Receives: arg1 = signed integer
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp     ; setup frame
    mov     ebp, esp
    push    esi     ; preserve ESI

    mov     esi, BUFF
    cmp     dword [ebp + 8], 0  ; check if positive
    jge     .else               ; jump to .else if positive

    ; if negative
    ; add negative sign to string buffer
    ; negate integer
    ; convert from integer to string
    ; append integer string to the end of sign string buffer

    .if:            ; if negative
    mov     byte [esi], NEG_SIGN    ; put negative sign into BUFF
    inc     esi                     ; inc ESI to next char
    neg     dword [ebp + 8]         ; negate signed integer
    .else:          ; if positive
    push    esi                     ; ESI = BUFF
    push    dword [ebp + 8]         ; arg1 = signed integer
    call    itoa                    ; convert from integer to string
    push    BUFF            ; BUFF = signed integer
    call    putstr          ; print string
    .endif:         ; end if
    add     esp, 12

    pop     esi     ; restore ESI
    leave           ; tear down frame
    ret

; End  putsint -------------------------------------------------------
; 
; End  sint io

; char io
; 
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
getchar:
;
; Description: Get single character from user input
; Receives: nothing
; Returns:  EAX = single character
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp     ; setup frame
    mov     ebp, esp
    
    push    dword 2 ; buffer size = 2
    push    BUFF    ; BUFF = single character
    call    getstr  ; get single character from user input
    add     esp, 8

    movzx   eax, byte [BUFF]; EAX = char

    leave           ; tear down frame
    ret
    
; End  getchar -------------------------------------------------------

;-------------------------------------------------------------------------------
putchar:
;
; Description: Print single character
; Receives: arg1 = single character
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp     ; setup frame
    mov     ebp, esp

    mov     eax, [ebp + 8]  ; EAX = arg1
    mov     [BUFF], al      ; BUFF = AL
    mov     byte [BUFF + 1], NULL   ; BUFF + 1 = NULL

    push    BUFF    ; BUFF = char
    call    putstr  ; print char
    add     esp, 4

    leave           ; tear down frame
    ret
    
; End  putchar -------------------------------------------------------

;-------------------------------------------------------------------------------
putcomma:
;
; Description: Print comma character
; Receives: nothing
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    comma_str
    call    putstr
    add     esp, 4

    ret
    
; End  putcomma -------------------------------------------------------

;-------------------------------------------------------------------------------
putnl:
;
; Description: Print new line character
; Receives: nothing
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    nl_str
    call    putstr
    add     esp, 4

    ret

; End  putnl -------------------------------------------------------

;-------------------------------------------------------------------------------

putspace:
;
; Description: Print whitespace character
; Receives: nothing
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    space_str
    call    putstr
    add     esp, 4

    ret
    
; End  putspace -------------------------------------------------------

; str io
; 
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
getstr:
;
; Description: Get string input from user
; Receives: arg1 = string buffer
;           arg2 = buffer size
; Returns:  nothing
; Requires: nothing
; Notes:    Remove nl char if exits and null terminate
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp     ; setup frame
    mov     ebp, esp
    push    ebx     ; preserve EBX

    mov     eax, SYS_READ   ; EAX = 3
    mov     ebx, STD_CIN    ; EBX = 0
    mov     ecx, [ebp + 8]  ; ECX = string buffer
    mov     edx, [ebp + 12] ; EDX = buffer size
    int     SYS_CALL        ; sys_call = 0x80

    ; EAX = byte read from input
    dec     eax             ; dec EAX to remove nl char
    mov     ebx, [ebp + 8]  ; EBX = string buffer
    add     ebx, eax        ; EBX = last char in string
    mov     byte [ebx], NULL; null terminate string
    
    pop     ebx     ; restore EBX
    leave           ; tear down frame
    ret
    
; End  getstr -------------------------------------------------------

;-------------------------------------------------------------------------------
putstr:
;
; Description: Print string
; Receives: arg1 = string buffer
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp     ; setup frame
    mov     ebp, esp
    push    ebx     ; preserve EBX

    push    dword [ebp + 8] ; push arg1 
    call    strlen          ; call strlen to find size of string
    add     esp, 4

    mov     edx, eax        ; EDX = size of string
    mov     ecx, [ebp + 8]  ; ECX = string buffer
    mov     ebx, STD_COUT   ; EBX = 1
    mov     eax, SYS_WRITE  ; EAX = 4
    int     SYS_CALL        ; perform SYS_CALL = 0x80

    pop     ebx     ; restore EBX
    leave           ; tear down frame
    ret
    
; End  putstr -------------------------------------------------------
; 
; End str io ------------------------------------------------------------------

; file io
; 
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
fread:
;
; Description:Read from file
; Receives: arg1 = file descriptor
;           arg2 = string buffer
;           arg3 = buffer size
; Returns:  EAX = number of bytes have read
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp     ; setup frame
    mov     ebp, esp
    push    ebx     ; preserve EBX
    
    mov     eax, SYS_READ   ; EAX = 3
    mov     ebx, [ebp + 8]  ; EBX = arg1
    mov     ecx, [ebp + 12] ; ECX = arg2
    mov     edx, [ebp + 16] ; EDX = arg3
    int     SYS_CALL        ; perform SYSCALL = 0x80
    ; EAX = number of bytes have read

    pop     ebx     ; restore EBX
    leave           ; tear down frame
    ret
    
; End  fread -------------------------------------------------------

;-------------------------------------------------------------------------------
fwrite:
;
; Description: Write to file
; Receives: arg1 = file descriptor
;           arg2 = string buffer
;           arg3 = buffer size
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp     ; setup frame
    mov     ebp, esp
    push    ebx     ; preserve EBX

    mov     eax, SYS_WRITE  ; EAX = 4
    mov     ebx, [ebp + 8]  ; EBX = arg1
    mov     ecx, [ebp + 12] ; ECX = arg2
    mov     edx, [ebp + 16] ; EDX = arg3
    int     SYS_CALL        ; perform SYS_CALL = 0x80

    pop     ebx     ; restore EBX
    leave           ; tear down frame
    ret

; End  fwrite -------------------------------------------------------

;-------------------------------------------------------------------------------
fclose:
;
; Description: Close file
; Receives: arg1 = file descriptor
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp     ; setup frame
    mov     ebp, esp
    push    ebx     ; preserve EBX

    mov     eax, SYS_CLOSE      ; EAX = 6
    mov     ebx,    [ebp + 8]   ; EBX = arg1
    int     SYS_CALL        ; perform SYS_CALL = 080

    pop     ebx     ; restore EBX
    leave           ; tear down frame
    ret

; End  fclose -------------------------------------------------------

;-------------------------------------------------------------------------------
fcreat:
;
; Description: Create file
; Receives: arg1 = file path
; Returns:  EAX = file descriptor
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp     ; setup frame
    mov     ebp, esp
    push    ebx     ; preserve EBX

    mov     eax, SYS_CREAT  ; EAX = 8
    mov     ebx, [ebp + 8]  ; EBX = arg1
    mov     ecx, ALL_PERM   ; EDX = ALL_PERM = 0o777
    int     SYS_CALL        ; perform SYS_CALL = 0x80
    ; EAX = file descriptor

    pop     ebx     ; restore EBX
    leave           ; tear down frame
    ret
    
; End  fcreate -------------------------------------------------------

;-------------------------------------------------------------------------------
fopen:
;
; Description: Open file
; Receives: arg1 = file path
;           arg2 = access mode { 0 = read, 1 = write, 2 = read and write }
; Returns:  EAX = file descriptor
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp     ; setup frame
    mov     ebp, esp
    push    ebx     ; preserve EBX

    mov     eax, SYS_OPEN   ; EAX = 5
    mov     ebx, [ebp + 8]  ; EBX = arg1
    mov     ecx, [ebp + 12] ; ECX = access mode
    mov     edx, ALL_PERM   ; EDX = ALL_PERM
    int     SYS_CALL        ; perform SYS_CALL = 0x80
    ; EAX = file descriptor

    pop     ebx     ; restore EBX
    leave           ; tear down frame
    ret
    
; End  fopen -------------------------------------------------------
; 
; End  file io

; helper procedures (private)
;------------------------------------------------------------------------------
atoi:
;
; Description: Convert null terminated string to unsigned integer
; Receives: arg1 = string buffer
; Returns:  EAX = unsigned integer
; Requires: String must be null terminated
; Notes:    Discard all whitespace until first non-whitespace char
; Algo:     Horner's method
;-------------------------------------------------------------------------------

    push    ebp     ; setup frame
    mov     ebp, esp
    push    esi     ; preserve ESI
    push    ebx     ; preserve EBX

    mov     esi, [ebp + 8]  ; ESI = arg1
    xor     eax, eax    ; EAX = 0
    mov     ecx, 10     ; ECX = 10

    ; discard all whitespace until first non-whitespace char
    .while1:
    movzx   ebx, byte [esi] ; EBX = char
    cmp     ebx, SPACE  ; check if = whitespace
    jne     .wend1      ; end if != whitespace
    inc     esi         ; ESI = next char
    jmp     .while1     ; loop
    .wend1:

    ; convert char to decimal until encounter a NULL or not in between 0 - 9
    .while2:
    test    ebx, ebx    ; check for NULL
    jz      .wend2      ; end if = NULL
    cmp     ebx, 48     ; check if < 0
    jl      .wend2      ; end if < 0
    cmp     ebx, 57     ; check if > 9
    jg      .wend2      ; end if > 9
    mul     ecx         ; EAX = EAX * 10
    sub     ebx, 48     ; convert from ascii to decimal
    add     eax, ebx    ; add decimal to EAX
    inc     esi         ; ESI = next char
    movzx   ebx, byte [esi] ; EBX = char
    jmp     .while2     ; loop
    .wend2:

    pop     ebx     ; restore EBX
    pop     esi     ; restore ESI
    leave           ; tear down frame
    ret
    
; End  atoi -------------------------------------------------------

;------------------------------------------------------------------------------
itoa:
;
; Description: Convert unsigned integer to null terminated string
; Receives: arg1 = unsigned integer
;           arg2 = string buffer
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp     ; setup frame
    mov     ebp, esp
    push    edi     ; reserve EDI
    sub     esp, 4  ; declare local var

    mov     eax, [ebp + 8]  ; EAX = arg1
    mov     edi, [ebp + 12] ; EDI = arg2
    mov     dword [ebp - 4], 10 ; local var = 10
    xor     ecx, ecx        ; ECX = counter = 0

    ; div by 10
    ; add 48 to remainder
    ; 
    .while:
    test    eax, eax    ; check if = 0
    jz      .wend       ; end while if = 0
    xor     edx, edx    ; EDX = 0
    div     dword [ebp - 4] ; EAX = EAX / 10
    add     edx, 48     ; EDX = remainder + 48 convert from integer to char
    push    edx         ; preserve EDX
    inc     ecx         ; inc ECX
    jmp     .while
    .wend:

    cld             ; set forward
    .loop:
    pop     eax     ; restore char to EAX
    stosb           ; store al into EDI
    loop    .loop   ; loop

    mov     byte [edi], NULL; null terminate string

    pop     edi     ; restore EDI
    leave           ; tear down frame
    ret
    
; End  itoa -------------------------------------------------------

;------------------------------------------------------------------------------
strlen:
;
; Description: Calculates size of null-terminated string
; Receives: arg1 = string buffer
; Returns:  EAX = size of string
; Requires: String must be null-terminated
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp     ; setup frame
    mov     ebp, esp
    push    edi     ; preserve EDI

    mov     edi, [ebp + 8]  ; EDI = arg1
    mov     al, NULL    ; AL = NULL
    mov     ecx, 0xffffffff ; ECX = -1 

    cld                 ; set forward
    repne   scasb       ; repeat scan and inc EDI unitl NULL is found
    dec     edi         ; dec EDI
    mov     eax, edi    ; EAX = EDI = last char of string
    mov     edx, [ebp + 8]  ; EDX = arg1 = first char of string
    sub     eax, edx    ; EAX = EAX - EDX = size of string

    pop     edi     ; restore EDI
    leave           ; tear down frame
    ret
    
; End  strlen -------------------------------------------------------
; 
; End  helper procedures


section     .bss
; tmp input buffer
BUFSZ:      equ 255
BUFF:       resb BUFSZ

section     .data
; string constant
comma_str:  db COMMA, NULL
negsig_str: db NEG_SIGN, NULL
nl_str:     db NL, NULL
space_str:  db SPACE, NULL

; char constant
COMMA:      equ 0x2c
NEG_SIGN:   equ 0x2d
NL:         equ 0x0a
NULL:       equ 0x00
SPACE:      equ 0x20

; Access mode
RD_ONLY:    equ 0
WR_ONLY:    equ 1
RD_N_WR:    equ 2

; Permission
ALL_PERM:   equ 0o777


; System call code
STD_CIN:    equ 0
STD_COUT:   equ 1
SYS_CALL:   equ 0x80
SYS_CLOSE:  equ 6
SYS_CREAT:  equ 8
SYS_EXIT:   equ 1
SYS_ERR:    equ 2
SYS_OPEN:   equ 5
SYS_READ:   equ 3
SYS_TIME:   equ 13
SYS_WRITE:  equ 4