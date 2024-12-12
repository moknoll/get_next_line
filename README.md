# get_next_line

The `get_next_line` function is a utility designed to read a file line by line. It is particularly useful for scenarios where processing files incrementally is more efficient than loading the entire file into memory.

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

##  File Structure

```
get_next_line/
├── get_next_line.c        # Main function implementation
├── get_next_line_utils.c  # Utility functions
├── get_next_line.h        # Header file
├── README.md              # Documentation
└── example.txt            # Example file (optional)
```

### Explanation:
```markdown
1. **Title and Introduction**: The README starts with a brief description of what the project is, 
    focusing on the `ft_printf` implementation and its features.
  
2. **Features**: Lists the core functionalities of the `ft_printf` function, like printing integers, 
    strings, characters, pointers, hexadecimal values, and special characters.

3. **Installation**: Explains how to clone the project and include it in your own.

4. **Usage**: Provides an example of how to use the `ft_printf` function, 
    showing the format specifiers and their expected output.

5. **File Descriptions**: A brief rundown of the core files in the project.

6. **License**: Mentions that the project uses the MIT license, 
    or you can replace it with another if you prefer.

This should give users a clear understanding of your project and how to use your `ft_printf` function effectively.
```

