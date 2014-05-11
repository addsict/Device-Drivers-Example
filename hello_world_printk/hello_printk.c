#include <linux/init.h>
#include <linux/module.h>

static int __init hello_init(void)
{
    printk("Hello Kernel!\n");
    return 0;
}

module_init(hello_init);

static void __exit hello_exit(void)
{
    printk("Goodbye Kernel!\n");
}

module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("yuki");
MODULE_DESCRIPTION("test module");
MODULE_VERSION("printk");
