.code32
.extern handler0
.extern handler1

.global irq0
.global irq1
.global irq2
.global irq3
.global irq4
.global irq5
.global irq6
.global irq7
.global irq8
.global irq9
.global irq10
.global irq11
.global irq12
.global irq13
.global irq14
.global irq15

irq0:
	push %eax
	movb $0x20, %al
	outb %al, $0x20
	outb %al, $0xA0
	pop %eax
	iret

irq1:
	call mul
	push %eax
	movb $0x20, %al
	outb %al, $0x20
	outb %al, $0xA0
	pop %eax
	iret

irq2:
	push %eax
	movb $0x20, %al
	outb %al, $0x20
	outb %al, $0xA0
	pop %eax
	iret

irq3:
	push %eax
	movb $0x20, %al
	outb %al, $0x20
	outb %al, $0xA0
	pop %eax
	iret

irq4:
	push %eax
	movb $0x20, %al
	outb %al, $0x20
	outb %al, $0xA0
	pop %eax
	iret

irq5:
	push %eax
	movb $0x20, %al
	outb %al, $0x20
	outb %al, $0xA0
	pop %eax
	iret

irq6:
	push %eax
	movb $0x20, %al
	outb %al, $0x20
	outb %al, $0xA0
	pop %eax
	iret

irq7:
	push %eax
	movb $0x20, %al
	outb %al, $0x20
	outb %al, $0xA0
	pop %eax
	iret

irq8:
	push %eax
	movb $0x20, %al
	outb %al, $0x20
	outb %al, $0xA0
	pop %eax
	iret

irq9:
	push %eax
	movb $0x20, %al
	outb %al, $0x20
	outb %al, $0xA0
	pop %eax
	iret

irq10:
	push %eax
	movb $0x20, %al
	outb %al, $0x20
	outb %al, $0xA0
	pop %eax
	iret

irq11:
	push %eax
	movb $0x20, %al
	outb %al, $0x20
	outb %al, $0xA0
	pop %eax
	iret

irq12:
	push %eax
	movb $0x20, %al
	outb %al, $0x20
	outb %al, $0xA0
	pop %eax
	iret

irq13:
	push %eax
	movb $0x20, %al
	outb %al, $0x20
	outb %al, $0xA0
	pop %eax
	iret

irq14:
	push %eax
	movb $0x20, %al
	outb %al, $0x20
	outb %al, $0xA0
	pop %eax
	iret

irq15:
	push %eax
	movb $0x20, %al
	outb %al, $0x20
	outb %al, $0xA0
	pop %eax
	iret
