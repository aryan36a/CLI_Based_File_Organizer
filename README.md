# CLI Based File Organizer

![C++17](https://img.shields.io/badge/C%2B%2B-17-blue)
![Platform-Windows](https://img.shields.io/badge/Platform-Windows-success)
![Linux/macOS-Untested](https://img.shields.io/badge/Linux%2FmacOS-Untested-orange)
![Status-Active](https://img.shields.io/badge/Status-Active-brightgreen)

A simple C++ command-line utility that sorts files into folders based on extension.

## Compatibility Warning

- Fully tested on Windows.
- Linux and macOS build commands are included, but they are currently untested in this repository.
- If you run this on Linux/macOS and notice issues, please open an issue with your compiler version and error output.

## What It Does

Given a target directory, the program scans files recursively and moves them into category folders such as:

- `image`
- `video`
- `document`
- `audio`
- `archive`
- `code`
- `binary`
- `font`
- `disk`
- `others`

If a file name already exists in the destination folder, the tool auto-renames it safely (for example `photo.jpg` -> `photo_1.jpg`).

## Project Structure

```text
CLI Based File Organizer/
|- include/
|  |- organizer.h
|- src/
|  |- main.cpp
|  |- organizer.cpp
|  |- include/
|- test/
|  |- make_files.py
|- README.md
```

## Requirements

- C++17 compatible compiler (`g++`, `clang++`, or MSVC)
- Git (optional)
- Python 3 (optional, only for generating test files)

## Build

### Windows (PowerShell + g++)

```powershell
g++ src/main.cpp src/organizer.cpp -Iinclude -o organizer
```

### Linux/macOS (g++)

```bash
g++ src/main.cpp src/organizer.cpp -Iinclude -o organizer
```

### MSVC (Developer Command Prompt)

```bat
cl /std:c++17 /EHsc /I include src\main.cpp src\organizer.cpp /Fe:organizer.exe
```

## Run

### Windows

```powershell
.\organizer "D:\path\to\folder"
```

### Linux/macOS

```bash
./organizer "/path/to/folder"
```

## Example

Before:

```text
Downloads/
|- report.pdf
|- photo.JPG
|- song.mp3
|- archive.zip
```

After running the organizer:

```text
Downloads/
|- document/
|  |- report.pdf
|- image/
|  |- photo.JPG
|- audio/
|  |- song.mp3
|- archive/
|  |- archive.zip
```

## Notes

- Extension matching is case-insensitive (`.JPG` and `.jpg` are treated the same).
- The tool skips files already inside known category folders.
- Invalid paths and inaccessible directories are handled with error messages.

## Test Data Generator (Optional)

To quickly create sample files for testing:

```powershell
cd test
python make_files.py
```

## What I Learned

Building this project taught me a lot about practical C++ filesystem tooling:

- How to use `std::filesystem` for recursive directory traversal and file moves.
- Why collision-safe naming matters when two files share the same name.
- How to normalize file extensions for case-insensitive matching.
- How small CLI tools still need solid error handling for invalid paths and permission issues.
- Why project documentation and test-data scripts make a repo easier for others to use.

## Author

Aryan
