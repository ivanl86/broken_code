
STRUC   Student
    .id:    resb 10
    .name:  resb 150
    .grade: resb 1
EBDSTRUC



section .text
;------------------------------------------------------------------------------
get_stud_qty:
;
; Description: gets number of students
; Receives: none
; Returns:  return qty on EAX
; Requires: <requirements>
; Notes:    <notes>
; Algo:     <algorithm>
;-------------------------------------------------------------------------------

    push    ebp
    mov     ebp, esp

    push    dword prompt_stud_qty
    call    printstr

    push    dword buff_sz
    push    buffer
    call    get_input

    push    buff
    call    atoi

    leave
    ret
    
; End  <procedure_label> -------------------------------------------------------


section .bss

section .bss
buff_sz:    equ 150
buff:       resb buff_sz


section .data
prompt_stud_qty:    db "Enter the number of students: ", NULL
prompt_stud:        db "Enter student's ", NULL
prompt_id:          db "ID: ", NULL
prompt_name:        db "name: ", NULL
prompt_grade:       db "grade: ", NULL