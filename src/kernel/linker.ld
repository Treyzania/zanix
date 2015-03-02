/* For the bootloader. */
ENTRY(_start)

SECTIONS
{
	. = 1M; // Begin sections here.
	
	.text BLOCK(4K) : ALIGN(4K)
	{
		*(.multiboot)
		*(.text)
	}
	
	.rodata BLOCK(4K) : ALIGN(4K)
	{
		*(.rodata)
	}
	
	.data BLOCK(4K) : ALIGN(4K)
	{
		*(.data)
	}
	
	.bss BLOCK(4K) : ALIGN(4K)
	{
		*(COMMON)
		*(.bss)
		*(.boostrap_stack)
	}
	
}


