# Exam 3 Review
## Section 1
(1)
##
        a) EAX, ECX, EDX only if the info is needed
        b) EBX, ESI, EDI, EBP only if used

(2)
##
        push    EBP
        mov     EBP, ESP
        sub     ESP, 4
        push    EDI
        push    ESI

        mov     ESI, [EBP + 8]
        mov     EDI, [EBP + 12]
(3)
##
        push    val2
        push    val1
        call    swap
        add     ESP, 8
(6)
##
        mov     ESP, EBP
        pop     EBP
## Section 2
(2)
##
        CLD: lets EDI or ESI increment by 1, 2, 4
        STD: lets EDI or ESI decrement by 1, 2, 4
(3)
- index is mem offset
- subscript is element offset
##
        mov     ESI, src_array
        mov     EDI, dst_array
        mov     ECX, array_sz

        cld
        rep     movsb
(4)
##
    scasb   EDI, AL
    scasw   EDI, AX
    scasd   EDI, EAX

    repe
    repne
(5)
##
    lodsb   ESI, AL
    lodsw   ESI, AX
    lodsd   ESI, EAX
    stosb   EDI, AL
    stosw   EDI, AX
    stosd   EDI, EAX