
; uint io
; 
;-------------------------------------------------------------------------------
extern  getuint
;
; Description: Get unsigned integer from user input
; Receives: nothing
; Returns:  EAX = unsigned integer
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

;--------------------------------------------------------------------------------
extern  putuint
;
; Description: Print unsigned integer
; Receives: arg1 = unsigned integer
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------
; 
; End  uint io

; sint io
; 
;-------------------------------------------------------------------------------
extern  getsint
;
; Description: Get signed integer from user input
; Receives: nothing
; Returns:  EAX = signed integer
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
extern  putsint
;
; Description: Print signed integer
; Receives: nothing
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------
; 
; End  sint io

; char io
; 
;-------------------------------------------------------------------------------
extern  getchar
;
; Description: Get single character from user input
; Receives: nothing
; Returns:  EAX = single character
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
extern  putchar
;
; Description: Print single character
; Receives: arg1 = single character
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
extern  putcomma
;
; Description: Print comma character
; Receives: nothing
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
extern  putnl
;
; Description: print new line character
; Receives: nothing
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
extern  putspace
;
; Description: Print whitespace character
; Receives: nothing
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------
; 
; End  char io

; str io
; 
;-------------------------------------------------------------------------------
extern  getstr
;
; Description: Get string input from user
; Receives: arg1 = string buffer
;           arg2 = buffer size
; Returns:  nothing
; Requires: nothing
; Notes:    remove nl char if exits and null terminate
; Algo:     none
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
extern  putstr
;
; Description: Print string
; Receives: arg1 = string buffer
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------
; 
; End  str io

; file io
; 
;-------------------------------------------------------------------------------
extern  fread
;
; Description:Read from file
; Receives: arg1 = file descriptor
;           arg2 = string buffer
;           arg3 = buffer size
; Returns:  EAX = number of bytes have read
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
extern  fwrite
;
; Description: Write to file
; Receives: arg1 = file descriptor
;           arg2 = string buffer
;           arg3 = buffer size
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
extern  fclose
;
; Description: Close file
; Receives: arg1 = file descriptor
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
extern  fcreat
;
; Description: Create file
; Receives: arg1 = file path
; Returns:  EAX = file descriptor
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
extern  fopen
;
; Description: Open file
; Receives: arg1 = file path
;           arg2 = access mode { 0 = read, 1 = write, 2 = read and write }
; Returns:  EAX = file descriptor
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------
; 
; End  file io