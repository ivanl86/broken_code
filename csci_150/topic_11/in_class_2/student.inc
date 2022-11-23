
STRUC   Student
    .id:    resb 10
    .name:  resb 150
    .grade: resb 1
EBDSTRUC

;------------------------------------------------------------------------------
get_student:
;
; Description: prompts for and stores  a student
; Receives: arg1 = address to store student at
; Returns:  <return list>
; Requires: <requirements>
; Notes:    <notes>
; Algo:     <algorithm>
;-------------------------------------------------------------------------------

    push    ebp         ; setup frame
    mov     ebp, esp    ; preserve edi
    push    edi
    push    ebx

    mov     edi, [ebp + 8]
    ; prompt for id
    push    prompt_stud
    printstr
    push    prompt_id
    printstr
    ; get id
    lea     edi, [ebx + Student.id]
    push    dword 10
    push    edi
    call    get_input
    ; prompt for name
    push    prompt_stud
    printstr
    push    prompt_name
    printstr
    ; get name
    lea     edi, [ebx + Student.name]
    push    dword 150
    push    edi
    call    get_input
    ; prompt for grade
    push    prompt_stud
    printstr
    push    prompt_grade
    printstr
    ; get grade
    call    getchar
    lea     edi, [ebx + Student.grade]
    mov     [edi], al

    pop     ebx
    pop     edi         ; restore edi
    leave               ; teardown frame
    ret
    
; End  <procedure_label> -------------------------------------------------------

;------------------------------------------------------------------------------
print_student:
;
; Description:
; Receives: <argument list>
; Returns:  <return list>
; Requires: <requirements>
; Notes:    <notes>
; Algo:     <algorithm>
;-------------------------------------------------------------------------------

    push    ebp
    mov     ebp, esp
    push    edi
    push    ebx
    mov     ebx, [ebp + 8]
    
    push    prompt_id
    call    printstr
    add     esp, 4
    lea     edi, [ebx + Student.id]
    push    edi
    call    printstr
    add     esp, 4
    call    print_nl

    push    prompt_name
    call    printstr
    add     esp, 4
    lea     edi, [ebx + Student.name]
    push    edi
    call    printstr
    add     esp, 4
    call    print_nl

    push    prompt_grade
    call    printstr
    add     esp, 4
    lea     edi, [ebx + Student.grade]
    push    edi
    call    printstr
    add     esp, 4
    call    print_nl

    pop     ebx
    pop     edi
    leave
    ret
    
; End  <procedure_label> -------------------------------------------------------

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
