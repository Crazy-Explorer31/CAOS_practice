* Makefile яблоко
	* $@ = target file
	* $< = first dependency
	* $^ = all dependencies


* QEMU
	> What is the shortcut key for exit QEMU?

	>To exit, either close the VGA window or press Ctrl-c or Ctrl-a x in your terminal. make
	>qemu-nox. Like make qemu, but run with only the serial console. To exit, press Ctrl-a x.


	```
	Ctrl-Alt-f
	Toggle full screen

	Ctrl-Alt-+
	Enlarge the screen

	Ctrl-Alt--
	Shrink the screen

	Ctrl-Alt-u
	Restore the screen’s un-scaled dimensions

	Ctrl-Alt-g
	Toggle mouse and keyboard grab.
	```


* BIOS (ROM)  
	* POST
	* load MBR (bootloader) from 0 block to 0x7c00
	* library of primitive input/ouptut functions

* Memory maped registers
	```
	0x000000 RAM

	0xFFFFFA Video card

	0xFFFFFF

	mov $4, 0x000000   --> RAM
	mov $4, 0xFFFFFA   --> Video Card
	```

* Port maped registers
	```
	1 -- Video Card
	2 -- Key Board

	in 2, $ax
	out $4, 1
	```

* VGA (текстовый режим) https://wiki.osdev.org/VGA_Hardware#Port_0x3C4.2C_0x3CE.2C_0x3D4

	* memory maped и port maped

	> The data register will hold the low byte if the control register is set to 0x0f, and the 
	> high byte if the value 0x0e is used.

	>The memory offset is twice the cursor offset, because each position in the text grid is 
	>represented by 2 bytes, one for the character and one for color information.

	```
	vga
	--------------------
	[      ][       ]  port (перемещать курсок)
	 ctrl r   data r

	80 строк  x 25 столбцов

	[code,color|                                                          ]
	  1b   1b

	80x25x2
	--------------------
	```

	* перевести курсор в позицию 0x11aa
	```
	out
	[     0x0e][  0x11     ]  
	ctrl r     data r

	out
	[     0x0f][  0xaa     ]  
	ctrl  r    data r
	```


* Яблоко

	```
	unsigned char port_byte_in(unsigned short port) {
	    unsigned char result;
	    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
	    return result;
	}

	void port_byte_out(unsigned short port, unsigned char data) {
	    __asm__("out %%al, %%dx" : : "a" (data), "d" (port));
	}
	```

	* https://stackoverflow.com/questions/38410829/why-cant-find-the-insl-instruction-in-x86-document


* Драйвер клавиатуры

	> When a key is pressed, the microcontroller stores the relevant information
	> inside the I/O port 0x60 and sends an interrupt request IRQ 1
	> to the programmable interrupt controller (PIC).

* Keyboard. Scan codes https://www.win.tue.nl/~aeb/linux/kbd/scancodes-1.html

	>  Each key press and key release produces between 0 and 6 scancodes.

	> Below I'll only mention the scancode for key press (`make'). The scancode for key release (`break') is
	> obtained from it by setting the high order bit (adding 0x80 = 128). Thus, Esc press produces
	> scancode 01, Esc release scancode 81 (>hex).
	```
	press_code = x
	release_code = x + 0x80
	``


```
