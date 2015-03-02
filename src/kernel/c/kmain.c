// Zanix -- Main kernel source file.

#if !defined(__cplusplus)
#include <stdbool.h> // In case we decide to start using C++.
#endif

#include <stddef.h>
#include <stdint.h>

#include "kutils.c"
#include "terminal.c"

#if !defined(__cplusplus)
extern "C" // Use C linking behaviour.
#endif

void kmain(void) {
    
    // Yay!
    term_init();
    term_writestring("Hello world!\n");
    
}

