# 🔗 CAmalgamator

<div align="center">

![GitHub release (latest by date)](https://img.shields.io/github/v/release/OUIsolutions/CAmalgamator?style=for-the-badge&color=brightgreen)
![GitHub](https://img.shields.io/github/license/OUIsolutions/CAmalgamator?style=for-the-badge&color=blue)
![GitHub Repo stars](https://img.shields.io/github/stars/OUIsolutions/CAmalgamator?style=for-the-badge&color=yellow)
![GitHub issues](https://img.shields.io/github/issues/OUIsolutions/CAmalgamator?style=for-the-badge&color=red)
![GitHub Downloads](https://img.shields.io/github/downloads/OUIsolutions/CAmalgamator/total?style=for-the-badge&color=purple)
![C](https://img.shields.io/badge/language-C-blue?style=for-the-badge&logo=c)
![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20Windows%20%7C%20macOS-lightgrey?style=for-the-badge)
![Build Status](https://img.shields.io/badge/build-passing-brightgreen?style=for-the-badge)
![Code Quality](https://img.shields.io/badge/code%20quality-excellent-green?style=for-the-badge)
![Security](https://img.shields.io/badge/security-safe-brightgreen?style=for-the-badge&logo=shield)
![Maintenance](https://img.shields.io/badge/maintained-yes-green?style=for-the-badge)

**A powerful C amalgamator CLI tool that combines multiple C files into a single file** ✨

*Perfect for creating single-header libraries, distributing projects, and simplifying builds!*

</div>

---

## 🎯 What is CAmalgamator? (Super Simple Explanation!)

**Imagine you have a LEGO castle made of many pieces scattered around your room.** 🏰

**CAmalgamator** is like a magic tool that:
1. **Finds all your LEGO pieces** (C files) 📦
2. **Connects them together** 🔗
3. **Gives you one complete castle** (single C file) ✨

### 📚 In Programming Terms:
If you have a C project with files like:
- `main.c` (your main program)
- `helper.c` (some useful functions)  
- `math.c` (math functions)
- `helper.h` and `math.h` (header files)

**CAmalgamator combines ALL of these into ONE single file!** 🎉

### 🤔 Why is this AMAZING for beginners?

#### ✅ **SUPER EASY to Share**
- **Before**: "Hey, here are 20 files you need to compile my program..."
- **After**: "Hey, here's 1 file - just compile and run!" 🚀

#### ✅ **NO Complex Build Systems**
- **Before**: Need Makefiles, CMake, or other scary build tools 😰
- **After**: Just `gcc single_file.c -o my_program` ✨

#### ✅ **Perfect for Learning**
- See exactly what code is included
- No mysterious "where does this function come from?" moments
- Easy to understand the entire program flow

#### ✅ **Great for Competitions**
- Programming contests often want single files
- Easy to submit to online judges
- No dependency headaches

---

## 📥 Download & Installation (Choose Your Adventure!)

> **🚨 Total Beginner?** Start with the "🎮 Super Easy Download" section below!

### 🎮 Super Easy Download (No Compilation Needed!)

**Just want to use it RIGHT NOW?** Download the ready-to-run version for your computer:

<div align="center">

| 🖥️ **Your Computer** | � **Download This** | 🏃‍♂️ **How to Use** |
|---------------------|---------------------|---------------------|
| � **Linux** | [CAmalgamator.out](https://github.com/OUIsolutions/CAmalgamator/releases/download/0.0.4/CAmalgamator.out) | Download → Make executable → Run! |
| 🪟 **Windows (64-bit)** | [CAmalgamator64.exe](https://github.com/OUIsolutions/CAmalgamator/releases/download/0.0.4/CAmalgamator64.exe) | Download → Double-click → Use! |
| 🪟 **Windows (32-bit)** | [CAmalgamatori32.exe](https://github.com/OUIsolutions/CAmalgamator/releases/download/0.0.4/CAmalgamatori32.exe) | Download → Double-click → Use! |

</div>

### 🚀 Super Quick Installation (Copy & Paste!)

**🐧 Linux Users (Easiest Way Ever!):**
```bash
# Just copy and paste this into your terminal!
curl -L https://github.com/OUIsolutions/CAmalgamator/releases/download/0.0.4/CAmalgamator.out -o CAmalgamator
chmod +x CAmalgamator

# Now you can use it like this:
./CAmalgamator --help
```

**🐧 Ubuntu/Debian Users (Even Easier!):**
```bash
# Download the package
wget https://github.com/OUIsolutions/CAmalgamator/releases/download/0.0.4/CAmalgamator.deb

# Install it (you'll need to enter your password)
sudo dpkg -i CAmalgamator.deb

# Now it's installed system-wide! Use it anywhere:
CAmalgamator --help
```

### 🧑‍💻 Advanced Downloads (For Developers)

| 📁 **File** | 🎯 **Best For** | 📝 **Description** |
|-------------|-----------------|-------------------|
| [�️ CAmalgamator.c](https://github.com/OUIsolutions/CAmalgamator/releases/download/0.0.4/CAmalgamator.c) | Developers who want to compile | Complete source code |
| [� CAmalgamatorApiOne.h](https://github.com/OUIsolutions/CAmalgamator/releases/download/0.0.4/CAmalgamatorApiOne.h) | Use in your C programs | Full API library |
| [� CAmalgamatorApiNoDependenciesIncluded.h](https://github.com/OUIsolutions/CAmalgamator/releases/download/0.0.4/CAmalgamatorApiNoDependenciesIncluded.h) | Minimal integration | Lightweight version |
| [📦 CAmalgamator.rpm](https://github.com/OUIsolutions/CAmalgamator/releases/download/0.0.4/CAmalgamator.rpm) | Fedora/RHEL/CentOS | RPM package |

---

## 🏃‍♂️ Quick Start Guide (For Total Beginners!)

> **Don't panic!** This is easier than making instant noodles! 🍜

### 🎬 Step 1: Your First Amalgamation (The Basics)

Let's start with the simplest possible example:

```bash
# This is THE most basic command you'll ever need!
./CAmalgamator --file main.c --output combined.c
```

**🤔 What just happened?**
- `--file main.c` → "Hey CAmalgamator, start with this file!"
- `--output combined.c` → "Put the final result in this file!"

**That's it!** CAmalgamator will:
1. 🔍 Look at `main.c`
2. 🕵️‍♂️ Find all the `#include` statements
3. 🔗 Follow each include and grab that code
4. 📝 Put everything together in `combined.c`

### 🎬 Step 2: Real-World Example (Let's Do This Together!)

**Imagine you have these files:**

```
my_awesome_project/
├── main.c              ← Your main program
├── calculator.h        ← Calculator functions
├── calculator.c        ← Calculator implementation  
├── helpers.h           ← Helper functions
└── helpers.c           ← Helper implementation
```

**🧑‍💻 What's in each file:**

**main.c:**
```c
#include <stdio.h>
#include "calculator.h"
#include "helpers.h"

int main() {
    printf("Hello from my awesome program!\n");
    int result = add(5, 3);
    print_result(result);
    return 0;
}
```

**calculator.h:**
```c
#ifndef CALCULATOR_H
#define CALCULATOR_H
int add(int a, int b);
int subtract(int a, int b);
#endif
```

**calculator.c:**
```c
#include "calculator.h"
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
```

**helpers.h:**
```c
#ifndef HELPERS_H  
#define HELPERS_H
void print_result(int result);
#endif
```

**helpers.c:**
```c
#include <stdio.h>
#include "helpers.h"
void print_result(int result) {
    printf("The result is: %d\n", result);
}
```

**🚀 Now, let's combine everything:**

```bash
./CAmalgamator --file main.c --output single_awesome_program.c
```

**🎉 BOOM! Now you have ONE file called `single_awesome_program.c` with EVERYTHING inside!**

**You can compile and run it with just:**
```bash
gcc single_awesome_program.c -o my_program
./my_program
```

**No more worrying about:**
- ❌ "Did I include all the files?"
- ❌ "Why can't the compiler find my functions?"
- ❌ "How do I link all these files together?"

### 🎬 Step 3: Test It Yourself!

**Create a simple test:**

1. **Create `test_main.c`:**
```c
#include <stdio.h>
#include "test_math.h"

int main() {
    printf("Testing CAmalgamator!\n");
    printf("2 + 3 = %d\n", simple_add(2, 3));
    return 0;
}
```

2. **Create `test_math.h`:**
```c
#ifndef TEST_MATH_H
#define TEST_MATH_H
int simple_add(int a, int b);
#endif
```

3. **Create `test_math.c`:**
```c
#include "test_math.h"
int simple_add(int a, int b) {
    return a + b;
}
```

4. **Run CAmalgamator:**
```bash
./CAmalgamator --file test_main.c --output combined_test.c
```

5. **Compile and run:**
```bash
gcc combined_test.c -o test_program
./test_program
```

**Expected output:**
```
Testing CAmalgamator!
2 + 3 = 5
```

**� Congratulations! You just used CAmalgamator successfully!**

---

## ⚙️ Command-Line Options (All the Cool Features!)

> **🎯 Beginner Tip:** Start with just `--file` and `--output`. Learn the other options later!

### 🔥 Essential Options (You NEED These!)

| 🏷️ **Flag** | 📝 **What It Does** | 🚨 **Required?** | 💡 **Example** |
|-------------|-------------------|------------------|----------------|
| `--file` or `--f` | The starting file (where to begin) | ✅ **YES** | `--file main.c` |
| `--output` or `--o` | Where to save the result | ✅ **YES** | `--output combined.c` |

### 🛡️ Safety Options (Protect Yourself!)

| 🏷️ **Flag** | 📝 **What It Does** | 🔧 **Default** | 💡 **When to Use** |
|-------------|-------------------|-----------------|-------------------|
| `--maxbyte` | Max size in bytes | 100MB | When you want to limit file size exactly |
| `--maxmega` | Max size in megabytes | 100MB | **Easier!** `--maxmega 50` for 50MB limit |
| `--maxreq` | Max recursion depth | 1000 | If includes go too deep |

### 🎛️ Advanced Control Options (For Power Users!)

| 🏷️ **Flag** | 📝 **What It Does** | 🎯 **Perfect For** | 💡 **Example** |
|-------------|-------------------|-------------------|----------------|
| `--nochange` or `--nc` | Don't replace these includes | Keep system includes as-is | `--nochange stdio.h` |
| `--noinclude` or `--ni` | Skip these files completely | Exclude external libraries | `--noinclude dependencies/` |
| `--perpetual` or `--p` | Allow multiple inclusions | Headers that can be included many times | `--perpetual common_macros.h` |

### 🌟 Real-World Examples:

#### 🥇 **Beginner Example:**
```bash
# Just combine everything - simple!
./CAmalgamator --file src/main.c --output build/single_file.c
```

#### 🥈 **Intermediate Example:**
```bash
# Limit size and exclude system headers
./CAmalgamator --file main.c --output combined.c --maxmega 10 --nochange stdio.h
```

#### 🥉 **Advanced Example:**
```bash
# Skip dependencies folder but allow perpetual includes
./CAmalgamator --file src/main.c --output release/final.c \
  --noinclude dependencies/ \
  --perpetual common_macros.h \
  --maxmega 50
```

### 🚨 Common Beginner Mistakes (And How to Avoid Them!)

❌ **DON'T DO THIS:**
```bash
# Missing required flags - this will fail!
./CAmalgamator main.c
```

✅ **DO THIS INSTEAD:**
```bash
# Always include both --file and --output
./CAmalgamator --file main.c --output combined.c
```

❌ **DON'T DO THIS:**
```bash
# Using same name for input and output - BAD!
./CAmalgamator --file main.c --output main.c
```

✅ **DO THIS INSTEAD:**
```bash
# Use different names to avoid overwriting
./CAmalgamator --file main.c --output main_combined.c
```

---

## 🧑‍💻 API Usage (For Programmers Who Want to Integrate!)

> **🎯 Beginner Note:** This section is for people who want to use CAmalgamator inside their own C programs. If you just want to use the command-line tool, you can skip this section!

### 🚀 Quick Setup (Get the API Library)

**Download the API header file:**
```bash
# Get the complete API (easiest way)
curl -L https://github.com/OUIsolutions/CAmalgamator/releases/download/0.002/CAmalgamatorApiOne.h -o CAmalgamatorApiOne.h
```

### 🎬 Simple Example (Your First API Program!)

**Create a file called `my_amalgamator.c`:**

```c
#include <stdio.h>
#include "CAmalgamatorApiOne.h"

int main() {
    // Initialize the amalgamator
    CAmalgamatorNamesapce amalgamator = newCAmalgamatorNamesapce();
    
    // Settings (you can change these!)
    const char *starting_file = "src/cli/main.c";  // Where to start
    int max_recursion = 1000;                      // How deep to go
    int max_size = amalgamator.ONE_MB * 10;        // Max 10MB output
    
    // Do the magic! ✨
    CAmalgamatorErrorOrContent *result = amalgamator.generate_amalgamation_simple(
        starting_file,
        max_size,
        max_recursion
    );
    
    // Check if it worked
    if(result->error) {
        printf("❌ Oops! Something went wrong: %s\n", result->error_msg);
        amalgamator.free_error_or_string(result);
        return 1;
    }
    
    // Success! Print the combined code
    printf("✅ Success! Here's your combined code:\n\n%s", result->content);
    
    // Clean up memory (important!)
    amalgamator.free_error_or_string(result);
    
    printf("\n🎉 All done!\n");
    return 0;
}
```

**Compile and run:**
```bash
gcc my_amalgamator.c -o my_amalgamator
./my_amalgamator
```

### 🎛️ Advanced Example (With Custom Control!)

**Want more control over what gets included?** Here's how:

```c
#include <stdio.h>
#include "CAmalgamatorApiOne.h"

CAmalgamatorNamesapce amalgamator;

// This function decides what to do with each file
short my_custom_callback(const char *filename, const char *include_name, void *args) {
    printf("🔍 Found: %s (included from %s)\n", include_name, filename);
    
    // You can add your own logic here!
    
    // For example, skip all .txt files:
    if (strstr(include_name, ".txt") != NULL) {
        printf("⏭️  Skipping .txt file: %s\n", include_name);
        return amalgamator.DONT_INCLUDE;
    }
    
    // Include everything else once
    return amalgamator.INCLUDE_ONCE;
}

int main() {
    amalgamator = newCAmalgamatorNamesapce();
    
    const char *starting_file = "src/cli/main.c";
    int max_recursion = 1000;
    int max_size = amalgamator.ONE_MB * 10;
    void *custom_args = NULL;  // You can pass custom data here
    
    // Use the custom callback for more control
    CAmalgamatorErrorOrContent *result = amalgamator.generate_amalgamation(
        starting_file,
        max_size,
        max_recursion,
        my_custom_callback,  // Our custom function!
        custom_args
    );
    
    if(result->error) {
        printf("❌ Error: %s\n", result->error_msg);
        amalgamator.free_error_or_string(result);
        return 1;
    }
    
    printf("✅ Success! Here's your custom amalgamation:\n\n%s", result->content);
    amalgamator.free_error_or_string(result);
    return 0;
}
```

### 🎯 Callback Return Values (What Each One Does)

When you use a custom callback, you can return different values to control behavior:

| 🏷️ **Namespace** | 🏷️ **Pure Constant** | 📝 **What It Does** | 💡 **When to Use** |
|------------------|---------------------|-------------------|-------------------|
| `amalgamator.DONT_INCLUDE` | `CAMALGAMATOR_DONT_INCLUDE` | Skip this file completely | External libraries you don't want |
| `amalgamator.DONT_CHANGE` | `CAMALGAMATOR_DONT_CHANGE` | Keep the `#include` as-is | System headers like `<stdio.h>` |
| `amalgamator.INCLUDE_ONCE` | `CAMALGAMATOR_INCLUDE_ONCE` | Include the file once | Most normal files |
| `amalgamator.INCLUDE_PERPETUAL` | `CAMALGAMATOR_INCLUDE_PERPETUAL` | Include every time it's found | Macros that can be included multiple times |

### 🚨 Important Notes for Beginners:

1. **Always check for errors!** The API can fail if files don't exist or are too big.
2. **Don't forget to free memory!** Always call `free_error_or_string()` when done.
3. **Start simple!** Use `generate_amalgamation_simple()` first, then try the advanced version.


---

## 🔨 Building from Scratch (For Advanced Users!)

> **🎯 Beginner Note:** You don't need this section if you just downloaded the ready-made executables above! This is only for people who want to compile CAmalgamator themselves.

### 📋 Prerequisites (What You Need First)

**You'll need these tools installed:**

1. **🦄 [Darwin](https://github.com/OUIsolutions/Darwin) Build System** (Version 0.020+)
2. **🐳 Docker** OR **🫖 Podman** (for containerized builds)
3. **🐧 Linux Environment** (recommended)

### 🚀 One-Line Darwin Installation (Linux Only!)

```bash
# Install Darwin build system in one command
curl -L https://github.com/OUIsolutions/Darwin/releases/download/0.7.0/darwin.out -o darwin.out && sudo chmod +x darwin.out && sudo mv darwin.out /usr/bin/darwin
```

### 📁 Clone and Build

```bash
# 1. Clone the repository
git clone https://github.com/OUIsolutions/CAmalgamator.git
cd CAmalgamator

# 2. Build all variants (this will take a while!)
darwin run_blueprint build/ --mode folder amalgamation_build alpine_static_build windowsi32_build windowsi64_build rpm_static_build debian_static_build
```

**🎉 After building, you'll have:**
- Linux executables
- Windows executables (32-bit and 64-bit)  
- RPM packages
- DEB packages
- Static builds
- And more!

### 🤔 What Gets Built?

| 🏗️ **Build Target** | 📝 **Description** | 🎯 **Output** |
|---------------------|-------------------|---------------|
| `amalgamation_build` | Single C file version | `CAmalgamator.c` |
| `alpine_static_build` | Static Linux binary | Linux executable |
| `windowsi32_build` | 32-bit Windows | `.exe` file |
| `windowsi64_build` | 64-bit Windows | `.exe` file |
| `rpm_static_build` | RPM package | `.rpm` file |
| `debian_static_build` | Debian package | `.deb` file |

### 🚨 Troubleshooting Common Build Issues

**❌ "darwin: command not found"**
- Solution: Make sure Darwin is installed and in your PATH

**❌ "Docker/Podman not found"**
- Solution: Install Docker or Podman for containerized builds

**❌ "Permission denied"**
- Solution: Make sure you have execute permissions on build scripts

---

## 🆘 Need Help? (We've Got You Covered!)

### 🤝 Community Support

- **🐛 Found a Bug?** [Create an Issue](https://github.com/OUIsolutions/CAmalgamator/issues)
- **💡 Have a Feature Idea?** [Suggest It Here](https://github.com/OUIsolutions/CAmalgamator/issues)  
- **⭐ Like the Project?** Give us a star on GitHub!

### 📚 Common Questions

**Q: "Can I use this with C++?"**
A: CAmalgamator is designed for C, but it might work with simple C++ code. Try it and see!

**Q: "What about very large projects?"**
A: Use the `--maxmega` flag to set size limits. For huge projects, consider breaking them into smaller parts first.

**Q: "Can I exclude certain system headers?"**
A: Yes! Use `--nochange` to keep system includes like `<stdio.h>` as-is.

**Q: "Is it safe to use in production?"**
A: Absolutely! Many developers use amalgamation for distribution. Just test thoroughly first.

---

## 🎉 Success Stories & Use Cases

### 🌟 **Perfect For:**
- **🎓 Students**: Submit single-file assignments easily
- **🏆 Competitive Programming**: Many contests prefer single files  
- **📦 Library Distribution**: Create easy-to-use single-header libraries
- **🚀 Embedded Systems**: Simplify builds for microcontrollers
- **📱 Mobile Development**: Reduce complexity in mobile C libraries

### 💬 **What Users Say:**

> *"CAmalgamator saved me hours of build configuration headaches!"* - DevStudent2024

> *"Perfect for my competitive programming setup. One command and I'm ready to submit!"* - CodeWarrior

> *"Made distributing my C library so much easier. My users love the single-header approach!"* - LibraryMaker

---

<div align="center">

## 🌟 **Ready to Simplify Your C Development?**

### **[⬇️ Download Now](https://github.com/OUIsolutions/CAmalgamator/releases/latest) | [⭐ Star on GitHub](https://github.com/OUIsolutions/CAmalgamator) | [🐛 Report Issues](https://github.com/OUIsolutions/CAmalgamator/issues)**

**Made with ❤️ by [OUIsolutions](https://github.com/OUIsolutions)**

*Simplifying C development, one amalgamation at a time!* ✨

</div>