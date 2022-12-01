global sum_int_array
global factorial
global printstr
global get_input
global strlen
global atoi
global itoa
global swap
global swap_xor
global srand
global rand
global current_time
global print_nl
global is_even
global array_search
global copy_int_array
global strcopy
global to_lower
global to_upper
global getchar
global printchar
global print_int_array
global exit
global get_uint
global print_uint
global file_open
global file_close
global file_read
global file_write
global file_creat

; constant
global NL
global NULL
global TRUE
global FALSE
global RAND_MAX

;-------------------------------------------------------------------------------
; who: Ivan Leung ileung2
; what: Library
; why: Reusable procedures
; when: Fall 2022
;-------------------------------------------------------------------------------

;------------------------------------------------------------------------------
file_open:
;
; Description: open a file
; Receives: arg1 = address of file
;           arg2 = access mode {0 = rd, 1 = wr, 2 = rd n wr}
; Returns:  <return list>
; Requires: <requirements>
; Notes:    <notes>
; Algo:     <algorithm>
;-------------------------------------------------------------------------------

    push    ebp
    mov     ebp, esp
    push    ebx

    mov     eax, 5          ; EAX = sys_open
    mov     ebx, [ebp + 8]  ; EBX = src file name
    mov     ecx, [ebp + 12] ; ECX = access mode
    mov     edx, ALL_PERM   ; EDX = permission
    int     0x80            ; perform sys_call

    pop     ebx
    leave
    ret
    
; End  file_open -------------------------------------------------------

;------------------------------------------------------------------------------
file_close:
;
; Description: close a file
; Receives: arg1 = file descriptor
; Returns:  <return list>
; Requires: <requirements>
; Notes:    <notes>
; Algo:     <algorithm>
;-------------------------------------------------------------------------------

    push    ebp
    mov     ebp, esp
    push    ebx

    mov     eax, 6          ; EAX = sys_close
    mov     ebx, [ebp + 8]  ; EBX = file descriptor
    int     0x80            ; perform sys_call
    
    pop     ebx
    leave
    ret
    
; End  file_close -------------------------------------------------------

;------------------------------------------------------------------------------
file_read:
;
; Description: read from file
; Receives: arg1 = file descriptor
;           arg2 = address of buffer
;           arg3 = buffer size
; Returns:  EAX = number of bytes read
; Requires: <requirements>
; Notes:    <notes>
; Algo:     <algorithm>
;-------------------------------------------------------------------------------

    push    ebp
    mov     ebp, esp
    push    ebx

    mov     eax, 3          ; EAX = sys_read
    mov     ebx, [ebp + 8]  ; EBX = file descriptor
    mov     ecx, [ebp + 12] ; ECX = buff
    mov     edx, [ebp + 16] ; EDX = buff size
    int     0x80            ; perform sys_call
    
    pop     ebx
    leave
    ret
    
; End  file_read -------------------------------------------------------

;------------------------------------------------------------------------------
file_write:
;
; Description: write to file
; Receives: arg1 = file descriptor
;           arg2 = address of buffer
;           arg3 = buffer size
; Returns:  <return list>
; Requires: <requirements>
; Notes:    <notes>
; Algo:     <algorithm>
;-------------------------------------------------------------------------------

    push    ebp
    mov     ebp, esp
    push    ebx

    mov     eax, 4          ; EAX = sys_wirte
    mov     ebx, [ebp + 8]  ; EBX = file descriptor
    mov     ecx, [ebp + 12] ; ECX = buff
    mov     edx, [ebp + 16] ; EDX = buff size
    int     0x80            ; perform sys_call
    
    pop     ebx
    leave
    ret
    
; End  file_write -------------------------------------------------------

;------------------------------------------------------------------------------
file_creat:
;
; Description:
; Receives: arg1 = address of file
; Returns:  EAX = file descriptor
; Requires: <requirements>
; Notes:    <notes>
; Algo:     <algorithm>
;-------------------------------------------------------------------------------

    push    ebp
    mov     ebp, esp
    push    ebx

    mov     eax, 8          ; EAX = sys_creat
    mov     ebx, [ebp + 8]  ; EBX = buff
    mov     ecx, ALL_PERM   ; ECX = permission
    int     0x80            ; perform sys_call

    pop     ebx
    leave
    ret
    
; End  file_creat -------------------------------------------------------

;------------------------------------------------------------------------------
get_uint:
;
; Description: get an unsigned integer input from user
; Receives: nothing
; Returns:  EAX = unsigned int
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    buff_sz
    push    buff
    call    get_input
    add     esp, 8

    push    buff
    call    atoi
    add     esp, 4
    
    ret
    
; End  get_uint -------------------------------------------------------

;------------------------------------------------------------------------------
print_uint:
;
; Description: print an int
; Receives: arg1 = value of int
; Returns:  nothing
; Requires: nothing
; Notes:    push value of int not address of int
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp
    mov     ebp, esp

    push    buff
    push    dword [ebp + 8]
    call    itoa
    add     esp, 8

    push    buff
    call    printstr
    add     esp, 4

    leave
    ret
    
; End  print_uint -------------------------------------------------------


;------------------------------------------------------------------------------
getchar:
;
; Description: get a char input from user
; Receives: nothing
; Returns:  EAX = character
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push     ebp
    mov      ebp, esp 

    push    dword 2
    push    buff
    call    get_input
    
    movzx   eax, byte [buff]

    leave    
    ret
    
; End  getchar -------------------------------------------------------

;------------------------------------------------------------------------------
printchar:
;
; Description: print a char
; Receives: arg1 = char
; Returns:  nothing
; Requires: nothing
; Notes:    push value of char not address of char
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp
    mov     ebp, esp
    push    edi

    mov     eax, [ebp + 8]
    mov     [buff], al
    mov     byte [buff + 1], NULL

    push    buff
    call    printstr
    add     esp, 4

    pop     edi
    leave
    ret
    
; End  printchar -------------------------------------------------------


;------------------------------------------------------------------------------
copy_int_array:
;
; Description: copy array of dwords from one buffer to another
; Receives: arg1 src array
;           arg2 dst array
;           arg3 src size (number of element in src array)
; Returns:  nothing
; Requires: nothing
; Notes:    dst buffer is expected to be the correct size
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp
    mov     ebp, esp
    push    esi
    push    edi

    mov     esi, [ebp + 8]  ; ESI = arg1
    mov     edi, [ebp + 12] ; EDI = arg2
    mov     ecx, [ebp + 16] ; ECX = arg3

    cld             ; set forward
    rep     movsd   ; mov esi to edi until ECX = 0
    
    pop     edi
    pop     esi
    leave
    ret
    
; End  copy_int_array -------------------------------------------------------


;-------------------------------------------------------------------------------
sum_int_array:
;
; Descriptions: Sums the integer (dwords) elements of an array
; Receives: arg1 = address of array
;           arg2 = number of elements
; Returns:  EAX = sum of the elements of the array
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp             ; preserve caller's base pointer
    mov     ebp, esp        ; set base of frame

    push    esi             ; preserve esi

    mov     esi, [ebp + 8]  ; esi = address of array = arg1
    mov     ecx, [ebp + 12] ; ecx = number of elements = arg2
    ; mov     esi, eax        ; mov address of array into esi
    ; mov     ecx, ebx        ; mov count of array elements into ecx
    xor     eax, eax        ; set eax = 0

    .loop:
    add     eax, [esi]
    add     esi, 4
    loop    .loop

    pop     esi
    leave
    ret

; End sum_int_array-----------------------------------------------------------------

;------------------------------------------------------------------------------
factorial:
;
; Description: calculates the factorialof an unsigned integer (N!)
; Receives: arg1 = receive on stack the value of n
; Returns:  EAX = n!
; Requires: <requirements>
; Notes:    <notes>
; Algo:     <algorithm>
;-------------------------------------------------------------------------------

    push    ebp             ; preserve caller's base pointer
    mov     ebp, esp        ; set base of frame

    mov     eax, 1          ; base case return value
    mov     ecx, [ebp + 8]  ; ecx = n = arg1
    cmp     ecx, eax        ; is n <= 1?
    jbe     .base           ; if n <= 1 then base case

    dec     ecx
    push    ecx
    call    factorial
    mul     dword [ebp + 8]

    .base:

    leave
    ret

    ; push    ebp         ; preserve caller's base pointer
    ; mov     ebp, esp    ; set base of frame

    ; mov     eax, [ebp + 8]  ; move n to eax, n is in the stack which is ebp + 8
    ; cmp     eax, 1          ; if n <= 1: base case
    ; jle     .base           ; jummp to base

    ; dec     eax
    ; push    eax
    ; call    factorial
    ; mul     dword [ebp + 8]

    ; .base:
    ; leave

    ret
    
; End  factorial -------------------------------------------------------

;------------------------------------------------------------------------------
to_lower:
;
; Description: convert uppercase alphabet char to lowercase
; Receives: arg1 = address of string
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp
    mov     ebp, esp
    push    edi
    push    esi

    mov     esi, [ebp + 8]  ; ESI = arg1
    mov     edi, [ebp + 8]
    cld                     ; forward

    .while:
    lodsb
    cmp     al, NULL
    je      .wend
    cmp     al, 65
    jb      .skip
    cmp     al, 90
    ja      .skip
    add     al, 32
    .skip:
    stosb
    loop    .while
    .wend:

    pop     esi
    pop     edi
    leave
    ret
    
; End  to_lower -------------------------------------------------------

;------------------------------------------------------------------------------
to_upper:
;
; Description: convert lowercase alphabet char to uppercase
; Receives: arg1 = address of string
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp
    mov     ebp, esp
    push    edi
    push    esi

    mov     esi, [ebp + 8]  ; ESI = arg1
    mov     edi, [ebp + 8]
    cld                     ; forward

    .while:
    lodsb
    cmp     al, NULL
    je      .wend
    cmp     al, 97
    jb      .skip
    cmp     al, 122
    ja      .skip
    sub     al, 32
    .skip:
    stosb
    loop    .while
    .wend:

    pop     esi
    pop     edi
    leave
    ret
    
; End  to_upper -------------------------------------------------------

;------------------------------------------------------------------------------
strcopy:
;
; Description: copy from one string to another
; Receives: arg1 = address of src string
;           arg2 = address of dst string
; Returns:  nothing
; Requires: nothing
; Notes:    assume dst string has correct length
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp
    mov     ebp, esp
    push    esi
    push    edi

    push    dword [ebp + 8]
    call    strlen          ; EAX = size of string
    add     esp, 4

    mov     edi, [ebp + 12] ; EDI = arg2
    mov     esi, [ebp + 8]  ; ESI = arg1

    cld
    mov     ecx, eax        ; ECX = size of string (arg1)
    rep     movsb

    pop     edi
    pop     esi
    leave
    ret
    
; End  strcopy -------------------------------------------------------


;-------------------------------------------------------------------------------
strlen:
;
; Description: Calculates the size of a null-termainated string
; Receives: arg1 = address of string on stack
; Returns:  EAX = size of string
; Requires: The string must be null-terminated
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp             ; preserve caller's base pointer
    mov     ebp, esp        ; set base of frame
    push    edi             ; preserve EDI

    mov     edi, [ebp + 8]  ; EDI = arg1
    mov     al, NULL        ; AL = NULL
    mov     ecx, 0xFFFF     ; ECX

    cld                     ; go forward
    repne   scasb           ; repeat scan until it finds NULL
    dec     edi
    mov     eax, edi        ; EAX = address of null in string
    mov     edx, [ebp + 8]  ; EDX = address of first char in string
    sub     eax, edx        ; EAX = length of string

    ; push    esi             ; perserve esi
    ; mov     esi, [ebp + 8]  ; esi = address of string = arg1
    ; xor     eax, eax        ; eax will be the counter of none-null chars

    ; .while:
    ; cmp     byte [esi], NULL
    ; je      .wend
    ; inc     eax
    ; inc     esi
    ; jmp     .while

    ; .wend:

    ; pop     esi
    pop     edi
    leave
    ret
    
; End strlen -------------------------------------------------------------------

;-------------------------------------------------------------------------------
printstr:
;
; Descriptions: Print a string
; Receives: arg1 = address of string
; Returns:  none
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    ; push    eax             ; preserve string address

    ; push    ebx

    push    ebp             ; preserve caller's base pointer
    mov     ebp, esp        ; set base of frame
    push    ebx             ; preserve caller's base pointer

    push    dword [ebp + 8] ; strlen arg1 = addres of string 
    call    strlen          ; eax has the size of the string
    add     esp, 4

    mov     edx, eax        ; edx = size of the string
    ; pop     ecx             ; restore the address into ecx
    mov     ecx, [ebp + 8]  ; ecx = address of string = arg1

    mov     eax, 4          ; mov 4 to eax indicates write operation
    mov     ebx, 1          ; mov 1 to ebx indicates stdout
    int     0x80            ; performs syscall

    pop     ebx             ; restore caller's base pointer
    leave
    ret

; End sum_int_array------------------------------------------------------------------

;------------------------------------------------------------------------------
print_int_array:
;
; Description: print an array of dword unsigned integer
; Receives: arg1 = address of the array
;           arg2 = the number of element in the array
; Returns:  none
; Requires: nothing
; Notes:    Print out format: { a, b, c, d }
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp
    mov     ebp, esp

    push    dword [buff_op_brace]
    call    printchar
    add     esp, 4

    mov     ecx, [ebp + 12]
    mov     esi, [ebp + 8]

    .print:
    push    ecx

    push    dword [buff_space]
    call    printchar
    add     esp, 4

    mov     eax, [esi]
    push    eax
    call    print_uint
    add     esp, 4
    add     esi, 4

    pop     ecx
    cmp     ecx, 1
    push    ecx
    je      .no_comma

    .print_comma:
    push    dword [buff_comma]
    call    printchar
    add     esp, 4
    .no_comma:
    pop     ecx
    loop    .print

    push    dword [buff_space]
    call    printchar
    add     esp, 4

    push    dword [buff_cl_brace]
    call    printchar
    add     esp, 4

    leave    
    ret
    
; End  print_int_array -------------------------------------------------------

;--------------------------------------------------------------------------------
get_input:
;
; Descriptions: Get a string input from the user
; Receives: arg1 = address of input buffer
;           arg2 = size of input buffer
; Returns:  none
; Requires: nothing
; Notes:    remove newline char if it exists and null terminate
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp             ; preserve caller's base pointer
    mov     ebp, esp        ; set base of frame  
    push    ebx

    mov     eax, 3          ; read
    mov     ebx, 0          ; set cin
    mov     ecx, [ebp + 8]  ; set address ob input buffer
    mov     edx, [ebp + 12] ; set input size
    int     0x80
    
    dec     eax
    mov     ebx, [ebp + 8] 
    add     ebx, eax
    mov     byte [ebx], NULL

    pop     ebx    
    leave
    ret                     ; return the number of characters enetered

; End get_input------------------------------------------------------------------


;-------------------------------------------------------------------------------
is_even:
;
; Description: Takes a value and return 1 if even or false otherwise
; Receives: arg1 = the value will be checked
; Returns:  EAX = TRUE or FALSE
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp             ; preserve caller's base pointer
    mov     ebp, esp        ; set base of frame

    mov     eax, [ebp + 8]  ; eax = value to be checked = arg1
    and     eax, 1          ; use AND instruction on EAX with 1
    xor     eax, 1          ; use XOR instruction on EAX to clear other bits
    ; EAX = 1 if even
    ; EAX = 0 if odd
    leave
    ret                     ; return EAX
    
; End  is_even -----------------------------------------------------------------



;-------------------------------------------------------------------------------
atoi:
;
; Description: convert null terminated representation of a unsigned integer to an unsigned integer
; Receives: arg1 = address of a NULL terminated string = EDX
; Returns:  EAX = converted unsigned integer value
; Requires: nothing
; Notes:    none
; Algo:     use horner's method
;-------------------------------------------------------------------------------
    push    ebp                     ; setup frame
    mov     ebp, esp
    push    esi                     ; preserve esi

    mov     esi, [ebp + 8]          
    mov     eax, 0
    mov     ecx, 10
    movzx   edx, byte [esi]

    .while:
    test    edx, edx
    jz      .wend
    mul     ecx
    movzx   edx, byte [esi]
    add     eax, edx
    sub     eax, 48
    inc     esi
    movzx   edx, byte [esi]
    jmp     .while
    .wend:

    pop     esi                     ; retore esi
    leave                           ; teardown frame
    ret
    
; End atoi ---------------------------------------------------------------------

;------------------------------------------------------------------------------
itoa:
;
; Description: converts an unsigned integer to a null-terminated string representation
; Receives: arg1 = unsigned integer value = eax, last to push
;           arg2 = address of string buffer = edi, push before arg1
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    push    ebp             ; preserve caller's base pointer
    mov     ebp, esp        ; set base of frame

    sub     esp, 8          ; allocate counter var
    mov     dword [ebp - 4], 0 ; initialzing counter
    mov     dword [ebp - 8], 10; divisor

    push    edi

    ; mov     edi, ebx 
    mov     eax, [ebp + 8]  ; eax = unsigned integer value = arg1
    mov     edi, [ebp + 12] ; edi = address of string buffer = arg2

    ; loop over eax (until 0)
    ; div by  10
    ; use remainder + 48 as the character
    .while:
    test    eax, eax
    jz      .wend
    mov     edx, 0
    div     dword [ebp - 8] ; div eax by 10

    add     edx, 48         ; add 48 to the remainder to convert number to char
    push    edx             ; push edx into stack
    inc     dword [ebp - 4] ; inc the counter
    jmp     .while
    .wend:

    mov     ecx, [ebp - 4]  ; mov counter into ecx
    .loop:
    pop     eax             ; pop the char into eax
    mov     [edi], al       ; mov al into edi
    inc     edi             ; inc edi to mov to next char
    loop    .loop

    mov     byte [edi], NULL; null terminate the string

    pop     edi
    leave
    ret
    
; End  <procedure_label> -------------------------------------------------------

;-------------------------------------------------------------------------------
swap:
;
; Description: Swap the 32bit values located at the addresses passed in as args
; Receives: EAX: address of first value (val1)
;           EBX: address of second value (val2)
; Returns:  <return list>
; Requires: <requirements>
; Notes:    The registers hold the addresses of two values to be swapped, not the values themselves
; Algo:     <algorithm>
;-------------------------------------------------------------------------------

    push    ebp
    mov     ebp, esp
    sub     esp, 4

    lea     esi, [ebp - 4]  ; move address of local var into esi
    mov     esi, [eax]      ; move val1 into esi
    xchg    esi, [ebx]      ; exchange val1 in esi with val2 in ebx
    mov     [eax], esi      ; move val2 in esi into eax
    
    leave
    ret
    
; End  <procedure_label> -------------------------------------------------------

;-------------------------------------------------------------------------------
swap_xor:
;
; Description: Swap the 32bit values located at the addresses passed in as args
; Receives: EAX: address of first value (val1)
;           EBX: address of second value (val2)
; Returns:  <return list>
; Requires: <requirements>
; Notes:    The registers hold the addresses of two values to be swapped, not the values themselves
; Algo:     <algorithm>
;-------------------------------------------------------------------------------

    mov     ecx, [eax]  ; mov val1 into ecx
    mov     edx, [ebx]  ; mov val2 into edx

    xor     ecx, [ebx]  ; a ^ b
    xor     [ebx], ecx  ; b ^ a
    xor     ecx, [ebx]  ; a ^ b

    xor     edx, [eax]  ; b ^ a
    xor     [eax], edx  ; a ^ b
    xor     edx, [eax]  ; b ^ a

    ret
    
; End  <procedure_label> -------------------------------------------------------

;-------------------------------------------------------------------------------
srand:
;
; Description: Seeds the value used by rand
; Receives: arg1 = seed value
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

    ; mov     [next], eax
    push    ebp             ; preserve caller's base pointer
    mov     ebp, esp        ; set base of frame

; can i mov arg1 to next directly
    mov     eax, [ebp + 8]  ; eax = see value = arg1
    mov     [next], eax

    leave
    ret
    
; End srand --------------------------------------------------------------------

;-------------------------------------------------------------------------------
rand:
;
; Description: generates a random unsigned integer value
; Receives: nothing
; Returns:  EAX = a random unsigned integer value
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------
  
    ; mov     eax, [next]     ; mov next to eax
    ; mov     ebx, n_0        ; mov n_0 to ebx
    ; mul     ebx             ; mul eax by ebx (eax * 1103515245)
    ; add     eax, n_1        ; add n_1 to eax (eax + 12345)

    ; mov     ebx, n_2        ; mov n_2 to ebx
    ; xor     edx, edx        ; clear edx
    ; div     ebx             ; div eax by ebx (eax / 65536 )
    ; xor     edx, edx        ; clear edx
    ; mov     ebx, n_3        ; mov n_3 to ebx
    ; div     ebx             ; div eax by ebx (eax / 32768)
    ; movzx   eax, dx         ; mov dx (remainder) to eax

    mov     eax, [next]     ; eax = next
    mov     ecx, RANDC1     ; ecx = RANDC1
    mul     ecx             ; edx:eax = eax * ecx
    add     eax, RANDC2     ; eax = eax + RANDC2
    mov     [next], eax     ; update next
    ; next = next * 1103515245 + 12345

    xor     edx, edx        ; clear edx for div
    mov     ecx, RANDC3     ; ecx = RANDC3
    div     ecx             ; edx:eax = eax / ecx

    xor     edx, edx        ; clear edx for div
    mov     ecx, RANDC4     ; ecx = RANDC4
    div     ecx             ; edx:eax = eax / ecx
    mov     eax, edx        ; move remainder from edx into eax for return
    ; return next / 65536 % 32768
    ret
    
; End rand ---------------------------------------------------------------------

;-------------------------------------------------------------------------------
current_time:
;
; Description: 
; Receives: <argument list>
; Returns:  <return list>
; Requires: <requirements>
; Notes:    <notes>
; Algo:     <algorithm>
;-------------------------------------------------------------------------------

    push    ebx             ; preserve

    mov     eax, 13         ; syscall number for time
    mov     ebx, 0          ; time location = NULL
    int     0x80            ; 32 bit time vlaue returned in EAX

    pop     ebx             ; restore
    
    ret
    
; End current_time -------------------------------------------------------------

;------------------------------------------------------------------------------
array_search:
;
; Description: search an array. return subscript of the value if found or -1 otherwise
; Receives: arg1 = array address
;           arg2 = size of array
;           arg3 = search term
; Returns:  EAX = subscript of search term
; Requires: return subscript or -1
; Notes:    <notes>
; Algo:     <algorithm>
;-------------------------------------------------------------------------------

    push    ebp             ; preserve caller's base pointer
    mov     ebp, esp        ; set base of frame

    sub     esp, 4          ; establish a local var

    push    ebx             ; preserve ebx
    push    esi             ; preserve esi
    push    edi             ; preserve edi

    ; lea     edi, [ebp - 4]  ; edi holds address of local var
    ; mov     dword [edi], 0  ; initial counter
    ; mov     esi, eax        ; esi = address of array
    ; add     ebx, eax        ; ebx is upper bound of array
    ; mov     eax, -1
    lea     edi, [ebp - 4]  ; edi holds address of local var
    mov     dword [edi], 0  ; initialize counter
    mov     esi, [ebp + 8]  ; esi = address of array = arg1
    mov     ebx, [ebp + 12] ; ebx = size of array = arg2
    add     ebx, [ebp + 8]  ; ebx = upper bound of array
    mov     ecx, [ebp + 16] ; ecx = search term = arg3

    .while:
    cmp     esi, ebx
    jae     .wend
    .if:
    cmp     [esi], ecx
    je      .wend
    inc     dword [edi]
    add     esi, 4
    jmp    .while
    .wend:
    cmp     esi, ebx
    jae     .exit
    mov     eax, [edi]
    .exit:
    
    pop     edi
    pop     esi
    pop     ebx

    ; mov     esp, ebp        ; deallocate local var
    ; pop     ebp             ; restore caller's base pointer
    leave
    ret
    
; End  array_search -------------------------------------------------------

;------------------------------------------------------------------------------
print_nl:
;
; Description: print new line
; Receives: <argument list>
; Returns:  <return list>
; Requires: <requirements>
; Notes:    <notes>
; Algo:     <algorithm>
;-------------------------------------------------------------------------------

    ; mov     eax, NL_STR
    push    NL_STR
    call    printstr
    add     esp, 4

    ret
    
; End  <procedure_label> -------------------------------------------------------

;------------------------------------------------------------------------------
exit:
;
; Description: exit the program
; Receives: arg1 = exit code
; Returns:  <return list>
; Requires: <requirements>
; Notes:    arg1 = zero indicate "No Errors" or one inndicates "With Errors"
; Algo:     <algorithm>
;-------------------------------------------------------------------------------

    push    ebp
    mov     ebp, esp

    mov     eax, 1      ; invoke SYS_EXIT (kernel opcode 1)
    mov     ebx, [ebp + 8]      ; return 0 status on exit - 'No Errors'
    int     80h
    ; leave
    ; ret
    
; End  <procedure_label> -------------------------------------------------------

;-------------------------------------------------------------------------------
; constant
NL:         equ 0x0a        ; a newline character
NL_SZ:      equ $ - NL      ; size of newline character
NULL:       equ 0x00        ; a zero character
TRUE:       equ 0x01        ; true = 1
FALSE:      equ 0x00        ; false = 0

RANDC1:     equ 1103515245
RANDC2:     equ 12345
RANDC3:     equ 65536
RANDC4:     equ 32768
RAND_MAX:   equ RANDC4 - 1
RD_Mode:      equ 0
WR_Mode:    equ 1
RD_WR_Mode: equ 2
ALL_PERM:   equ 0o777

section     .bss

buff_sz:    equ 20
buff:       resb buff_sz

section     .data

next:       dd 1
NL_STR:     db " ",0x0a, NULL

buff_comma:     db ","
buff_space:     db " "
buff_op_brace:  db "{"
buff_cl_brace:  db "}"
; End constant------------------------------------------------------------------