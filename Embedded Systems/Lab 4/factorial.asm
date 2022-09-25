;MAP 0x0FFFFF00,0x0FFFFFFF READ WRITE ---------> write this in the view command window while debugging if getting any errors
;The result is in hex format
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
	mov r0,#5
	ldr r9,=DST
	bl fact
    str r0,[r9]
	B STOP
fact push {r0,r14}
	 sub r0,#1
	 cmp r0,#1
	 blne fact
	 pop {r1,r14}
	 mul r0,r1
	 bx lr
STOP B STOP
	AREA DATASEG,DATA,READWRITE
DST DCD 0
	END