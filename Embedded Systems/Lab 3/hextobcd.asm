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
	ldr r12,=DST
	LDR R1,[R0]
	mov r2,#0x0a
	mov r7,#8
up  cmp r1,r2
    BLCS conv
	orr r6,r1
	mov r1,r3
	mov r3,#0
	ror r6,#4
	subs r7,#1
	bne up
conv cmp r1,#0
	 beq close
	 sub r1,r2
	 add r3,#1
	 cmp r1,r2
	 bhs conv
	 bx lr
close 
	str r6,[r12]
STOP
    B STOP
SRC DCD 0xFF
	AREA data1,DATA,READWRITE
DST DCD 0
	END 