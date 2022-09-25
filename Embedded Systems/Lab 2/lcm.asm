    AREA RESET,DATA,READONLY
    EXPORT __Vectors
__Vectors
    DCD 0x40001000;
    DCD Reset_Handler;
    ALIGN
    AREA mycode,CODE,READONLY
    ENTRY
    EXPORT Reset_Handler
Reset_Handler
    LDR R1,=SRC1
    LDR R2,=SRC2
    LDR R3,=LCM

LOOP
    CMP R1,R2
    BEQ FIN
    BCC DOWN
    BCS UP
                                                                         
DOWN
    SUBS R2,R1
    BNE LOOP

UP
    SUBS R1,R2
     BNE LOOP

FIN	LDR R9,=SRC1
    LDR R10,=SRC2
    MUL R11,R9,R10
	UDIV R12,R11,R1
    STR R12,[R3]

STOP
    B STOP

SRC1 EQU 12
SRC2 EQU 15

    AREA data1,DATA, READWRITE
LCM DCD 0
    END     