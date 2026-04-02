# CLI Based File Organizer

A simple C++ command-line utility that sorts files into folders based on extension.

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
g++ -std=c++17 -Wall -Wextra -I include src/main.cpp src/organizer.cpp -o organizer.exe
```

### Linux/macOS (g++)

```bash
g++ -std=c++17 -Wall -Wextra -I include src/main.cpp src/organizer.cpp -o organizer
```

### MSVC (Developer Command Prompt)

```bat
cl /std:c++17 /EHsc /I include src\main.cpp src\organizer.cpp /Fe:organizer.exe
```

## Run

### Windows

```powershell
.\organizer.exe "D:\path\to\folder"
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

## Author

Aryan
