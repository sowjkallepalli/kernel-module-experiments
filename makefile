# Kernel build system  
obj-m += xx_hello.o  
obj-m += xx_strlen.o  

# Set kernel build directory  
KDIR := /lib/modules/$(shell uname -r)/build  

# Default target  
all:  
	$(MAKE) -C $(KDIR) M=$(PWD) modules  

# Clean target  
clean:  
	$(MAKE) -C $(KDIR) M=$(PWD) clean  

