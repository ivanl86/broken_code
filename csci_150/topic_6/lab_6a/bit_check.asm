; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>

section     .text

global      _start
    extern  printstr
    extern  NL

_start:
    mov     bl, 0b00101000  ; bit 4, 5, 6 are set in BL

    and     bl, 0b00111000  ; use AND instruction on AL with BL to all other bits
    cmp     bl, 0b00111000  ; compare AL and BL

    je      bit_set         ; jump to bit_set if equal otherwise jump to bit_not_set

    call    bit_not_set

exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

    bit_set:
    mov     eax, setMsg
    mov     ebx, setMsgSz

    call    printstr
    call    exit

    bit_not_set:
    mov     eax, notSetMsg
    mov     ebx, notSetMsgSz

    call    printstr
    call    exit

section     .bss

section     .data
    setMsg:         dd "Bits 4, 5, 6 are set", NL
    setMsgSz:       equ $ - setMsg

    notSetMsg:      dd "Bits 4, 5, 6 are not set", NL
    notSetMsgSz:    equ $ - notSetMsg