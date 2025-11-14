# MIPS Assembly Interpreter

A lightweight MIPS Assembly interpreter written in modern C++.  
This project executes a subset of the MIPS instruction set, manages registers and memory, and simulates common system calls used in MARS or SPIM.

---

## Features

- Instruction parsing for a core subset of MIPS operations  
  - Arithmetic (`add`, `sub`, `addi`, etc.)  
  - Memory access (`lw`, `sw`)  
  - Branching (`beq`, `bne`, `j`, etc.)  
  - Data movement (`move`, `la`, `li`)  
- Register file simulation for `$zero`, `$v0`, `$a0`, `$t*`, `$s*`, etc.  
- Memory simulation with configurable size  
- System call support:  
  - `print_int`  
  - `print_string`  
  - `read_int`  
  - `exit`  
- Error handling for invalid opcodes, syntax errors, and memory violations  
- Single-step execution mode for debugging  
- Extensible instruction dispatch system

---

## Project Structure

```
/src
  ├── interpreter.cpp
  ├── parser.cpp
  ├── instruction.cpp
  ├── memory.cpp
  ├── registers.cpp
  └── utils.cpp

/include
  ├── interpreter.hpp
  ├── parser.hpp
  ├── instruction.hpp
  ├── memory.hpp
  └── registers.hpp

/examples
  ├── hello_world.s
  └── arithmetic.s

README.md
```

---

## Getting Started

### Requirements
- C++17 or later  
- CMake 3.10+  
- POSIX environment (Linux, macOS, WSL)  
- Windows compatible via MinGW or MSVC with small adjustments

---

## Build Instructions

```bash
git clone https://github.com/<your-username>/<repo-name>.git
cd <repo-name>
mkdir build && cd build
cmake ..
make
```

The binary will be located in:

```
build/bin/mips
```

---

## Usage

### Run a MIPS program
```bash
./mips program.s
```

### Step-by-step execution
```bash
./mips program.s --step
```

### Example Program

```asm
# examples/hello_world.s
li $v0, 1
li $a0, 42
syscall

li $v0, 10
syscall
```

Run it:

```bash
./mips examples/hello_world.s
```

---

## Supported Instructions

| Category       | Instructions                                             |
|----------------|-----------------------------------------------------------|
| Arithmetic     | `add`, `sub`, `addi`, `mul`, `div`                        |
| Logical        | `and`, `or`, `xor`, `sll`, `srl`                          |
| Memory         | `lw`, `sw`, `la`                                          |
| Movement       | `move`, `li`                                              |
| Branch/Jump    | `beq`, `bne`, `j`, `jr`                                   |
| Syscalls       | `print_int`, `print_string`, `read_int`, `exit`           |

---

## Roadmap

- Floating-point support  
- Expanded syscall table  
- GUI debugger  
- ELF loader  
- Performance improvements

---
