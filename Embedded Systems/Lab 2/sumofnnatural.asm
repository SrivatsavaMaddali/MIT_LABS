    AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x40001000;
	DCD Reset_Handler;
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
    LDR R0,=N
    LDR R3,=DST

    LDR R1,[R0]
    MLA R4,R1,R1,R1

    MOV R5,#2
UP  SUB R4,R5
    ADD R6,#1
    CMP R4,R5
    BCS UP
    STR R6,[R3]

STOP
    B STOP

N DCD 11
	AREA data1,DATA, READWRITE
DST DCD 0

	END