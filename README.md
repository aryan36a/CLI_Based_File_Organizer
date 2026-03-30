# File Organizer

A CLI-based file organization utility written in C++17.

## Overview

File Organizer is a command-line tool that helps organize files in a directory by automatically sorting them into categorized subdirectories based on file type.

## Project Structure

```
file-organizer/
│
├── src/
│   ├── main.cpp           # Entry point
│   └── organizer.cpp      # Core organization logic
│
├── include/
│   └── organizer.h        # Header file with function declarations
│
├── Makefile               # Build configuration
└── README.md              # This file
```

## Requirements

- C++17 or later
- GCC or compatible compiler
- GNU Make (for building with Makefile)

## Building

### Using Makefile

```bash
make              # Build the project
make clean        # Remove build artifacts
make rebuild      # Clean and rebuild
```

### Using g++ directly

```bash
g++ -std=c++17 -Wall -Wextra -g -I include src/main.cpp src/organizer.cpp -o bin/file-organizer
```

## Usage

```bash
./bin/file-organizer <folder_path>
```

**Example:**
```bash
./bin/file-organizer /path/to/folder
```

The organizer will sort files in the specified folder into subdirectories based on their file types.

## Features

- Automatically organizes files by type
- Handles nested directories
- Preserves file structure and metadata

## License

MIT License

## Author

Aryan
