
; Dynamic memory management
global  free
global  malloc

; System
global  exit

; Searching and sorting
global  bsearch
global  qsort

; Pseudo-random generator
global  rand
global  srand
global  time

; Exit code constant
; 
global  NO_ERROR
global  WITH_ERROR


; Dynamic memory management
; 
;-------------------------------------------------------------------------------
free:
;
; Description: Deallocate memory on heap
; Receives: arg1 = memory address to deallocate
;           arg2 = memory size to deallocate
; Returns:  EAX = top of heap
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp     ; setup frame
    mov     ebp, esp
    push    ebx

    mov     eax, SYS_BRK    ; EAX = 0x2d
    mov     ebx, [ebp + 8]  ; EBX = arg1
    sub     ebx, [ebp + 12] ; EBX = EBX - arg2
    int     SYS_CALL        ; perform SYS_CALL = 0x80
    ; EAX = top of heap

    pop     ebx
    leave           ; tear down frame
    ret

; End  free -------------------------------------------------------

;-------------------------------------------------------------------------------
malloc:
;
; Description: Allocate memory on heap
; Receives: arg1 = memory size to allocate
; Returns:  EAX = allocated memory address
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp     ; setup frame
    mov     ebp, esp
    push    ebx     ; preserve EBX

    mov     eax, SYS_BRK    ; EAX = 0x2d
    xor     ebx, ebx        ; EBX = 0
    int     SYS_CALL        ; perform SYS_CALL = 0x80
    ; EAX = top heap

    push    eax             ; preserve EAX = allocated memory address

    mov     ebx, eax        ; EBX = EAX
    add     ebx, [ebp + 8]  ; EBX = EBX + arg1
    mov     eax, SYS_BRK    ; EAX = 0x2d
    int     SYS_CALL        ; perform SYS_CALL = 0x80
    pop     eax             ; restore EAX = allocated memory address

    pop     ebx     ; restore EBX
    leave           ; tear down frame
    ret

; End  malloc -------------------------------------------------------

; System
; 
;-------------------------------------------------------------------------------
exit:
;
; Description:
; Receives: nothing
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp
    mov     ebp, esp

    mov     eax, SYS_EXIT
    mov     ebx, [ebp + 8]
    int     SYS_CALL

; End  exit -------------------------------------------------------

; Searching and sorting
; 
;-------------------------------------------------------------------------------
bsearch:
;
; Description: Binary search in array
; Receives: arg1 = dword array
;           arg2 = start element
;           arg3 = end element
;           arg4 = search term
; Returns:  EAX = subscript of match term or -1 if not found
; Requires: Array must be sorted
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp     ; setup frame
    mov     ebp, esp

    push    esi
    push    ebx

    mov     esi, [ebp + 8]  ; ESI = dword array

    mov     ebx, [ebp + 12]
    mov     ecx, [ebp + 16]
    cmp     ebx, ecx
    ja      .notfound

    ; mid = (start + end) / 2
    mov     eax, [ebp + 12] ; EAX = start
    add     eax, [ebp + 16] ; EAX = start + end
    xor     edx, edx        ; EDX = 0
    mov     ebx, 2          ; EBX = 2
    div     ebx             ; EAX = (start + end) / 2
    mov     edx, [ebp + 20] ; EDX = search term
    cmp     edx, [esi + (eax * 4)]  ; ? search term == array[mid]
    je      .end            ; if equal, jump to .end
    ja      .greater        ; else if greater
    ; else if less
    dec     eax             ; EAX = mid - 1
    mov     ebx, [ebp + 12] ; EBX = start
    mov     ecx, eax        ; ECX = end
    jmp     .continue
    .greater:
    inc     eax             ; EAX = mid + 1
    mov     ebx, eax        ; EBX = start
    mov     ecx, [ebp + 16] ; ECX = end
    .continue:
    push    dword [ebp + 20]
    push    ecx             ; arg3 = end
    push    ebx             ; arg2 = start
    push    esi             ; arg1 = array
    call    bsearch
    jmp     .end
    .notfound:
    mov     eax, -1
    .end:

    pop     ebx
    pop     esi

    leave           ; tear down frame
    ret

; End  bsearch -------------------------------------------------------

;-------------------------------------------------------------------------------
qsort:
;
; Description:
; Receives: nothing
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp     ; setup frame
    mov     ebp, esp

    leave           ; tear down frame
    ret

; End  qsort -------------------------------------------------------

; Pseudo-random generator
; 
;-------------------------------------------------------------------------------
rand:
;
; Description: Generate random unsigned integer
; Receives: nothing
; Returns:  EAX = random unsigned integer
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp     ; setup frame
    mov     ebp, esp

    ; next = next * RANDC1 + RANDC2
    mov     eax, [next]
    mov     ecx, RANDC1
    mul     ecx
    add     eax, RANDC2

    ; return next / RANDC3 % RANDC4
    mov     ecx, RANDC3
    xor     edx, edx
    div     ecx
    xor     edx, RANDC4
    div     ecx
    mov     eax, edx

    leave           ; tear down frame
    ret

; End  rand -------------------------------------------------------

;-------------------------------------------------------------------------------
srand:
;
; Description: Seeds pseudo-random generator
; Receives: arg1 = seed
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp     ; setup frame
    mov     ebp, esp

    mov     eax, [ebp + 8]  ; EAX = arg1
    mov     [next], eax     ; next = EAX

    leave           ; tear down frame
    ret

; End  srand -------------------------------------------------------

;-------------------------------------------------------------------------------
time:
;
; Description: Get current time
; Receives: nothing
; Returns:  EAX = 32 bit time value
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebx

    mov     eax, 13
    mov     ebx, 0
    int     SYS_CALL

    pop     ebx
    ret

; End  time -------------------------------------------------------

section     .data
; 
next:       dd 1
; Pseudo-random generator constant
RANDC1:     equ 1103515245
RANDC2:     equ 12345
RANDC3:     equ 65536
RANDC4:     equ 32768
RAND_MAX:   equ (RANDC4 - 1)

; System call code
SYS_BRK:    equ 0x2d
SYS_CALL:   equ 0x80
SYS_EXIT:   equ 1
NO_ERROR:   equ 0
WITH_ERROR: equ 1