; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>

section     .text

global      _start
    extern  NL
    extern  printstr

_start:
    mov     al, 0b00000100
    add     al, 0b00000010
    
    jp      evenParity

    call    oddParity

exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

    evenParity:
    mov     eax, evenMsg
    mov     ebx, evenMsgSz

    call    printstr
    call    exit

    oddParity:
    mov     eax, oddMsg
    mov     ebx, evenMsgSz

    call    printstr
    call    exit

section     .bss

section     .data
    evenMsg:        dd "AL has even parity", NL
    evenMsgSz:      equ $ - evenMsg

    oddMsg:         dd "AL has odd parity", NL
    oddMsgSz:       equ $ - oddMsg