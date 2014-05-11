cf.) [http://www.linuxdevcenter.com/pub/a/linux/2007/07/05/devhelloworld-a-simple-introduction-to-device-drivers-under-linux.html](http://www.linuxdevcenter.com/pub/a/linux/2007/07/05/devhelloworld-a-simple-introduction-to-device-drivers-under-linux.html)

printk

```sh
$ make
$ sudo insmod hello_printk.ko
$ sudo rmmod hello_printk
```

proc

```sh
$ make
$ sudo insmod hello_proc.ko
$ cat /proc/modules # confirm hello_proc module exist.
$ sudo rmmod hello_proc
```

dev

```sh
$ make
$ sudo insmod hello_dev.ko
$ sudo rmmod hello_dev
```
