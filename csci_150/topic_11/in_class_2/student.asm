; who: Ivan Leung ileung2
; what: Creating a struct
; why: In class exercise
; when: 11/21/2022

%include "../../lib.inc"
%include "student.inc"

section     .text

global      _start

_start:
    push    ebp
    mov     ebp, esp
    sub     esp, 12
    push    esi
    push    edi
; prompt user for student count
    call    get_stud_qty
    cmp     eax, max_student_qty
    jg      exit_with_error
    cmp     eax, 1
    jl      exit_with_error

    mov     [ebp - 4], eax      ; store count
    mov     ecx, [ebp - 4]      ; set ECX = count
    mov     dword [ebp - 8], 0  ; init grade sum
    mov     dword [ebp - 12], 0 ; head ptr
    mov     edi, student_array  ; set EDI = student pointer
; prompt user for each student
; print all students
; print average grade


exit:  
    ; push    0x0
    ; call    exit
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h