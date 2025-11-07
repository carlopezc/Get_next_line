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

1.  Clone the repository:
    ```bash
    git clone [https://github.com/carlopezc/Get_next_line.git](https://github.com/carlopezc/Get_next_line.git)
    cd Get_next_line
    ```
2.  Compile the project:
    ```bash
    make
    ```
    (O bien, compila tus archivos `.c` manualmente incluyendo `get_next_line.c`, `get_next_line_utils.c`, y tu `main.c`).

3.  To use it, call the `get_next_line()` function in a loop with a valid file descriptor:
    ```c
    #include "get_next_line.h"

    int main()
    {
        int fd;
        char *line;

        fd = open("your_file.txt", O_RDONLY);
        while ((line = get_next_line(fd)) != NULL)
        {
            printf("%s", line);
            free(line);
        }
        close(fd);
        return (0);
    }
    ```
