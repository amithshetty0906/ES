	AREA EX,CODE,READWRITE
	  ENTRY
START MOV r5,#0X0000000D
	  LDR r0,=Array
	  LDR r6,=ArrayEnd
	  LDR r2,[r0]
LOOP  CMP r5,#0
	  BEQ STOP
	  LDR r3,[r0,#4]!
	  ADD r5,r5,#-1
	  CMP r3,r2
	  BMI LOOP
	  MOV r4,r2
	  MOV r3,r2
	  B   LOOP
STOP  B   STOP
Array
		  DCD &1,&2,&3,&4,&5,&6,&7
ArrayEnd
	END