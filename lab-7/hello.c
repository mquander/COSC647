#define __KERNEL__
#define MODULE
#include <linux/module.h>
#include <linux/kernel.h>

int init_module(void){
	printk(KERN_INFO "hello.c -- init_module() called\n");
	return 0;
}

void cleanup_module(void){
	printk(KERN_INFO "hello.c -- cleanup_module() called\n");
}
