   AREA |.text|, CODE, READONLY

new_mas_positiv_asm	PROC
	EXPORT new_mas_positiv_asm
    ; R0 = *array
    ; R1 = size(array)
    ; R2 = *new_array
    ; R3 = *AVG_result
	MOV R4, #0	; i = 0
	MOV R5, #0	; n = 0
    
    MOV R6, #4
	MUL R1, R6
    
fun_new_mas_positiv
	CMP R4,R1
	BLT fun_new_mas_positiv_label
	B exit_new_mas_positiv
    
fun_new_mas_positiv_label
	LDR R6, [R0, R4]
    ADD R4, #8
    CMP R6, #0
    BLE fun_new_mas_positiv
    STR R6, [R2, R5]
    ADD R5, #4
	B fun_new_mas_positiv
    
exit_new_mas_positiv
	BX LR
	ENDP

finding_AVG_asm	PROC
	EXPORT finding_AVG_asm
    ; R0 = *array
    ; R1 = size(array)
    ; R2 = *new_array
    ; R3 = *AVG_result
	
	PUSH {R0-R3, LR}
	BL new_mas_positiv_asm
	POP {R0-R3, LR}

	MOV R4, #0	; i = 0
    
fun_finding_AVG
    CMP R4, R5
    BLT fun_finding_AVG_label
    UDIV R8, R5
    MOV R0, R8
    STR R0, [R3]
	B exit_finding_AVG_asm
    
fun_finding_AVG_label
	LDR R6, [R2, R4]
    ADD R4, #4
    MOV R7, #4
    MUL R6, R7
    ADD R8, R6
	B fun_finding_AVG

exit_finding_AVG_asm
	BX LR
	ENDP
        
	END	