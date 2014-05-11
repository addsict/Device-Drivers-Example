#include <linux/fs.h>
#include <linux/init.h>
#include <linux/miscdevice.h>
#include <asm/uaccess.h>

static ssize_t hello_read(struct file *file, char *buf,
                          size_t count, loff_t *ppos)
{
    char *hello_str = "Hello, World!\n";
    int len = strlen(hello_str);

    if (count < len) return -EINVAL;
    if (*ppos != 0) return 0;

    if (copy_to_user(buf, hello_str, len)) return -EINVAL;

    *ppos = len;
    return len;
}

static const struct file_operations hello_fops = {
    .owner = THIS_MODULE,
    .read  = hello_read,
};

static struct miscdevice hello_dev = {
    MISC_DYNAMIC_MINOR,
    "hello_world",
    &hello_fops
};

static int __init hello_init(void)
{
    int ret;

    ret = misc_register(&hello_dev);
    if (ret) {
        printk(KERN_ERR "Unable to register hello world misc device\n");
    }

    return ret;
}

module_init(hello_init);

static void __exit hello_exit(void)
{
    misc_deregister(&hello_dev);
}

module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("yuki");
MODULE_DESCRIPTION("test misc device");
MODULE_VERSION("dev");
