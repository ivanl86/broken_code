; who: <your name and Mt SAC username goes here>
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.

section     .text

global      _start

_start:
    call get_user_input
    call string_reverse
    call print_string

exit:  
    mov     ebx, 0          ; return 0 status on exit - 'No Errors'
    mov     eax, 1          ; invoke SYS_EXIT (kernel opcode 1)
    int     80h             ; syscall

get_user_input:             ; use 4 and 1 for output
    mov     eax, 4
    mov     ebx, 1
    mov     ecx, prompt     ; mov label prompt into ecx
    mov     edx, promptSz   ; mov the size of prompt into edx
    int     0x80
                            ; use 3 and 0 for input
    mov     eax, 3          
    mov     ebx, 0
    mov     ecx, inputBf    ; mov label inputBf into ecx
    mov     edx, bufferSz   ; mov the size of buffer into edx
    int     0x80            ; syscall

    RET                     ; return

string_reverse:             ; eax holds the # of char entered including newline char
    dec     eax             ; dec eax to ignore the newline char
    mov     [qty], eax      ; mov eax into qty
    mov     ecx, [qty]      ; mov qty into ecx to set the counter
    mov     esi, inputBf    ; mov inputBuf into esi (source index)
    mov     eax, 0          ; mov 0 to eax

    .loop1:                 ; push inputBuf into the stack
    mov     al, [esi]   
    push    eax
    inc     esi
    loop    .loop1

    mov     ecx, [qty]      ; mov qty into ecx to set the counter
    mov     esi, inputBf    ; mov inputBf into esi (source index)

    .loop2:                 ; pop the stack and put into esi
    pop     eax
    mov     [esi], al
    inc     esi
    loop    .loop2

    RET                     ; return

print_string:
    inc     dword [qty]     ; inc qty
    mov     eax, 4
    mov     ebx, 1
    mov     ecx, inputBf
    mov     edx, [qty]
    int     0x80            ; syscall

    RET                     ; return

section     .bss
    bufferSz:   equ 255
    inputBf:    resd bufferSz
    qty:        resd 1

section     .data
    prompt:     db "Enter a string: "
    promptSz:   equ $ - prompt

    msg:        db "The reversed string is: "
    msgSz:      equ $ - msg