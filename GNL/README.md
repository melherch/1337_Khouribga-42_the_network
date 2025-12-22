*This project has been created as part of the 42 curriculum by ***mel-herc***.*

# Description
The **get_next_line** project consists of implementing a C function that reads a file descriptor line by line and returns each line on successive calls.

The main goal of this project is to understand low-level file I/O in Unix systems, particularly the behavior of the `read()` system call, buffer management, and dynamic memory allocation. The function must handle arbitrary file sizes efficiently and work correctly with different file descriptors.

This project also introduces the concept of maintaining state between function calls using **static variables**.

# Instructions

####    Compilation

Since the `get_next_line` function relies on reading data from a file descriptor, the buffer size used by the `read()` system call must be configurable at compile time.

To achieve this, the macro `BUFFER_SIZE` is defined using the compiler flag:

```
-D BUFFER_SIZE=n
```
where `n` represents the desired buffer size.

This allows the buffer size to be modified dynamically during evaluation.

The project ***must compile correctly both with and without*** the
`-D BUFFER_SIZE` flag. When the flag is ***not provided, a default buffer size defined in the code will be used***.

####    Example Compilation

The project can be compiled using the following command, where a buffer size of 42 is specified:
```
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c
```
# Resources

[The universal I/O file](https://man7.org/tlpi/download/TLPI-04-File_IO_The_Universal_IO_Model.pdf)


[static variables.](https://www.tutorialspoint.com/cprogramming/c_static_variables.htm)

[syscalls.](https://youtu.be/9-IW2MRtmfc?si=fPMX25v75hgfPf2b)

more about: [read(), open(), close().](https://labs.bilimedtech.com/operating-systems/4/index.html)

[Lorem Ipsum.](https://www.lipsum.com/)

#### AI usage:

`Artificial Intelligence tools` were used in accordance with the 42 guidelines. They were employed to refine and validate my understanding of the theoretical concepts studied by comparing my own explanations with AI feedback.
AI was also used to assist in structuring and improving the clarity of this README file.
No `AI tools` were used to generate or write the project’s source code.

# Additional section

`get_next_line` keeps a persistent `stash` per file descriptor that stores unread data between calls. On each call, it first checks whether the stash already contains a `newline`; if not, it repeatedly `reads` from the file descriptor into a `temporary buffer` and `appends` this data to the stash until a `newline is found` or `EOF` occurs. Once a newline is present (or EOF is reached), the function `extracts` the `next line` from the stash, including the newline if it exists, returns that line to the caller, and `updates` the stash to keep only the remaining unread data for the next call. If EOF is reached and no data remains, it cleans up the stash and returns `NULL`.