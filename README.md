# message_to_kernel_ring_buffer
This projects purpose is to learn about linux kernel modules.  
It creates a .ko file which can be inserted as a linux kernel module to print a string to the linux kernel ring buffer.  

# Usage
Making the .ko file:  
```bash
sudo make
```
  
Inserting the .ko file as a linux kernel module and manipulating the message parameter:  
(NOTE: please do not use whitespaces in your message, since the kernel interprets everything after a whitespace as an additionial parameter)  
```bash
sudo insmod message_to_kernel_ring_buffer.ko message="This_is_a_custom_message"
```

Viewing the result via dmesg:  
```bash
sudo dmesg
```

Removing the linux kernel module:
```bash
sudo rmmod message_to_kernel_ring_buffer
```

Cleaning up files:
```bash
sudo make clean
```

Tested on kernel 6.7.5-arch1-1.
