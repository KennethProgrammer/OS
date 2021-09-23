read_disk:
	mov $0x02, %ah	 #Read
	mov $0x1, %bx #Start address of kernel
	mov $40, %al	 #Number of sectors
	mov $0x80, %dl 	 #Hard Disk Drive
	mov $0x00, %ch	 #Cylinder 0
	mov $0x00, %dh	 #Head 0
	mov $0x02, %cl	 #Sector 2 onwords
	int $0x13
	jmp load_gdt
