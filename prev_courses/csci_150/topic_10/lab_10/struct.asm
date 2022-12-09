; who: Ivan Leung ileung2
; what: <the function of this program>
; why: <the name of the lab>
; when: < the due date of this lab.>

STRUC student
    .id:    resb id_sz
    .name:  resb name_sz
    .grade: resb grade_sz
ENDSTRUC


section     .text
%include    "../../lib.inc"

global      _start

_start:

    push    get_count
    call    printstr
    add     esp, 4

    push    count_sz
    push    count
    call    get_input
    add     esp, 8

    push    count
    call    atoi
    add     esp, 4

    mov     ecx, 5              ; ECX = count of students
    lea     esi, students       ; ESI = students

get_students:
    lea     edi, [esi]          ; EDI = ESI
    push    ecx

    call    get_id
    call    get_name
    call    get_grade

    pop     ecx
    add     esi, student_size   ; ESI = next student
    loop    get_students
    .end_get_students:

    mov     ecx, 5              ; ECX = count of students
    lea     esi, students       ; ESI = students
    call    print_students

    mov     ecx, 5              ; ECX = count of students
    lea     edi, [students + student.grade]     ;  EDI = student.grade
    call    print_average_grade

    call    print_nl

exit:  
    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, 0      ; return 0 status on exit - 'No Errors'
    int     80h

section     .bss
students:   resb (student_size * 5)

count_sz: equ 255
count:    resb count_sz

section     .data
get_count:  db "Enter the number of students: ", NULL
prompt:     db "Enter the student's ", NULL
id:         db "ID: ", NULL
name:       db "name: ", NULL
grade:      db "grade: ", NULL
print_av_grade:     db "The average grade is: ", NULL
print_A:    db "A", NULL
print_B:    db "B", NULL
print_C:    db "C", NULL
print_D:    db "D", NULL
print_F:    db "F", NULL

id_sz:      equ 10
name_sz:    equ 150
grade_sz:   equ 2

get_id:
    push    prompt
    call    printstr
    add     esp, 4

    push    id
    call    printstr
    add     esp, 4

    add     edi, student.id ; EDI = student.id
    push    id_sz
    push    edi
    call    get_input
    add     esp, 8
    sub     edi, student.id ; EDI = students

    ret
    .end_get_id:

get_name:
    push    prompt
    call    printstr
    add     esp, 4

    push    name
    call    printstr
    add     esp, 4

    add     edi, student.name ; EDI = student.name
    push    name_sz
    push    edi
    call    get_input
    add     esp, 8
    sub     edi, student.name ; EDI = students

    ret
    .end_get_name:


get_grade:
    push    prompt
    call    printstr
    add     esp, 4

    push    grade
    call    printstr
    add     esp, 4

    add     edi, student.grade ; EDI = student.grade
    push    grade_sz
    push    edi
    call    get_input
    add     esp, 8
    push    edi
    call    to_upper
    add     esp, 4
    sub     edi, student.grade ; EDI = students

    ret
    .end_get_grade:

print_students:
    lea     edi, [esi]
    push    ecx

    .print_id:
    add     edi, student.id
    push    edi
    call    printstr
    add     esp, 4
    sub     edi, student.id
    .end_print_id:

    call    print_nl

    .print_name:
    add     edi, student.name
    push    edi
    call    printstr
    add     esp, 4
    sub     edi, student.name
    .end_print_name:

    .print_grade:
    add     edi, student.grade
    push    edi
    call    printstr
    add     esp, 4
    sub     edi, student.grade
    .end_print_grade:

    call    print_nl
    pop     ecx
    add     esi, student_size
    loop    print_students

    ret
    .end_print_students:

print_average_grade:
    xor     ebx, ebx

    .while:
    lea     esi, [edi]          ; ESI = EDI = student.grade
    push    ecx                 ; preserve count

    mov     dl, 70              ; DL = 'F'
    lodsb   
    sub     dl, al              ; 'F' - student.grade
    add     bl, dl              ; BL = sum of grades

    pop     ecx
    add     edi, student_size   ; EDI = next student
    loop    .while

    xor     edx, edx            ; clear EDX
    mov     al, bl              ; AL = sum of grades
    mov     cl, 5               ; CL = count of students
    div     ecx                 ; Total divided by count

    push    eax
    push    print_av_grade
    call    printstr
    add     esp, 4
    pop     eax

    cmp     eax, 5
    jae      .get_A
    cmp     eax, 4
    jae     .get_B
    cmp     eax, 3
    jae     .get_C
    cmp     eax, 2
    jae     .get_D

    .get_F:
    push    print_F
    call    printstr
    add     esp, 4
    jmp     .end
    .get_D:
    push    print_D
    call    printstr
    add     esp, 4
    jmp     .end
    .get_C:
    push    print_C
    call    printstr
    add     esp, 4
    jmp     .end
    .get_B:
    push    print_B
    call    printstr
    add     esp, 4
    jmp     .end
    .get_A:
    push    print_A
    call    printstr
    add     esp, 4
    .end:
    ret
    .end_print_average_grade: