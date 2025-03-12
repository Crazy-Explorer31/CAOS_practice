SRCS = $(wildcard *.c)

PROGS = $(patsubst %.c,%.elf,$(SRCS))

all: $(PROGS)

%.elf: %.c
	$(CC) $(CFLAGS) -g -o $@ $<

clean:
	rm -f *.elf
