; who: Ivan Leung ileung2
; what: Creating a struct
; why: In class exercise
; when: 11/21/2022

%include "../../lib.inc"
%include "student.inc"

section     .text

global      _start

_start:
; prompt user for student count
    call    get_stud_qty
; prompt user for each student
; print all students
; print average grade


exit:  
    ; push    0x0
    ; call    exit
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h