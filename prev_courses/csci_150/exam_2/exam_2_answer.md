# Exam 2 Answer
## Section 1
6) IF-ELSE
##
    if:
    cmp eax, ebx
    jge .else
    mul ebx
    jump .endif
    .else:
    push eax
    cdq
    idiv ebx
    mov ebx, eax
    pop eax
    .endif:
## Section 2
1)
##
    shr: shift n bits to right
         msbs are padded with  zero
         CF = last lsb shifted off
    sar: same as shr with masbs padded with sign bit
    shl: shift n bits left right bits padded with zero
         CF = last msb shifted off
    sal: same as shl
## Section 3
1)
##
    