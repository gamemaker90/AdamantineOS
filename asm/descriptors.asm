; Load up the Global Descriptor Table:
[global gdt_flush]
gdt_flush:
	mov eax, [esp + 4]
	lgdt [eax]

	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	MOV ss, ax
	jmp 0x08:.flush
.flush:
	ret

; Load up the Interrupt Descriptor Table:
[global idt_flush]
idt_flush:
	mov eax, [esp + 4]
	lidt [eax]
	ret

; Load up the Task State Segment:
[global tss_flush]
tss_flush:
    mov ax, 0x2B

    ltr ax
    ret
