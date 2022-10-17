; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>

section     .text

global      _start
    extern  strlen
    extern  printstr

_start:
    ; mov     eax, string
    ; call    printstr

    mov     ecx, 32
    mov     eax, [val]
    mov     edi, binstr

    .loop:
    rol     eax, 1

    .if:
    jnc     .else
    mov     byte [edi], '1'
    jmp     .endif

    .else:
    mov     byte [edi], '0'
    .endif:

    inc     edi
    loop    .loop

    mov     byte [edi], 0x0a
    mov     byte [edi+1], 0x00

    mov     eax, binstr
    call    printstr
exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

section     .bss
    binstr:     resb 33

section     .data
    string:     db "It'll look something lilke this", 0x0a, 0x00
    val:        dd 1023