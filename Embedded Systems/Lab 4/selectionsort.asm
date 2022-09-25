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
	LDR R0, =SRC
	LDR R1, =DST
	MOV R3, #10
loop  LDR R2, [R0], #4
	STR R2, [R1], #4
	SUB R3, #1
	TEQ R3, #0
	BNE loop
	
	 
	ldr r1,=DST
	add r9,r1,#40
	add r11,r1,#36
	ldr r5,=DST
	mov r3,#9
	
oloop
	
	mov r4,r5
	add r6,r5,#4
iloop
	ldr r7,[r6],#4
	ldr r8,[r4]
	cmp r7,r8
	bcs next
	sub r6,#4
	mov r4,r6
next 
	cmp r6,r9
	bcc iloop
	
	
	
	
	ldr r12,[r5]
	str r8,[r5],#4
	str r12,[r4]
	
	
	
	
	
	
	subs r3,#1
	cmp r3,#0
	bne oloop
STOP B STOP		
SRC DCD 0x3, 0x5, 0x1, 0x4, 0x2, 0xA, 0xF, 0xE, 0xC, 0x6
	AREA DATASEG, DATA, READWRITE
DST DCD 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	END