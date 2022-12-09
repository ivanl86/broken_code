; who: Ivan Leung ileung2
; what: Goodbye Cruel World program
; why: Demo coding
; when: 8/29/2022

section     .text

global      _start

_start:
    mov     eax, 4      ; this is a write operation
    mov     ebx, 1      ; use standard output (to terminal)
    mov     ecx, msg    ; address of the string
    mov     edx, len    ; length of the string
    int     0x80        ; perform system call
    

exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     0x80        ; perform syscall

; section     .bss

section     .data
    msg:    db "Goodbye Cruel World!"; db = data byte = 16 bits, string in double quote
            db 0x0a ; new line character
    len:    equ $ - msg