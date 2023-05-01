

; character conversion
; 
;-------------------------------------------------------------------------------
extern  tolower
;
; Description: Convert uppercase alphabet character to lowercase alphabet character
; Receives: arg1 = lowercase alphabet character
; Returns:  nothing
; Requires: nothing
; Notes:    It does nothing if not lowercase alphabet character
; Algo:     none
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
extern  toupper
;
; Description: Convert lowercase alphabet character to uppercase alphabet character
; Receives: arg1 = single character
; Returns:  EAX = uppercase alphabet character
; Requires: nothing
; Notes:    It does nothing if not lowercase alphabet character
; Algo:     none
;-------------------------------------------------------------------------------

; character validations
; 
;-------------------------------------------------------------------------------
extern  isalpha
;
; Description: check if character is alphabetic
; Receives: arg1 = character
; Returns:  EAX = TRUE if alphabetic, FALSE otherwise
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
extern  isdigit
;
; Description: check if character is decimal digit character
; Receives: arg1 = character
; Returns:  EAX = TRUE if numeric, FALSE otherwise
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
extern  islower
;
; Description: check if character is lowercase alphabetic character
; Receives: arg1 = character
; Returns:  EAX = TRUE if lowercase, FALSE otherwise
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------

;-------------------------------------------------------------------------------
extern  isupper
;
; Description: check if character is uppercase alphabetic character
; Receives: arg1 = character
; Returns:  EAX = TRUE if uppercase, FALSE otherwise
; Requires: nothing
; Notes:    none
; Algo:     none
;-------------------------------------------------------------------------------