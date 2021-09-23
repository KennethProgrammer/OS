all:
	as --32 -o main.o main.s
	ld -mi386pe -Ttext 0x7c00 -o main.exe main.o
	objcopy -j .text -O binary main.exe boot.bin
	rm main.o
	rm main.exe
	gcc -m32 -nostdlib -mno-red-zone -fno-ident -fno-leading-underscore -fno-pie -c kernel.c
	as --32 -o irq.o irq.s
	ld -melf_i386 -Ttext 0x1 -o main.exe kernel.o irq.o
	objcopy -O binary main.exe kernel.bin
	python script.py
	rm main.exe
	rm *.o

run:
	copy /b boot.bin+kernel.bin os.bin
	del kernel.bin
	del boot.bin
	qemu-system-i386 os.bin

del:
	del c:\users\kenneth\_viminfo
	del *.o
	del *.bin
