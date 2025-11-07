# 🚀 Get Next Line (GNL)

> A C function that reads a file line by line, one line at a time.

---

## 🎯 Project Goals

This project is a classic challenge focused on **file I/O** and **static variables**. The goal is to create a function that, when called inside a loop, returns the next line from a file descriptor until the end of the file is reached. It teaches efficient reading with a minimal buffer size and the critical importance of persistent data (static variables) between function calls.

## 🛠️ Technical Details

* **Static Variables:** Uses a `static char *` (or similar structure) to store any leftover data from the buffer that wasn't part of the line returned in the previous call. This ensures no data is lost between calls.
* **Buffer-Based Reading:** Reads the file in small, fixed-size chunks (defined by `BUFFER_SIZE`) to efficiently handle large files without loading them entirely into memory.
* **Newline Handling:** Correctly identifies and processes lines ending with a newline character (`\n`) as well as the final line of the file, which may not have one.
* **Challenge:** The main challenge was managing the static buffer correctly. It involved complex string manipulation: joining the new buffer read with the leftover data, finding the newline, extracting the line to be returned, and correctly updating the static variable with the new "leftover" data.

## ⚙️ How to Compile & Run

This project does not have a `Makefile` for a library. To use it, you must compile its files along with your own project.

1.  Add the `get_next_line.c` and `get_next_line_utils.c` (and the `get_next_line.h` header) files to your project's directory.

2.  When compiling your program, include the `.c` files in your command. You **must** also define the `BUFFER_SIZE` with a flag:

    ```bash
    # Replace main.c with your project's files
    cc main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=42 -o your_program
    ```

3.  To use it, include the header and call the function in a loop. Here is an example `main.c`:

    ```c
    #include "get_next_line.h"
    
    int main()
    {
        int fd;
        char *line;

        // Make sure to create a file named "your_file.txt"
        fd = open("your_file.txt", O_RDONLY);
        if (fd == -1)
        {
            printf("Error opening file\n");
            return (1);
        }
        
        while ((line = get_next_line(fd)) != NULL)
        {
            printf("%s", line);
            free(line);
        }
        
        close(fd);
        return (0);
    }
    ```
