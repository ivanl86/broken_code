; who: Ivan Leung ileung2
; what: demo loop instruction
; why: <the name of the lab>
; when: 9/19/2022

section     .text

global      _start

_start:
    mov     esi, srcarray   ; esi = source address
    mov     edi, dstarray   ; edi = destination address
    mov     ecx, srcsz      ; set counter for loop

    .loop:
    mov     eax, [esi]      ; move value at esi into eax
    mov     [edi], eax      ; move value in eax into edi
    add     esi, 4          ; increment points by 4 (size of the data)
    add     edi, 4          ; increment points by 4 (size of the data)
    loop    .loop           ; loop while ecx != 0


exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

section     .bss
    dstarray:   resd srcsz

section     .data
    srcarray:   dd 1,2,3,4,5,6,7,8,9,10
    srcsz:      equ ($ - srcarray) / 4