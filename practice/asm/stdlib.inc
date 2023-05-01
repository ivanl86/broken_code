extern  NO_ERROR

; Dynamic memory management
; 
;-------------------------------------------------------------------------------
extern  free
;
; Description: Deallocate memory on heap
; Receives: arg1 = memory address to deallocate
;           arg2 = memory size to deallocate
; Returns:  EAX = top of heap
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
extern  malloc
;
; Description: Allocate memory on heap
; Receives: arg1 = memory size to allocate
; Returns:  EAX = allocated memory address
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

; System
; 
;-------------------------------------------------------------------------------
extern  exit
;
; Description:
; Receives: nothing
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

; Pseudo-random generator
; 
;-------------------------------------------------------------------------------
extern  rand
;
; Description: Generate random unsigned integer
; Receives: nothing
; Returns:  EAX = random unsigned integer
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
extern  srand
;
; Description: Seeds pseudo-random generator
; Receives: arg1 = seed
; Returns:  nothing
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
extern  time
;
; Description: Get current time
; Receives: nothing
; Returns:  EAX = 32 bit time value
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------