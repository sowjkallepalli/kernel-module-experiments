#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple Hello World kernel module");

static int __init xx_hello_init(void) {
    printk(KERN_INFO "xx_hello module loading\n");
    return 0;
}

static void __exit xx_hello_exit(void) {
    printk(KERN_INFO "xx_hello module unloading\n");
}

module_init(xx_hello_init);
module_exit(xx_hello_exit);

