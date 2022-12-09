%include "stack.inc"
%include "../../lib.inc"

section     .text

global      _start

_start:
    push    ebp
    mov     ebp, esp
    sub     esp, 4

    ; mov     edi, head   ; edi = head
    ; ; push
    ; mov     dword [edi + node.val], 90  ; head->val = 83
    ; inc     dword [count]

    ; mov     eax, 0x2d   ; sys_brk
    ; xor     ebx, ebx    ; EBX = 0
    ; int     0x80        ; perform sys_call

    ; mov     dword [edi + node.next], eax; head->next = new node

    ; mov     ebx, eax    ; EBX = top of heap
    ; add     ebx, node_size  ; resevred node size on heap
    ; mov     eax, 0x2d
    ; int     0x80

    ; ; push
    ; add     edi, node.next
    ; mov     dword [edi + node.val], 40
    ; inc     dword [count]

    ; mov     eax, 0x2d   ; sys_brk
    ; xor     ebx, ebx    ; EBX = 0
    ; int     0x80        ; perform sys_call

    ; mov     dword [edi + node.next], eax; head->next = new node

    ; mov     ebx, eax    ; EBX = top of heap
    ; add     ebx, node_size  ; resevred node size on heap
    ; mov     eax, 0x2d
    ; int     0x80
    ; ; push
    ; add     edi, node.next
    ; mov     dword [edi + node.val], 96
    ; inc     dword [count]

    ; mov     eax, 0x2d   ; sys_brk
    ; xor     ebx, ebx    ; EBX = 0
    ; int     0x80        ; perform sys_call

    ; mov     dword [edi + node.next], eax; head->next = new node

    ; mov     ebx, eax
    ; add     ebx, node_size  ; resevred node size in heap
    ; mov     eax, 0x2d
    ; int     0x80
    ; ; push
    ; add     edi, node.next
    ; mov     dword [edi + node.val], 22
    ; inc     dword [count]

    ; mov     eax, 0x2d   ; sys_brk
    ; xor     ebx, ebx    ; EBX = 0
    ; int     0x80        ; perform sys_call

    ; mov     dword [edi + node.next], eax; head->next = new node

    ; mov     ebx, eax
    ; add     ebx, node_size  ; resevred node size in heap
    ; mov     eax, 0x2d
    ; int     0x80
    ; ----------------------------
    mov     edi, head
    pushnode:
    mov     dword eax, [count]

    mov     dword [edi + node.val], 78
    inc     dword [count]

    mov     eax, 0xed
    xor     ebx, ebx
    int     0x80

    mov     [edi + node.next], eax

    mov     ebx, eax
    add     ebx, node_size
    mov     eax, 0x2d
    int     0x80

    add     edi, (node.next)
    ; cmp     dword [count], 5
    ; jl      pushnode

    ; print val
    mov     esi, head
    mov     ecx, [count]

    .loop:
    push ecx

    push    dword [esi + node.val]
    call    print_uint
    call    print_nl
    add     esp, 4

    add     esi, node.next
    pop     ecx
    loop    .loop

    ; push    dword [esi + node.val]
    ; call    print_uint
    ; call    print_nl
    ; add     esp, 4

    ; add     esi, node.next

    ; push    dword [esi + node.val]
    ; call    print_uint
    ; call    print_nl
    ; add     esp, 4

    ; add     esi, node.next

    ; push    dword [esi + node.val]
    ; call    print_uint
    ; call    print_nl
    ; add     esp, 4

    ; push    dword [head]
    ; call    print_uint
    ; call    print_nl
    ; add     esp, 4

    leave

    push    dword 0
    call    exit

section     .bss
    head:   resd node_size
section     .data
    count:  dd 0





; -----------------

;     mov     edi, head

; ; insert
;     mov     eax, 0x2d   ; sys_brk
;     xor     ebx, ebx    ; EBX = 0
;     int     0x80        ; perform sys_call

;     mov     [edi], eax
;     mov     dword [edi + node.val], 87

;     mov     ebx, eax    ; EBX = top of heap
;     add     ebx, node_size  ; add node_size to top of heap
;     mov     eax, 0x2d   ; sys_brk
;     int     0x80

;     mov     edi, [edi + node.next]
; ; insert
;     mov     eax, 0x2d   ; sys_brk
;     xor     ebx, ebx    ; EBX = 0
;     int     0x80        ; perform sys_call

;     mov     [edi], eax
;     mov     dword [edi + node.val], 67

;     mov     ebx, eax    ; EBX = top of heap
;     add     ebx, node_size  ; add node_size to top of heap
;     mov     eax, 0x2d   ; sys_brk
;     int     0x80