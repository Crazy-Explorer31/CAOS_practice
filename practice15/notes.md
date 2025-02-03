* Прерывания
    * ISR gate (одна запись в таблице векторов прерывание IDT)

        > Offset. The 32 bit offset represents the memory address of the interrupt handler
        > within the respective code segment.
        >
        > Selector. The 16 bit selector of the code segment to jump to when invoking the
        > handler. This will be our kernel code segment.
        >
        > Type. 3 bits indicating the gate type. Will be set to 110 as we are defining an
        > interrupt gate.
        >
        > D. 1 bit indicating whether the code segment is 32 bit. Will be set to 1.
        >
        > DPL. 2 bits The descriptor privilege level indicates what privilege is required to
        > invoke the handler. Will be set to 00.
        >
        > P. 1 bit indicating whether the gate is active. Will be set to 1.
        >
        > 0. Some bits that always need to be set to 0 for interrupt gates.

    * IDT. Обработка прерывания. idt.c:

            * idt_gate_t
            * load_idt --> init_idt (заполнение таблицы idt адресами из массива default_handlers)
            * vector.S: заполнение массива default handlers функциями типа vecror_i (функции генерируются макросом)
            * vecror_i -- стандартный код обработки любого прерывания
            * каждый vector_i вызывает функцию trap

                ```
                vector1
                    .if (!(1 == 8 || (1 >= 10 && 1 <= 14) || 1 == 17))
                        pushl $0
                        .endif
                        pushl $1
                        jmp alltraps

                        // записываем на стек (err_code) и номер прерывания (int_no)
                        // смысл .if: для одних прерываний err_code кладет на стек сам CPU,
                        // для других --- надо класть 0 самим
                alltraps:
                    # Build trap frame.
                    pushl %ds
                    pushl %es
                    pushl %fs
                    pushl %gs
                    pushal // push all regs

                    mov $0x10, %ax
                    mov %ax, %ds

                    # Call trap(tf), where tf=%esp
                    pushl %esp
                    call trap
                    add $4, %esp
                    // execution falls through to trapret

                trapret:
                    popal // pop all regs
                    popl %gs
                    popl %fs
                    popl %es
                    popl %ds
                    addl $0x8, %esp  # trapno and errcode
                    iret
                ```

            * trap вызывает специфичный для конкретного прерывания обработчик, если он задан
            ```
                isr_t handler = interrupt_handlers[r->int_no];
                handler(r);
            ```
* Клавиатура

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
        ```

    * Задача << Shift >>
        ```
        static void interrupt_handler(registers_t *r) {
            uint8_t scancode = port_byte_in(0x60);
            if (scancode < sizeof(sc_ascii)) {
                char c = sc_ascii[scancode];
                if (shift) {
                    if (буквы) {
                        c = ...
                    } else if (цифры) {
                        c = ...
                    }
                }
                if (kbd_buf_size < kbd_buf_capacity) {
                    kbd_buf[kbd_buf_size++] = c;
                }
                char string[] = {c, '\0'};
                printk(string);
            } else if (scancode == LEFT_SHIFT or RIGHT_SHIFT) {
                if (нажат) {
                    shift = ...
                } else { // отжат
                    shift = ...
                }
            }
        }
        ```


* Видео VGA (текстовый режим) https://wiki.osdev.org/VGA_Hardware#Port_0x3C4.2C_0x3CE.2C_0x3D4

    * memory maped
        >The memory offset is twice the cursor offset, because each position in the text grid is
        >represented by 2 bytes, one for the character and one for color information.
        ```
        80 строк  x 25 столбцов

        [code, color]
          1b   1b

        80x25x2
        ```

    * port maped
        > The data register will hold the low byte if the control register is set to 0x0f, and the
        > high byte if the value 0x0e is used.
        ```
        [      ][       ]  port (перемещать курсор)
         ctrl r   data r
         ```
        * перевести курсор в позицию offset = 0x11aa,  offset = 2 * (i * 25 + j)
        ```
        out
        [ 0x0e ][ 0x11 ]
         ctrl r  data r

        out
        [ 0x0f ][ 0xaa ]
         ctrl r  data r
        ```


    * Задача << Backspace >>
    ```
    vga.c
    void vga_backspace() {
        unsigned offset = vga_get_cursor();
        if (есть что стирать) {
            vga_set_char(...) //поставить пробел на предыдущий символ
            vga_set_cursor(...) // переместить курсор на предыдущий символ
        }
    }


    keyboard.c
    static void interrupt_handler(registers_t *r) {
        if (нажат BACKSPACE) {
            if (в буфере есть что-нибудь) {
                изменить буфер kbd_buf, kbd_buf_size
                vga_backspace();
            }
        } else if (scancode < sizeof(sc_ascii)) {
            char c = sc_ascii[scancode];
            if (kbd_buf_size < kbd_buf_capacity) {
                kbd_buf[kbd_buf_size++] = c;
            }
            char string[] = {c, '\0'};
            printk(string);
        }
    }
    ```

* Timer
    * Прерывания, PIC (https://wiki.osdev.org/8259_PIC) (!!! NB: в современных PC -- APIC !!!)

    * Задача << Spinner >>
        ```
        init_pit();
        add_timer_callback(do_spin);
        uartinit();

        // меня вызывают 100 раз в секунду
        do_spin() {
            // менять картинку нужно 1 раз в секунду
            ...
            vga_set_char_color(offset, ch, color);
            ...
        }


        void vga_set_char(unsigned offset, char c) {
            video_memory[2 * offset] = c;
            video_memory[2 * offset + 1] = get_color(light_gray, black);
        }

        void vga_set_char_color(...) {

        }
        ```







