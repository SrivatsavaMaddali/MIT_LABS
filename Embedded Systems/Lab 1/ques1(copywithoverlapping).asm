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
	
	mov R11,#10
	LDR R0,=SRC
	LDR R10,=DST
down
	LDR R3,[R0],#4
	STR R3,[R10],#4
	
	SUBS R11,#1
	bne down
	
	MOV R0,#10
	LDR R1,=DST
	ADD R1,#36
	LDR R2,=DST
	ADD R2,#56
UP
	LDR R4,[R1],#-4
	STR R4,[R2],#-4
	SUBS R0,#1
	BNE UP

STOP

	B STOP

SRC DCD 0x1234,0x2234,0x3234,0x4234,0x5234,0x6234,0x7234,0x8234,0x9234,0x10234
	AREA data1,DATA, READWRITE
DST DCD 0

	END
	