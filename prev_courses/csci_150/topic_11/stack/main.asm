%include "stack.inc"
%include "../../lib.inc"

section     .text

global      _start

_start:
    mov     dword [count], 0      ; count = 0

    insert:
    mov     eax, 0x2d
    xor     ebx, ebx
    int     0x80

    mov     edi, eax

    mov     ebx, eax
    add     ebx, node_size
    mov     eax, 0x2d
    int     0x80

    mov     eax, 90    ; EAX = count
    mov     dword [edi + node.val], eax ; tmp->val = EAX
    inc     dword [count]   ; increment count

    mov     dword [edi + node.next], head   ; tmp->next = head
    mov     dword [head], edi   ; head = tmp
    mov     dword esi, [head]   ; ESI = head
    cmp     dword [count], 5
    jl      insert
    endinsert:

    ; mov     eax, 0x2d
    ; xor     ebx, ebx
    ; int     0x80

    ; mov     edi, eax

    ; mov     ebx, eax
    ; add     ebx, node_size
    ; mov     eax, 0x2d
    ; int     0x80

    ; mov     eax, 88     ; EAX = 88
    ; mov     dword [edi + node.val], eax ; tmp->val = EAX

    ; mov     dword [edi + node.next], head   ; tmp->next = head
    ; mov     dword [head], edi   ; head = tmp
    ; mov     dword esi, [head]   ; ESI = head

    mov     ecx, [count]

    print:
    push    ecx
    push    dword [esi + node.val]
    call    print_uint
    call    print_nl
    add     esp, 4

    pop     ecx
    add     dword [esi], node.next
    loop    print

    ; push    dword [esi + node.val]
    ; call    print_uint
    ; call    print_nl
    ; add     esp, 4

    push    0
    call    exit

section     .bss
    head:   resd node_size

section     .data
    count:  dd 1