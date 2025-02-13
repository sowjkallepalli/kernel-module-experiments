#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>

#define PROC_NAME "xx_strlen"
#define BUFFER_SIZE 128

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A kernel module to store and return string length");

static struct proc_dir_entry *proc_entry;
static char stored_string[BUFFER_SIZE];
static int string_length = 0;

ssize_t proc_read(struct file *file, char __user *ubuf, size_t count, loff_t *ppos) {
    char buf[10];
    int len = sprintf(buf, "%d\n", string_length);
    return simple_read_from_buffer(ubuf, count, ppos, buf, len);
}

ssize_t proc_write(struct file *file, const char __user *ubuf, size_t count, loff_t *ppos) {
    if (count > BUFFER_SIZE - 1)
        return -EINVAL;
    
    if (copy_from_user(stored_string, ubuf, count))
        return -EFAULT;

    stored_string[count] = '\0';
    string_length = count - 1;  // Excluding newline
    printk(KERN_INFO "xx_strlen module received string: %s\n", stored_string);
    return count;
}

static const struct proc_ops proc_fops = {
    .proc_read = proc_read,
    .proc_write = proc_write,
};

static int __init xx_strlen_init(void) {
    proc_entry = proc_create(PROC_NAME, 0666, NULL, &proc_fops);
    if (!proc_entry)
        return -ENOMEM;
    printk(KERN_INFO "xx_strlen module loaded\n");
    return 0;
}

static void __exit xx_strlen_exit(void) {
    remove_proc_entry(PROC_NAME, NULL);
    printk(KERN_INFO "xx_strlen module unloading\n");
}

module_init(xx_strlen_init);
module_exit(xx_strlen_exit);

