DEFAULT_HOST=i686
HOST=${DEFAULT_HOST}
HOSTARCH=$(HOST)

ARCHDIR=arch/$(HOSTARCH)

LINKER_FILE=$(ARCHDIR)/linker.ld
CONFIG_FILE=$(ARCHDIR)/make.config

CFLAGS=-std=gnu11 -ffreestanding -O2 -Wall -Wextra -I ./include
LDFLAGS=-T $(LINKER_FILE) -ffreestanding -O2 -nostdlib -lgcc -I ./include
LIBS=-nostdlib -lgcc

include $(CONFIG_FILE)

CFLAGS:=$(CFLAGS) $(KERNEL_ARCH_CFLAGS)
LDFLAGS:=$(LDFLAGS) $(KERNEL_ARCH_LDFLAGS)
LIBS:=$(LIBS) $(KERNEL_ARCH_LIBS)

KERNEL_OBJS=\
$(KERNEL_ARCH_OBJS) \
multiboot.o\
init_kernel.o\
kernel.o \
kheap/kavl.o \
kheap/kheap.o \
kheap/knoeud.o \
kheap/kfreespace.o \

LIBK_OBJS=\
libk/stdio/printf.o \
libk/stdio/print.o \
libk/stdio/putchar.o \
libk/stdio/puts.o \
libk/string/memcmp.o \
libk/string/memcpy.o \
libk/string/memmove.o \
libk/string/memset.o \
libk/string/strlen.o \
libk/stdlib/malloc.o \
libk/stdlib/free.o \
libk/stdlib/realloc.o \

OBJS=\
$(KERNEL_OBJS) \
$(LIBK_OBJS) \

LINK_LIST=\
$(LDFLAGS) \
$(KERNEL_OBJS) \
$(LIBK_OBJS) \
$(LIBS) \

.PHONY: all clean install install-headers install-kernel
.SUFFIXES: .o .c .S

all: install

Shea.kernel: $(OBJS)
	$(CC) -o $@ $(CFLAGS) $(LINK_LIST)
	grub-file --is-x86-multiboot Shea.kernel

.c.o: kernel_arch
	$(CC) -MD -c $< -o $@ $(CFLAGS)

.S.o:
	$(CC) -MD -c $< -o $@ $(CFLAGS)

clean:
	rm -f Shea.kernel
	rm -f $(OBJS) *.o */*.o */*/*.o
	rm -f $(OBJS:.o=.d) *.d */*.d */*/*.d

install: Shea.kernel

kernel_arch:
	chmod +x scripts/define_arch.sh
	./scripts/define_arch.sh $(HOSTARCH)

-include $(OBJS:.o=.d)
