	;This program stores in DST 0x0000000F if number is present, 0x00000007 if number not present
	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10000000
	DCD Reset_Handler
	ALIGN
	AREA mycode,CODE,READONLY
	ENTRY
	EXPORT  Reset_Handler
Reset_Handler
	ldr r0,=SRC
	ldr r1,=num
	ldr r5,[r1]
	ldr r2,=DST
	mov r7,#0x07
	mov r3,#10
	b loop
notfound 
	str r7,[r2]
	b STOP
found mov r6,#0x0f
	  str r6,[r2]
	  b next
	  
loop ldr r4,[r0],#4
	 cmp r4,r5
	 beq found
next subs r3,#1
	 bne loop

	cmp r6,#0x0f
	bne notfound

	
STOP B STOP
SRC DCD 0x12345678,0x19635824,0x56598564,0x98658963,0x36985214,0x98745621,0x69587236,0x95968732,0x87456921,0x59843267
num dcd 0x8
	AREA DATASEG,DATA,READWRITE
DST DCD 0
	END