.code32
.extern handler0
.extern handler1
.extern end

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
	outb $0x20, $0x20
	outb $0x20, $0xA0
	iret

irq1:
	call handler1
	outb $0x20, $0x20
	outb $0x20, $0xA0
	iret

irq2:
	call end
	iret

irq3:
	call end
	iret

irq4:
	call end
	iret

irq5:
	call end
	iret

irq6:
	call end
	iret

irq7:
	call end
	iret

irq8:
	call end
	iret

irq9:
	call end
	iret

irq10:
	call end
	iret

irq11:
	call end
	iret

irq12:
	call end
	iret

irq13:
	call end
	iret

irq14:
	call end
	iret

irq15:
	call end
	iret
