	AREA RESET, DATA, READONLY
    EXPORT __Vectors
__Vectors  
    DCD 0x40001000
	DCD Reset_Handler
	ALIGN
	AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=SRC
	LDR R9,=DST
	LDR R2,[R0]
	MOV R1,#2
UP	AND R3,R2,#0xF
	CMP R3,#0xA
	BCC DOWN
	ADD R3,#0x07
DOWN
	ADD R3,#0x30
	ORR R4,R3
	ROR R4,#8
	LSR R2,#4
	SUBS R1,#1
	BNE UP
	ROR R4,#16
	STR R4,[R9]
STOP
    B STOP
SRC DCD 0x3A
	AREA data1,DATA,READWRITE
DST DCD 0
	END 