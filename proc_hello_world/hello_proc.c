#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>

static int hello_read_proc(char *buffer, char **start, off_t offset,
                           int size, int *eof, void *data)
{
    char *hello_str = "Hello, World!\n";
    int len = strlen(hello_str);

    if (size < len) return -EINVAL;
    if (offset != 0) return 0;

    strcpy(buffer, hello_str);
    *eof = 1;

    return len;
}

static int __init hello_init(void)
{
    if (create_proc_read_entry("hello_world", 0, NULL, hello_read_proc, NULL) == 0) {
        printk(KERN_ERR "Unable to register hello world proc file\n");
        return -ENOMEM;
    }

    return 0;
}

module_init(hello_init);

static void __exit hello_exit(void)
{
    remove_proc_entry("hello_world", NULL);
}

module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("yuki");
MODULE_DESCRIPTION("test proc module");
MODULE_VERSION("proc");
