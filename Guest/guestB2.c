#include <stdint.h>

static void outb(uint16_t port, uint8_t value) {
	asm("outb %0,%1" : /* empty */ : "a" (value), "Nd" (port) : "memory");
}

void
__attribute__((noreturn))
__attribute__((section(".start")))
_start(void) {

	/*
		INSERT CODE BELOW THIS LINE
	*/
	uint16_t port = 0xE9;
    uint8_t character = 'b';

	for (uint32_t i = 0; i < 20; i++){
        outb(0xE9, character);
        for (uint32_t j = 0; j < 100000000; j++);
    }
    outb(0xE9, '\n');
	/*
		INSERT CODE ABOVE THIS LINE
	*/

	for (;;)
		asm("hlt");
}