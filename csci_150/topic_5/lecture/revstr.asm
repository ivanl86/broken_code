; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>

section     .text

global      _start

_start:
    mov     eax, 4          ; write op
    mov     ebx, 1          ; stdout
    mov     ecx, prompt     ;
    mov     edx, promptSz   ;
    int     0x80

    mov     eax, 3          ; read op
    mov     ebx, 0          ; stdin
    mov     ecx, inBuffer   ;
    mov     edx, bufferSz   ;
    int     0x80

    ; eax holds number of characters entered including newline
    dec     eax             ; ignore the newline character
    mov     [qty], eax      ; 
    mov     ecx, [qty]      ;
    mov     esi, inBuffer   ;
    mov     eax, 0          ;

    .loop1:
    mov     al, [esi]       ;
    push    eax             ; push eax to the stack
    inc     esi             ; +1 to esi
    loop    .loop1

    mov     ecx, [qty]      ;
    mov     esi, inBuffer   ;

    .loop2:
    pop     eax             ;
    mov     [esi], al       ;
    inc     esi          ;
    loop    .loop2

    inc     dword [qty]           ;
    mov     eax, 4
    mov     ebx, 1
    mov     ecx, inBuffer
    mov     edx, [qty]
    int     0x80            ;

exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

section     .bss
    bufferSz:   equ 255
    inBuffer:   resd bufferSz
    qty:        resd 1

section     .data
    prompt      db "Enter a string: "
    promptSz    equ $ - prompt

    msg:        db "The reversed string is: "
    msgSz:      equ $ - msg

    nl:         db 0x0a