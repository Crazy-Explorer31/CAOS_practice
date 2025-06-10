SRCS = $(wildcard *.c) $(wildcard *.cpp)

PROGS = $(patsubst %.c,%.elf,$(SRCS)) $(patsubst %.cpp,%.elf,$(SRCS))

all: $(PROGS)

%.elf: %.c
	$(CC) $(CFLAGS) -pthread -o $@ $<

%.elf: %.cpp
	$(CXX) $(CFLAGS) -pthread -o $@ $<

clean:
	rm -f *.elf
