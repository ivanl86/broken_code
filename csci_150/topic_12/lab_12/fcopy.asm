; who: Ivan Leung ileung2
; what: Copy file
; why: Lab 12
; when: 12/04/2022

section     .text
%include    "../../lib.inc"

global      _start

_start:
    push    ebp
    mov     ebp, esp
    sub     esp, 8

    ; open src file
    push    dword rd_mode   ; read mode
    push    src_path        ; src
    call    file_open
    mov     [ebp - 4], eax  ; local1 = src file descriptor
    add     esp, 4
    cmp     eax, 0          ; print error msg if file not opened
    jl      op_file_error
    end_op_src:

    ; create and open dst file
    push    dst_path
    call    file_creat
    mov     [ebp - 8], eax  ; local2 = dst file descriptor
    add     esp, 4
    cmp     eax, 0          ; print error msg if file not created
    jl      cr_file_error
    end_cr_dst:

    .while:
    ; read from src
    push    buff_sz         ; arg3 = buff size
    push    buff            ; arg2 = buff
    push    dword [ebp - 4] ; arg1 = dst file descriptor
    call    file_read
    add     esp, 12
    cmp     eax, 0
    jle      .wend
    ; write to dst
    push    eax             ; arg3 = bytes read/buff size
    ; push    buff_sz         ; arg3 = buff size
    push    buff            ; arg2 = buff
    push    dword [ebp - 8] ; arg1 = dst file descriptor
    call    file_write
    add     esp, 12
    jmp     .while
    .wend:

    ; close src file
    push    dword [ebp - 4]
    call    file_close
    add     esp, 4
    ; close dst file
    push    dword [ebp - 8]
    call    file_close
    add     esp, 4

    .end:
    leave
    call    exit

section     .bss
buff_sz:    equ 1024
buff:       resb buff_sz        

section     .data
op_error_msg:   db "Failed to open file", NULL
cr_error_msg:   db "Failed to create file", NULL
src_path:   db "einstein_field_eqs.jpeg", NULL
dst_path:   db "fcopy.jpg", NULL

rd_mode     equ 0
wr_mode     equ 1
rw_mode     equ 2

op_file_error:
    push    op_error_msg
    call    printstr
    add     esp, 4
    call    print_nl
    jmp     end_op_src

cr_file_error:
    push    cr_error_msg
    call    printstr
    add     esp, 4
    call    print_nl
    jmp     end_cr_dst

; open src
; open dst
; while
;     read src to buffer
;     if number of bytes read less than 0
;         exit while
;     write buffer to dst
; endwhile
; close src
; close dst

; access mode = 0, 1, 2

; permission for file open
; r = read
; w = write
; x = 
; user, group, other
; rwx, r--, ---
; 111, 100, 000
; 7o, 4o, 0o
; set to 777 for simplicity
; ALL_PERM equ 0o777
; src_path: db "../pic.jpg", NULL

; create mode also open the file

; eax     ebx         ecx         edx
; read 3, file descriptor, buffer address, buffer size
; write 4, file descriptor, buffer address, buffer size
; open 5, file address, access mode, permission
; close 6, file descriptor
; create 8, file address, permission