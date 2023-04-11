Write a boot loader - to load a particular OS. OS image – code to access from BIOS to loading the OS

Download and install NASM (Netwide Assembler) and QEMU from
http://www.osdever.net/downloads/assemblers/nasm-0.98.35-1.i386.rpm
sudo apt-get install nasm
sudo apt-get install qemu

create a file firstBootLoader.asm

[BITS 16]       ;tell the assembler that its a 16 bit code
[ORG 0x7C00]    ;Origin, tell the assembler that where the code will
;be in memory after it is been loaded
JMP $           ;infinite loop
TIMES 510 - ($ - $$) db 0       ;fill the rest of sector with 0
DW 0xAA55                       ; add boot signature at the end of bootloader

Compile the program
nasm firstBootLoader.asm -f bin -o boot.bin

Run using the emulator
qemu-system-x86_64 -drive file=boot.bin,index=0,media=disk,format=raw

Create a floppy image using
dd if=boot.bin bs=512 of=floppy1.img

Attach the floppy image to the Virtual machine and boot. You should see a blank screen

Create 2nd Bootloader that prints ‘A’ on the screen

Code saved in secondBootLoader.asm
bits 16
org 0x7c00
boot:
	mov si,hello
	mov ah, 0x0e
.loop:
	lodsb
	or al,al
	jz halt
	int 0x10
	jmp .loop
halt:
	cli
	hlt
hello: db "A",0
times 510 - ($-$$) db 0
dw 0xaa55

Compile the program
nasm secondBootLoader.asm -f bin -o boot2.bin

Run using the emulator
qemu-system-x86_64 -drive file=boot2.bin,index=0,media=disk,format=raw

Code saved in secBootLoader2.asm( Another code for secondboot loader)

[BITS 16]       ;Tells the assembler that its a 16 bit code
[ORG 0x7C00]    ;Origin, tell the assembler that where the code will
;be in memory after it is been loaded
MOV AL, 65
CALL PrintCharacter
JMP $           ;Infinite loop, hang it here.
PrintCharacter: ;Procedure to print character on screen
	    ;Assume that ASCII value is in register AL
MOV AH, 0x0E    ;Tell BIOS that we need to print one charater on screen.
MOV BH, 0x00    ;Page no.
MOV BL, 0x07    ;Text attribute 0x07 is lightgrey font on black background
INT 0x10        ;Call video interrupt
RET             ;Return to calling procedure
TIMES 510 - ($ - $$) db 0       ;Fill the rest of sector with 0
DW 0xAA55                       ;Add boot signature at the end of bootloader
