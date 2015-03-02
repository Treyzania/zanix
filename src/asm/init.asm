# Sets		...
.set ALIGN,     1<<0
.set MEMINFO,   1<<1
.set FLAGS,     ALIGN | MEMINFO
.set MAGIC,     0x1BADB002 # Lets multiboot find the header.
.set CHECKSUM,  -(MAGIC + FLAGS)

# Multiboot header.
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# Stack init
.section .bootstrap_stack, "aw", @nobits
stack_bottom:
	.skip 16384 # 16k stack.
stack_top:

# Actually close to entry point.
.section .text
.global _start
.type _start, @function

_start:
	
	# Kernel mode here.
	movl $stack_top, %esp	
	
	# To C!
	call kmain
	
	# If kmain returns.
	cli
	hlt
	
.Lhang
	jmp .Lhang

# Voodoo.
.size _start, . - _start
