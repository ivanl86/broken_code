extern copy_int_array
extern sum_int_array
extern factorial
extern printstr
extern get_input
extern strlen
extern atoi
extern itoa
extern swap
extern swap_xor
extern srand
extern rand
extern current_time
extern print_nl
extern is_even
extern array_search
extern strcopy
extern to_lower
extern to_upper
extern get_uint
extern print_uint
extern getchar
extern printchar
extern print_int_array
extern exit
extern file_open
extern file_close
extern file_read
extern file_write
extern file_creat


; constant
extern NL
extern NULL
extern TRUE
extern FALSE
extern RAND_MAX

;------------------------------------------------------------------------------
; get_uint:
;
; Description: get an unsigned integer input from user
; Receives: nothing
; Returns:  EAX = unsigned int
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; print_uint:
;
; Description: print an int
; Receives: arg1 = value of int
; Returns:  nothing
; Requires: nothing
; Notes:    push value of int not address of int
; Algo:     none
;-------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; getchar:
;
; Description: get a char input from user
; Receives: nothing
; Returns:  EAX = character
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; printchar:
;
; Description: print a char
; Receives: arg1 = char
; Returns:  nothing
; Requires: nothing
; Notes:    push value of char not address of char
; Algo:     none
;-------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; copy_int_array:
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

;-------------------------------------------------------------------------------
; sum_int_array:
;
; Descriptions: Sums the integer (dwords) elements of an array
; Receives: arg1 = address of array
;           arg2 = number of elements
; Returns:  EAX = sum of the elements of the array
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; factorial:
;
; Description: calculates the factorialof an unsigned integer (N!)
; Receives: arg1 = receive on stack the value of n
; Returns:  EAX = n!
; Requires: <requirements>
; Notes:    <notes>
; Algo:     <algorithm>
;-------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; to_lower:
;
; Description: convert uppercase alphabet char to lowercase
; Receives: arg1 = address of string
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; to_upper:
;
; Description: convert lowercase alphabet char to uppercase
; Receives: arg1 = address of string
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; strcopy:
;
; Description: copy from one string to another
; Receives: arg1 = address of src string
;           arg2 = address of dst string
; Returns:  nothing
; Requires: nothing
; Notes:    assume dst string has correct length
; Algo:     none
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
; strlen:
;
; Description: Calculates the size of a null-termainated string
; Receives: arg1 = address of string on stack
; Returns:  EAX = size of string
; Requires: The string must be null-terminated
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
; printstr:
;
; Descriptions: Print a string
; Receives: arg1 = address of string
; Returns:  none
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; print_int_array:
;
; Description: print an array of dword unsigned integer
; Receives: arg1 = address of the array
;           arg2 = the number of element in the array
; Returns:  none
; Requires: nothing
; Notes:    Print out format: { a, b, c, d }
; Algo:     none
;-------------------------------------------------------------------------------

;--------------------------------------------------------------------------------
; get_input:
;
; Descriptions: Get a string input from the user
; Receives: arg1 = address of input buffer
;           arg2 = size of input buffer
; Returns:  none
; Requires: nothing
; Notes:    remove newline char if it exists and null terminate
; Algo:     none
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
; is_even:
;
; Description: Takes a value and return 1 if even or false otherwise
; Receives: arg1 = the value will be checked
; Returns:  EAX = TRUE or FALSE
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
; atoi:
;
; Description: convert null terminated representation of a unsigned integer to an unsigned integer
; Receives: arg1 = address of a NULL terminated string = EDX
; Returns:  EAX = converted unsigned integer value
; Requires: nothing
; Notes:    none
; Algo:     use horner's method
;-------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; itoa:
;
; Description: converts an unsigned integer to a null-terminated string representation
; Receives: arg1 = unsigned integer value = eax, last to push
;           arg2 = address of string buffer = edi, push before arg1
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
; swap:
;
; Description: Swap the 32bit values located at the addresses passed in as args
; Receives: EAX: address of first value (val1)
;           EBX: address of second value (val2)
; Returns:  <return list>
; Requires: <requirements>
; Notes:    The registers hold the addresses of two values to be swapped, not the values themselves
; Algo:     <algorithm>
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
; swap_xor:
;
; Description: Swap the 32bit values located at the addresses passed in as args
; Receives: EAX: address of first value (val1)
;           EBX: address of second value (val2)
; Returns:  <return list>
; Requires: <requirements>
; Notes:    The registers hold the addresses of two values to be swapped, not the values themselves
; Algo:     <algorithm>
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
; srand:
;
; Description: Seeds the value used by rand
; Receives: arg1 = seed value
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
; rand:
;
; Description: generates a random unsigned integer value
; Receives: nothing
; Returns:  EAX = a random unsigned integer value
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
; current_time:
;
; Description: 
; Receives: <argument list>
; Returns:  <return list>
; Requires: <requirements>
; Notes:    <notes>
; Algo:     <algorithm>
;-------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; array_search:
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

;------------------------------------------------------------------------------
; print_nl:
;
; Description: print new line
; Receives: <argument list>
; Returns:  <return list>
; Requires: <requirements>
; Notes:    <notes>
; Algo:     <algorithm>
;-------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; exit:
;
; Description: exit the program
; Receives: arg1 = exit code
; Returns:  <return list>
; Requires: <requirements>
; Notes:    arg1 = zero indicate "No Errors" or one inndicates "With Errors"
; Algo:     <algorithm>
;-------------------------------------------------------------------------------
