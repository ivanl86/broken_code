%include "stack.inc"
%include "../../lib.inc"

section     .text

global      _start

_start:



exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

section     .bss
    head:   resd node_size

section     .data