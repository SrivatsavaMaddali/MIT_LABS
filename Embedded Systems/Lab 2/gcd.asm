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
    LDR R3,=GCD

LOOP
    CMP R1,R2
    BEQ RESULT
    BCC DOWN
    BCS UP

DOWN
    SUBS R2,R1
    BNE LOOP

UP
    SUBS R1,R2
     BNE LOOP

RESULT
    STR R1,[R3]

STOP
    B STOP

SRC1 EQU 2
SRC2 EQU 4

    AREA data1,DATA, READWRITE
GCD DCD 0
    END     