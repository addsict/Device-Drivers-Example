obj-m := hello_printk.o

# KDIR := /lib/modules/$(shell uname -r)/build
KDIR := /usr/src/kernels/2.6.32-431.17.1.el6.x86_64

PWD := $(shell pwd)

default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
