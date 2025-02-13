# Linux Kernel Module experiments  

## Overview  
This repository contains implementations of Linux kernel modules that demonstrate module loading, unloading, and interaction with the `/proc` filesystem.  

### Features  
- A simple **"Hello World" kernel module** that logs messages when loaded and unloaded.  
- A **string-length kernel module** that creates a virtual file in `/proc`, allowing users to store a string and retrieve its length.  

---

## File Structure  
📂 linux-kernel-modules/
│── 📜 README.md # Project documentation
│── 📜 Makefile # Makefile to compile modules
│── 📜 xx_hello.c # Hello world kernel module
│── 📜 xx_strlen.c # String length kernel module
│── 📜 script_output.txt # Execution log


## 📌 How to Compile and Load

### 🔹 Step 1: Compile Modules
```bash
make

**🔹 Step 2: Load and Test xx_hello**
'
sudo insmod xx_hello.ko
lsmod | grep xx_hello
sudo rmmod xx_hello
dmesg | tail
'

**🔹 Step 3: Load and Test xx_strlen**
'
sudo insmod xx_strlen.ko
lsmod | grep xx_strlen
echo "CS621IsGreat" > /proc/xx_strlen
cat /proc/xx_strlen  # Should return 12
sudo rmmod xx_strlen
dmesg | tail
'

**📌 Cleaning Up**
'
make clean
'
