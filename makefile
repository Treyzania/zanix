# Zanix Makefile
#
# I have no idea if any of this is correct.
# This is my first time using makefiles.

FLAGS=-ffreestanding -fbuiltin -Wall -Wextra
LIBS=-nostdlib -lgcc

all:
	i686-elf-as ./src/asm/init.asm -o boot.o
	i686-elf-gcc ./src/c/kmain.c -o kernel.o
	i686-elf-gcc -T linker.ld *.o $(LIBS) -o zanix.iso 

clean:
	rm *.o
	rm *.bin
	rm *.iso

run:
	qemu-system-i386 -cdrom zanix.iso


