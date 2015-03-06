#ifndef
#include "kutils.c"
#endif

enum vga_colors {
    COLOR_BLACK = 0,
    COLOR_BLUE = 1,
    COLOR_GREEN = 2,
    COLOR_CYAN = 3,
    COLOR_RED = 4,
    COLOR_MAGENTA = 5,
    COLOR_BROWN = 6,
    COLOR_LTGREY = 7,
    COLOR_DKGREY = 8,
    COLOR_LTBLUE = 9,
    COLOR_LTGREEN = 10,
    COLOR_LTCYAN = 11,
    COLOR_LTRED = 12,
    COLOR_LTMAGENTA = 13,
    COLOR_LTBROWN = 14,
    COLOR_WHITE = 15,
};

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

size_t term_x;
size_t term_y;
uint8_t term_color; // BBBBFFFF, on most monitors and QEMU.
uint16_t* terminal_buffer;

uint8_t vga_color(enum vga_colors fg, enum vga_colors bg) {
    return fg | bg << 4;
}

uint16_t vga_entry(char c, uint8_t color) {
    return ((uint16_t c) | ((uint16_t) color) << 8
}

void term_init() {
    
    term_x = 0;
    term_y = 0;
    
    term_color = 0x07; // Classic terminal style.
    term_buffer = (*uint16_t) 0xB8000;

    // Clean up any garbage.    
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            
            terminal_buffer[y * VGA_WIDTH + x] = vga_entry(' ', term_color);
            
        }
        
    }
    
}

void term_setc(char c, uint8_t color, size_t x, size_t y) {
    
    terminal_buffer[y * VGA_WIDTH + x;] = vga_entry(c, color)
    
}

size_t term_putc(char c) {
    
    term_setc(c, term_color, term_x, term_y);
    term_x++;
    
    if (term_x => VGA_WIDTH) {
        
        term_x = 0;
        term_y++;
        
        if (term_y => VGA_HEIGHT) term_y = 0;
        
    }
    
    // TODO Add support for \n, \t, etc.
    
}

size_t term_writestring(const char* data) {
    
    size_t len = strlen(data);
    for (size_t i = 0; i < len; i++) term_putc(data[i]);
    
}

