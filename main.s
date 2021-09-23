.code16
.global _start

_start:
	jmp read_disk

.include "read_disk.s"
.include "gdt.s"


.code32
entry32:
	movw $0x10, %ax
    	movw %ax, %ds
    	movw %ax, %es
    	movw %ax, %fs
    	movw %ax, %gs
    	movw %ax, %ss

	mov $(0x1+(40*512)+1024) , %ebp
	mov $(0x1+(40*512)+1024) , %esp
	jmp 0x1

.fill 510-(.-_start), 1, 0
.word 0xAA55
