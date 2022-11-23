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
    sub     esp, 4
    mov     ebx, esp
; prompt user for student count
    call    get_stud_qty
    cmp     eax, max_student_qty
    jg      exit_with_error

    mov     [ebx], eax
    mov     ecx, [ebx]
    mov     edi, student_array
    .loop1:
; prompt user for each student
    push    ecx

    push    edi
    call    get_student
    add     esp, 4

    add     edi, Student_size
    pop     ecx
    loop    .loop1

    mov     ecx, [ebx]
    .loop2:
; print all students
    push    ecx

    push    esi
    call    print_student
    add     esp, 4

    add     esi, Student_size
    pop     ecx
    loop    .loop2

; print average grade


exit:  
    push    qword 0x0
    call    exit
    ; mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    ; mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    ; int     80h

exit_with_error:
    push    error_msg
    printstr
    push    qword 1
    call    exit

section     .bss

max_student_qty     equ 30
student_array       resb (Student_size * max_student_qty)


section     .data

error_msg:  db "Invalid input!", NL, "Exiting...", NULL


; p/s (char[100])student_array
; x/1x mem address