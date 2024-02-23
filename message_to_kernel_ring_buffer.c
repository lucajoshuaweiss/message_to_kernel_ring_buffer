/* 

 * message_to_kernel_ring_buffer.c - Prints a string into linux kernel ring buffer 

 Created by Luca Joshua Weiß
 */ 

#include <linux/module.h> // Needed by all modules 
#include <linux/printk.h> // Needed for pr_info()  

//string parameter
static char *message = "DEFAULT";

//reads message as a charpointer and gives reading and writing permissions to user
module_param(message, charp, S_IRUSR | S_IWUSR);

MODULE_PARM_DESC(message, "A character pointer, please do not use whitespaces");

int message_init(void) 
{ 
    //pr_info sends a KERN_INFO log to the kernel ring buffer
    pr_info("%s\n", message);  
    return 0; 
} 

void message_exit(void) 
{ 
    pr_info("Unloaded module message_to_kernel_ring_buffer\n"); 
}

module_init(message_init);
module_exit(message_exit);

MODULE_LICENSE("MIT");
