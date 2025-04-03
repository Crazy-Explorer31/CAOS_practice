SRCS = $(wildcard *.c)

PROGS = $(patsubst %.c,%.elf,$(SRCS))

all: $(PROGS)

%.elf: %.c
	$(CC) $(CFLAGS)  -o $@ $<

clean:
	rm -f *.elf

# cc  -m32  -o 02-time_t-overflow.elf 02-time_t-overflow.c
