gdt_des:
	.word gdt_end - gdt_start - 1
	.long gdt_start

gdt_start:
    .long 0
    .long 0

gdt_code_segment:
    .word 0xffff
    .word 0x0000
    .byte 0x00
    .byte 0b10011010
    .byte 0b11001111
    .byte 0x00

gdt_data_segment:
    .word 0xffff
    .word 0x0000
    .byte 0x00
    .byte 0b10010010
    .byte 0b11001111
    .byte 0x00

gdt_end:

.equ codeseg, (gdt_code_segment - gdt_start)
.equ dataseg, (gdt_data_segment - gdt_start)

load_gdt:
	#mov $0x13, %ax
	#int $0x10
	cli
	lgdt gdt_des
	mov %cr0, %eax
    	or $0x1, %eax
    	mov %eax, %cr0
	jmp $codeseg, $entry32
