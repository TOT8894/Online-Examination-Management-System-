# Compilation and Running Guide

## Table of Contents
1. [Quick Start](#quick-start)
2. [Windows Compilation](#windows-compilation)
3. [Linux Compilation](#linux-compilation)
4. [macOS Compilation](#macOS-compilation)
5. [IDE-Specific Instructions](#ide-specific-instructions)
6. [Troubleshooting](#troubleshooting)

---

## 1. Quick Start

### Prerequisites
- C++ compiler (GCC, Clang, or MSVC)
- Terminal/Command Prompt access
- main.cpp file

### Fastest Way to Run

**Windows (with MinGW):**
```bash
g++ main.cpp -o exam_system.exe
exam_system.exe
```

**Linux/Mac:**
```bash
g++ main.cpp -o exam_system
./exam_system
```

---

## 2. Windows Compilation

### Method 1: Using MinGW (Recommended)

**Step 1: Install MinGW**
1. Download MinGW from [mingw-w64.org](https://www.mingw-w64.org/)
2. Run installer and select "x86_64" architecture
3. Add MinGW bin folder to PATH:
   - Right-click "This PC" → Properties
   - Advanced System Settings → Environment Variables
   - Edit "Path" → Add `C:\MinGW\bin`

**Step 2: Verify Installation**
```bash
g++ --version
```

**Step 3: Compile**
```bash
# Navigate to project folder
cd path\to\project

# Compile
g++ main.cpp -o exam_system.exe

# Run
exam_system.exe
```

**With Warnings Enabled:**
```bash
g++ -Wall -Wextra main.cpp -o exam_system.exe
```

**With Optimization:**
```bash
g++ -O2 main.cpp -o exam_system.exe
```

### Method 2: Using Visual Studio

**Step 1: Install Visual Studio**
1. Download Visual Studio Community (free)
2. Install "Desktop development with C++" workload

**Step 2: Create Project**
1. File → New → Project
2. Select "Console App"
3. Name: "ExamSystem"
4. Replace generated code with main.cpp content

**Step 3: Build and Run**
1. Build → Build Solution (Ctrl+Shift+B)
2. Debug → Start Without Debugging (Ctrl+F5)

**Or use Developer Command Prompt:**
```bash
cl main.cpp /EHsc
main.exe
```

### Method 3: Using Code::Blocks

**Step 1: Install Code::Blocks**
1. Download from [codeblocks.org](http://www.codeblocks.org/)
2. Choose version with MinGW included

**Step 2: Create Project**
1. File → New → Project
2. Select "Console Application"
3. Choose C++
4. Add main.cpp to project

**Step 3: Build and Run**
1. Build → Build (Ctrl+F9)
2. Build → Run (Ctrl+F10)
3. Or Build → Build and Run (F9)

---

## 3. Linux Compilation

### Method 1: Using GCC (Most Common)

**Step 1: Install GCC**

**Ubuntu/Debian:**
```bash
sudo apt update
sudo apt install g++ build-essential
```

**Fedora:**
```bash
sudo dnf install gcc-c++
```

**Arch Linux:**
```bash
sudo pacman -S gcc
```

**Step 2: Verify Installation**
```bash
g++ --version
```

**Step 3: Compile and Run**
```bash
# Navigate to project
cd ~/path/to/project

# Compile
g++ main.cpp -o exam_system

# Make executable
chmod +x exam_system

# Run
./exam_system
```

**With Additional Flags:**
```bash
# With warnings
g++ -Wall -Wextra -pedantic main.cpp -o exam_system

# With C++11 standard
g++ -std=c++11 main.cpp -o exam_system

# With debugging symbols
g++ -g main.cpp -o exam_system

# With optimization
g++ -O3 main.cpp -o exam_system
```

### Method 2: Using Clang

**Step 1: Install Clang**
```bash
sudo apt install clang  # Ubuntu/Debian
```

**Step 2: Compile**
```bash
clang++ main.cpp -o exam_system
./exam_system
```

### Method 3: Using Makefile

**Create Makefile:**
```makefile
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
TARGET = exam_system
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)
```

**Use Makefile:**
```bash
make          # Compile
make run      # Compile and run
make clean    # Remove executable
```

---

## 4. macOS Compilation

### Method 1: Using Clang (Default)

**Step 1: Install Xcode Command Line Tools**
```bash
xcode-select --install
```

**Step 2: Verify Installation**
```bash
clang++ --version
```

**Step 3: Compile and Run**
```bash
# Navigate to project
cd ~/path/to/project

# Compile
clang++ main.cpp -o exam_system

# Run
./exam_system
```

**With Additional Flags:**
```bash
# With warnings
clang++ -Wall -Wextra main.cpp -o exam_system

# With C++11
clang++ -std=c++11 main.cpp -o exam_system

# With optimization
clang++ -O2 main.cpp -o exam_system
```

### Method 2: Using GCC via Homebrew

**Step 1: Install Homebrew**
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

**Step 2: Install GCC**
```bash
brew install gcc
```

**Step 3: Compile**
```bash
g++-13 main.cpp -o exam_system  # Version number may vary
./exam_system
```

### Method 3: Using Xcode IDE

**Step 1: Install Xcode from App Store**

**Step 2: Create Project**
1. File → New → Project
2. macOS → Command Line Tool
3. Language: C++
4. Replace main.cpp content

**Step 3: Build and Run**
1. Product → Build (Cmd+B)
2. Product → Run (Cmd+R)

---

## 5. IDE-Specific Instructions

### Visual Studio Code

**Step 1: Install Extensions**
1. Install "C/C++" extension by Microsoft
2. Install "Code Runner" extension (optional)

**Step 2: Configure tasks.json**

Create `.vscode/tasks.json`:
```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "build",
            "type": "shell",
            "command": "g++",
            "args": [
                "-g",
                "main.cpp",
                "-o",
                "exam_system"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}
```

**Step 3: Build and Run**
1. Terminal → Run Build Task (Ctrl+Shift+B)
2. Run executable from terminal

### CLion

**Step 1: Create CMakeLists.txt**
```cmake
cmake_minimum_required(VERSION 3.10)
project(ExamSystem)

set(CMAKE_CXX_STANDARD 11)

add_executable(exam_system main.cpp)
```

**Step 2: Build and Run**
1. Build → Build Project (Ctrl+F9)
2. Run → Run 'exam_system' (Shift+F10)

### Dev-C++

**Step 1: Install Dev-C++**
Download from [sourceforge.net](https://sourceforge.net/projects/orwelldevcpp/)

**Step 2: Create Project**
1. File → New → Project
2. Console Application
3. C++ Project
4. Add main.cpp

**Step 3: Compile and Run**
1. Execute → Compile (F9)
2. Execute → Run (F10)
3. Or Execute → Compile & Run (F11)

---

## 6. Troubleshooting

### Common Errors and Solutions

#### Error: "g++ is not recognized"
**Problem:** Compiler not in PATH

**Solution (Windows):**
```bash
# Add to PATH or use full path
C:\MinGW\bin\g++ main.cpp -o exam_system.exe
```

**Solution (Linux/Mac):**
```bash
# Install compiler
sudo apt install g++  # Ubuntu
brew install gcc      # macOS
```

#### Error: "Permission denied"
**Problem:** Executable doesn't have execute permission

**Solution (Linux/Mac):**
```bash
chmod +x exam_system
./exam_system
```

#### Error: "No such file or directory"
**Problem:** Wrong directory or filename

**Solution:**
```bash
# Check current directory
pwd  # Linux/Mac
cd   # Windows

# List files
ls   # Linux/Mac
dir  # Windows

# Navigate to correct directory
cd path/to/project
```

#### Error: "undefined reference to..."
**Problem:** Linking error

**Solution:**
```bash
# Ensure all source files are included
g++ main.cpp -o exam_system

# If using multiple files
g++ main.cpp other.cpp -o exam_system
```

#### Error: Compilation warnings
**Problem:** Code issues

**Solution:**
```bash
# Compile with warnings to see issues
g++ -Wall -Wextra main.cpp -o exam_system

# Fix reported issues in code
```

#### Error: "iostream: No such file or directory"
**Problem:** Compiler not properly installed

**Solution:**
```bash
# Reinstall compiler
# Windows: Reinstall MinGW
# Linux: sudo apt install build-essential
# Mac: xcode-select --install
```

#### Error: Program crashes on startup
**Problem:** Missing data files or permissions

**Solution:**
```bash
# Ensure write permissions in directory
# Program will create data files automatically
# Check if antivirus is blocking
```

### Platform-Specific Issues

#### Windows: "cls" command not working
**Solution:** This is normal on some terminals. The program will still work.

#### Linux: Screen not clearing
**Solution:** Change `system("cls")` to `system("clear")` in code.

#### macOS: Deprecated warnings
**Solution:** These are warnings, not errors. Program will still work.

---

## Compilation Flags Explained

### Common Flags

| Flag | Purpose | Example |
|------|---------|---------|
| `-o` | Specify output filename | `g++ main.cpp -o exam_system` |
| `-Wall` | Enable all warnings | `g++ -Wall main.cpp -o exam_system` |
| `-Wextra` | Enable extra warnings | `g++ -Wall -Wextra main.cpp` |
| `-g` | Include debugging symbols | `g++ -g main.cpp -o exam_system` |
| `-O2` | Optimization level 2 | `g++ -O2 main.cpp -o exam_system` |
| `-O3` | Optimization level 3 | `g++ -O3 main.cpp -o exam_system` |
| `-std=c++11` | Use C++11 standard | `g++ -std=c++11 main.cpp` |
| `-std=c++14` | Use C++14 standard | `g++ -std=c++14 main.cpp` |
| `-std=c++17` | Use C++17 standard | `g++ -std=c++17 main.cpp` |

### Recommended Compilation Commands

**For Development:**
```bash
g++ -Wall -Wextra -g -std=c++11 main.cpp -o exam_system
```

**For Release:**
```bash
g++ -O2 -std=c++11 main.cpp -o exam_system
```

**For Maximum Warnings:**
```bash
g++ -Wall -Wextra -Wpedantic -Werror main.cpp -o exam_system
```

---

## Quick Reference Card

### Windows (MinGW)
```bash
g++ main.cpp -o exam_system.exe && exam_system.exe
```

### Linux
```bash
g++ main.cpp -o exam_system && ./exam_system
```

### macOS
```bash
clang++ main.cpp -o exam_system && ./exam_system
```

### With Warnings
```bash
g++ -Wall -Wextra main.cpp -o exam_system
```

### Clean Build
```bash
# Remove old executable
rm exam_system      # Linux/Mac
del exam_system.exe # Windows

# Recompile
g++ main.cpp -o exam_system
```

---

## Batch/Shell Scripts

### Windows Batch Script (compile.bat)
```batch
@echo off
echo Compiling Exam System...
g++ -Wall main.cpp -o exam_system.exe
if %errorlevel% == 0 (
    echo Compilation successful!
    echo Running program...
    exam_system.exe
) else (
    echo Compilation failed!
    pause
)
```

### Linux/Mac Shell Script (compile.sh)
```bash
#!/bin/bash
echo "Compiling Exam System..."
g++ -Wall main.cpp -o exam_system
if [ $? -eq 0 ]; then
    echo "Compilation successful!"
    echo "Running program..."
    ./exam_system
else
    echo "Compilation failed!"
    exit 1
fi
```

**Make executable:**
```bash
chmod +x compile.sh
./compile.sh
```

---

## Additional Resources

- [GCC Documentation](https://gcc.gnu.org/onlinedocs/)
- [Clang Documentation](https://clang.llvm.org/docs/)
- [C++ Reference](https://en.cppreference.com/)
- [Stack Overflow](https://stackoverflow.com/questions/tagged/c++)

---

**Need Help?**
- Check compiler version: `g++ --version`
- Check if file exists: `ls main.cpp` (Linux/Mac) or `dir main.cpp` (Windows)
- Read error messages carefully
- Search error messages online

---

**Last Updated:** May 2024  
**Tested On:** Windows 10, Ubuntu 22.04, macOS Ventura
