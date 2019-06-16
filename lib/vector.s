	AREA Vect,CODE,READONLY
	CODE32
	ENTRY
   	IMPORT  sysIrqHandler
 	IMPORT  sysFiqHandler
 	IMPORT __main
 	GLOBAL reset_addr
 	GLOBAL OSTimeTick
reset_addr       
    b reset_handler       ;reset 
    NOP            ;undefined instruction 
    NOP            ;swi 
    NOP            ;prefetch abort 
    NOP            ;data abort 
    NOP            ;reserve 
    b ARM_ExceptIrqHndlr
    b ARM_ExceptFiqHndlr
    SPACE 100
reset_handler
	MRC p15,0,R0,c1,c0,0
	BIC R0,R0,#0x2000
	MCR p15,0,R0,c1,c0,0
    MRS R0,CPSR                   ;CPSR->R0
    ;BIC R0,R0,#0xc0               ;enable irq and fiq
    MSR CPSR_c,R0                 ;R0->CPSR
	bl __main
ARM_ExceptIrqHndlr
	SUB lr,lr,#4
	STMFD  sp!, {r0-r4,r12,lr}
	MRS    r0, spsr
	STR    r0, [sp, #-4]!	
	bl sysIrqHandler
	LDR    r1, [sp], #4
	MSR    spsr_csxf, r1
	LDMFD  sp!, {r0-r4,r12,pc}^
ARM_ExceptFiqHndlr
	SUB lr,lr,#4
	STMFD  sp!, {r0-r4,r12,lr}
	MRS    r0, spsr
	STR    r0, [sp, #-4]!	
	bl sysFiqHandler
	LDR    r1, [sp], #4
	MSR    spsr_csxf, r1
	LDMFD  sp!, {r0-r4,r12,pc}^
OSTimeTick
	MOV pc,lr
    END