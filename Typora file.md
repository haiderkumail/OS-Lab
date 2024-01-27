# Task1:

# Ubuntu Installation Guide on VMware

## Introduction

This user manual provides step-by-step instructions for installing the Ubuntu distribution on your system using VMware. Follow these guidelines to set up a virtual machine with Ubuntu, ensuring a smooth installation process.

### Conditions Required

Before you begin, make sure you have the following:

- VMware installed on your system.
- Ubuntu ISO file downloaded from the official website.

## Step 1: VMware Installation

1. Open VMware and click on "Create a New Virtual Machine" or "New" depending on your VMware version.

2. Choose "Typical" for the setup type and click "Next."

3. Select "Installer disc image file (iso)" and browse to the location where you saved the Ubuntu ISO file. Click "Next."

4. Enter a name for your virtual machine, select a location to store it, and click "Next."

5. Set the disk capacity for your virtual machine. It is recommended to allocate at least 25 GB. Click "Next."

6. Review your settings and click "Finish" to create the virtual machine.

## Step 2: Ubuntu Installation

1. Power on the virtual machine.

2. The Ubuntu installer will start. Choose your language and click "Install Ubuntu."

3. Follow the on-screen instructions to select your time zone, keyboard layout, and user account details.

4. When prompted, select the option to "Erase disk and install Ubuntu" and click "Install Now."

5. Confirm the changes to the disk and click "Continue."

6. Complete the installation by following the prompts for language, keyboard layout, and user account creation.

7. Once the installation is complete, click "Restart Now" to reboot the virtual machine.

## Step 3: Post-Installation Configuration

1. After rebooting, log in with the user account created during the installation.

2. Open the Terminal and update the package lists using the command.
   
3. Install any additional compilers or tools you need for your development environment using the package manager. For example, to install the build-essential packages.
   
4. Your Ubuntu installation on VMware is now complete and ready for use.

## Conclusion

You have successfully installed Ubuntu on VMware, configured the virtual machine, and performed post-installation setup. If you encounter any issues or have specific requirements, refer to the official documentation for VMware and Ubuntu for additional support.

# Task2:

Certainly! If you have specific examples provided in your lecture slides to test the `gcc` and `g++` compilers, I'll guide you through the process of testing these compilers on your Ubuntu OS.

Let's assume you have two files named `hello.c` and `hello.cpp`. We'll compile and run these files using `gcc` and `g++`, respectively.

### Example 1: Testing `gcc` Compiler (C file)

**Step 1: Create `hello.c` file**

Open a text editor (like `nano` or `gedit`) and enter the following code:

```c
// hello.c
#include <stdio.h>

int main() {
    printf("Hello, this is a C program!\n");
    return 0;
}
```

Save the file.

**Step 2: Compile and Execute**

Open the terminal and navigate to the directory where `hello.c` is located.

```bash
gcc hello.c -o hello
./hello
```

**Output:**
```
Hello, this is a C program!
```

### Example 2: Testing `g++` Compiler (C++ file)

**Step 1: Create `hello.cpp` file**

Open a text editor and enter the following code:

```cpp
// hello.cpp
#include <iostream>

int main() {
    std::cout << "Hello, this is a C++ program!" << std::endl;
    return 0;
}
```

Save the file.

**Step 2: Compile and Execute**

Open the terminal and navigate to the directory where `hello.cpp` is located.

```bash
g++ hello.cpp -o hello_cpp
./hello_cpp
```

**Output:**
```
Hello, this is a C++ program!
```

### Summary

1. **For C Compilation:**
   - Create a C source file (e.g., `hello.c`).
   - Use `gcc` to compile: `gcc hello.c -o hello`
   - Run the executable: `./hello`

2. **For C++ Compilation:**
   - Create a C++ source file (e.g., `hello.cpp`).
   - Use `g++` to compile: `g++ hello.cpp -o hello_cpp`
   - Run the executable: `./hello_cpp`

Make sure to replace `hello.c` and `hello.cpp` with the actual file names if they are different. This process helps you verify that both `gcc` and `g++` compilers are installed and functioning correctly on your Ubuntu OS.

![WhatsApp Image 2024-01-27 at 11.33.44_c0637614](C:\Users\JUNCTION\AppData\Local\Packages\5319275A.WhatsAppDesktop_cv1g1gvanyjgm\TempState\83004190B1793D7AA15F8D0D49A13EBA\WhatsApp Image 2024-01-27 at 11.33.44_c0637614.jpg)

![pic](C:\Users\JUNCTION\Pictures\Camera Roll\pic.jpg)



# Task3:

https://github.com/haiderkumail/OS-Lab
