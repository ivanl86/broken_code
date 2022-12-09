; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>

section     .text

global      _start

_start:
    extern  NL
    extern  printstr

    mov     eax, 9
    mov     ebx, 8

    cmp    eax, ebx

    jg      greater

    jl      less

    je      equal

exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

    greater:
    mov     eax, greaterMsg
    mov     ebx, greaterMsgSz

    call    printstr
    call    exit

    less:
    mov     eax, lessMsg
    mov     ebx, lessMsgSz

    call    printstr
    call    exit

    equal:
    mov     eax, equalMsg
    mov     ebx, equalMsgSz

    call    printstr
    call    exit

section     .bss

section     .data
    greaterMsg:     dd "EAX > EBX", NL
    greaterMsgSz:   equ $ - greaterMsg

    lessMsg:        dd "EAX < EBX", NL
    lessMsgSz:      equ $ - lessMsg

    equalMsg:       dd "EAX == EBX", NL
    equalMsgSz:     equ $ - equalMsg