	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10000000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
	
Reset_Handler
	LDR R0,=SRC
	LDR R1,=DST
	mov r11,#10
	
loop LDR R9,[R0],#4
	 STR R9,[R1],#4
	 SUB R11,#1
	 TEQ R11,#0
	 BNE loop
	
	mov r6,#9
	mov r7,#8
oloop
	ldr r3,=DST
iloop
	ldr r4,[r3]
	ldr r5,[r3,#4]
	cmp r5,r4
	bhs next
	mov r8,r5
	str r4,[r3,#4]
	str r8,[r3]
next 
	add r3,#4
	subs r6,#1
	bne iloop
	mov r6,#9
	subs r7,#1
	bne oloop
STOP B STOP		
SRC DCD 0x3, 0x5, 0x1, 0x4, 0x2, 0xA, 0xF, 0xE, 0xC, 0x6
	AREA DATASEG, DATA, READWRITE
DST DCD 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	END
