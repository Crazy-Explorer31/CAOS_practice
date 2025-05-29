SRCS = $(wildcard *.c)

PROGS = $(patsubst %.c,%.elf,$(SRCS))

all: $(PROGS)

%.elf: %.c
	$(CC) $(CFLAGS) -lpthread -o $@ $<

clean:
	rm -f *.elf
