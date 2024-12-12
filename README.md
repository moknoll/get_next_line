# get_next_line

## ✨ Overview

The `get_next_line` function is a utility designed to read a file line by line. It is particularly useful for scenarios where processing files incrementally is more efficient than loading the entire file into memory.

This implementation adheres to the C programming standards and is compatible with the `read` system call. The function is designed to handle:

- Both text and binary files.
- Files with varying line lengths.
- Multiple file descriptors (if implemented).

## 📊 Features

- Reads one line at a time, including the newline character `\n`.
- Efficient use of memory through a buffer system.
- Handles large files and input streams gracefully.
- Can manage multiple file descriptors simultaneously (if configured to support them).

## ⚙️ Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/moknoll/get_next_line.git
   cd get_next_line
   ```
2. Compile the function with your project files. Example:
   ```bash
   gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c 
   ```

   Replace `BUFFER_SIZE=42` with your desired buffer size.

## 🔧 Usage

Include the `get_next_line` header file in your project:
```c
#include "get_next_line.h"
```

### Example:
```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void) {
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}
```

## 🔒 API Reference

### `char *get_next_line(int fd);`
- **Parameters:**
  - `fd`: File descriptor of the file to read from.
- **Returns:**
  - The next line from the file (including the newline character, if present).
  - `NULL` if there is nothing more to read or an error occurs.
- **Memory Management:**
  - The returned line must be freed by the user to prevent memory leaks.

## 🔧 Implementation Notes

- The function uses a static variable to store leftover data between calls.
- The buffer size is defined by the `BUFFER_SIZE` macro during compilation.
- Handles edge cases such as:
  - Files that do not end with a newline.
  - Empty files.

## 📚 File Structure

```
get_next_line/
├── get_next_line.c        # Main function implementation
├── get_next_line_utils.c  # Utility functions
├── get_next_line.h        # Header file
├── README.md              # Documentation
└── example.txt            # Example file (optional)
```

## ✨ Contributions

Contributions, issues, and feature requests are welcome! Feel free to check the [issues page](https://github.com/yourusername/get_next_line/issues).

## © License

This project is licensed under the MIT License. See the `LICENSE` file for details.

---

**Happy Coding!**

