%macro ISR_NOERRCODE 1
  global isr_%1
  isr_%1:
    CLI                         ; Disable interrupts firstly.
    PUSH BYTE 0                 ; Push a dummy error code.
    PUSH %1                ; Push the interrupt number.
    JMP ISR_CommonStub         ; Go to our common handler code.
%endmacro

; This macro creates a stub for an ISR which passes it's own
; error code.
%macro ISR_ERRCODE 1
  GLOBAL isr_%1
  isr_%1:
    CLI                         ; Disable interrupts.
    PUSH %1                ; Push the interrupt number
    JMP ISR_CommonStub
%endmacro

%macro IRQ 2
GLOBAL irq_%1
irq_%1:
	CLI
	PUSH BYTE 0
	PUSH BYTE %2
	JMP IRQ_CommonStub
%endmacro

ISR_NOERRCODE 	0
ISR_NOERRCODE 	1
ISR_NOERRCODE 	2
ISR_NOERRCODE 	3
ISR_NOERRCODE 	4
ISR_NOERRCODE 	5
ISR_NOERRCODE 	6
ISR_NOERRCODE 	7
ISR_ERRCODE   	8
ISR_NOERRCODE 	9
ISR_ERRCODE   	10
ISR_ERRCODE   	11
ISR_ERRCODE   	12
ISR_ERRCODE   	13
ISR_ERRCODE   	14
ISR_NOERRCODE 	15
ISR_NOERRCODE 	16
ISR_NOERRCODE 	17
ISR_NOERRCODE 	18
ISR_NOERRCODE 	19
ISR_NOERRCODE 	20
ISR_NOERRCODE 	21
ISR_NOERRCODE 	22
ISR_NOERRCODE 	23
ISR_NOERRCODE 	24
ISR_NOERRCODE 	25
ISR_NOERRCODE 	26
ISR_NOERRCODE 	27
ISR_NOERRCODE 	28
ISR_NOERRCODE	  29
ISR_NOERRCODE 	30
ISR_NOERRCODE 	31
ISR_NOERRCODE   150

IRQ	0, 32
IRQ	1, 33
IRQ	2, 34
IRQ	3, 35
IRQ	4, 36
IRQ	5, 37
IRQ	6, 38
IRQ	7, 39
IRQ	8, 40
IRQ	9, 41
IRQ	10, 42
IRQ	11, 43
IRQ	12, 44
IRQ	13, 45
IRQ	14, 46
IRQ	15, 47

EXTERN FaultHandler ; No longer used??

; This is our common ISR stub. It saves the processor state, sets
; up for kernel mode segments, calls the C-level fault handler,
; and finally restores the stack frame.
EXTERN isr_handler  ; In ISR.c
ISR_CommonStub:
    PUSHA                    ; Pushes edi,esi,ebp,esp,ebx,edx,ecx,eax

    MOV AX, DS               ; Lower 16-bits of eax = ds.
    PUSH EAX                 ; save the data segment descriptor

    MOV AX, 0x10  ; load the kernel data segment descriptor
    MOV DS, AX
    MOV ES, AX
    MOV FS, AX
    MOV GS, AX

    CALL isr_handler

    POP EBX        ; reload the original data segment descriptor
    MOV DS, BX
    MOV ES, BX
    MOV FS, BX
    MOV GS, BX

    POPA                     ; Pops edi,esi,ebp...
    ADD ESP, 8     ; Cleans up the pushed error code and pushed ISR number
    STI
    IRET

[EXTERN irq_handler]
IRQ_CommonStub:
	  PUSHA
	
	  MOV AX, DS
	  PUSH EAX
	
	  MOV AX, 0x10
	  MOV DS, AX
	  MOV ES, AX
	  MOV FS, AX
	  MOV GS, AX
	
	  CALL irq_handler
	
	  POP EBX
	  MOV DS, BX
	  MOV ES, BX
	  MOV FS, BX
	  MOV GS, BX
	
	  POPA
	  ADD ESP, 8
	  STI
	  IRET

[GLOBAL jump_usermode]
EXTERN test_user_function
jump_usermode:
  MOV ax, 0x23
  MOV ds, ax
  MOV es, ax
  MOV fs, ax
  MOV gs, ax
  
  MOV eax, esp
  PUSH 0x23
  PUSH eax
  PUSHF
  PUSH 0x1B
  PUSH test_user_function
  IRET
