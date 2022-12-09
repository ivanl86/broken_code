; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>

section     .text

global      _start
    extern      NL
    extern      printstr

_start:

    mov     eax, 1
    add     eax, -5

    js      negative

    jns     positive



exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

    negative:
    mov         eax, negativeMsg
    mov         ebx, negativeMsgSz

    call        printstr
    call        exit

    positive:
    mov         eax, positiveMsg
    mov         ebx, positiveMsgSz

    call        printstr
    call        exit

section     .bss

section     .data
    positiveMsg:        dd "The value in EAX is not negative", NL
    positiveMsgSz:      equ $ - positiveMsg

    negativeMsg:        dd "The value in EAX is negative", NL
    negativeMsgSz:      equ $ - negativeMsg