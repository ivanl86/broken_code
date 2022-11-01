global sum

;------------------------------------------------------------------------------
sum:
;
; Description: sum first n counting numbers
; Receives: stack arg = n
; Returns:  eax = sum
; Requires: <requirements>
; Notes:    <notes>
; Algo:     <algorithm>
;-------------------------------------------------------------------------------

    push    ebp         ; preserve caller's base pointer
    mov     ebp, esp    ; set base of frame

    mov     eax, [ebp + 8]  ; move n to eax
    cmp     eax, 1          ; if n <= 1: base case
    jle     .base           ; jummp to base

    dec     eax             ; dec n for recrusive call
    push    eax             ; push the arg for rec call
    call    sum             ;
    add     eax, [ebp + 8]  ; add n to the val returned

    .base:                  ; exit point for base case
    leave
    ret
    
; End  <procedure_label> -------------------------------------------------------
