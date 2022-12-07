global  calloc
global  malloc

;------------------------------------------------------------------------------
calloc:
;
; Description: return top mem address of heap
; Receives: nothing
; Returns:  EAX = top mem address of heap
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebx

    mov     eax, 0x2d   ; sys_brk
    xor     ebx, ebx    ; EBX = 0
    int     0x80        ; perform sys_call

    pop     ebx
    ret
    
; End  <procedure_label> -------------------------------------------------------

;------------------------------------------------------------------------------
malloc:
;
; Description: allocate memory on heap
; Receives: arg1 = mem size to reserve
; Returns:  <return list>
; Requires: <requirements>
; Notes:    <notes>
; Algo:     <algorithm>
;-------------------------------------------------------------------------------

    push    ebp
    mov     ebp, esp
    push    ebx
    
    call    calloc
    mov     ebx, eax
    mov     eax, 0x2d
    add     ebx, [ebp + 8]
    int     0x80

    pop     ebx
    leave
    ret
    
; End  <procedure_label> -------------------------------------------------------

;------------------------------------------------------------------------------
free:
;
; Description:
; Receives: <argument list>
; Returns:  <return list>
; Requires: <requirements>
; Notes:    <notes>
; Algo:     <algorithm>
;-------------------------------------------------------------------------------

    
    
    ret
    
; End  <procedure_label> -------------------------------------------------------
