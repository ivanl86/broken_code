%include "stack.inc"
%include "../../lib.inc"

section     .text

global      _start

_start:
    mov     eax, 0x2d
    xor     ebx, ebx
    int     0x80

    mov     edi, eax

    mov     ebx, eax
    add     ebx, node_size
    mov     eax, 0x2d
    int     0x80

    mov     eax, 8
    mov     dword [edi + node.val], eax

    mov     dword [edi + node.next], head   ; tmp->next = head
    mov     dword [head], edi   ; head = tmp
    mov     dword esi, [head]   ; ESI = head

    push    dword [esi + node.val]
    call    print_uint
    call    print_nl
    add     esp, 4

    push    0
    call    exit

section     .bss
    head:   resd node_size

section     .data