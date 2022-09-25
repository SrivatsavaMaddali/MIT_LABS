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
	MOV R0,#0x123
	MOV R1,#0123
	MOV R2,#33
	MOV R9,#2_1010
	ADD R2,R1
	LDR R4,=0x22222222
	LDR R0,=SRC
	MOV R2,#NUM
	LDR R3,[R0]
	LDR R4,[R0,#4]
	LDR R5,[R0,#8]
	LDR R6,[R0,#12]
	LDR R10,=DST
	STR R3,[R10]
	STR R4,[R10,#4]
	STR R5,[R10,#8]
	STR R6,[R10,#12]
STOP
	B STOP
NUM EQU 10
SRC DCD 8,0X123456,34567891,0XABCDEF12
	AREA data1,DATA, READWRITE
DST DCD 0,0
	END
