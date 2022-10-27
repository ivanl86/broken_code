global swap

;------------------------------------------------------------------------------
swap:
;
; Description: Swap the 32bit values located at the addresses passed in as args
; Receives: EAX: address of first value (val1)
;           EBX: address of second value (val2)
; Returns:  none
; Requires: nothing
; Notes:    The registers hold the addresses of two values to be swapped, not the values themselves
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp             ; setup activation record
    mov     ebp, esp

    mov     ecx, [ebp + 8]  ; load ecx with address of val1
    mov     ecx, [ecx]      ; load ecx with the value
    mov     edx, [ebp + 12] ; load edx with address of val2

    xchg    ecx, [edx]      ; exchange val1 and val2

    mov     edx, [ebp + 8]  ; load ebx with address of val1
    mov     [edx], ecx      ; update val1 mem location

    mov     esp, ebp        ; deallocate local storage
    pop     ebp             ; restore caller base pointer

    ret
    
; End  swap -------------------------------------------------------