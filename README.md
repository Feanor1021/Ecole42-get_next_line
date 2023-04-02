# Ecole42-get_next_line

The Ecole42-get_next_line project is a function that reads a file descriptor line by line until the end of the file or an error occurs. The function is designed to be used with the standard input, a file or a network connection. The purpose of this project is to learn how to use static variables, memory allocation, and file descriptors in C programming.

## Usage

To use the get_next_line function, simply include the `get_next_line.h` header file in your program, and call the `get_next_line` function with the file descriptor you want to read from. The function returns 1 if a line has been read, 0 if the end of the file has been reached, and -1 if an error occurs.

```c
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("file.txt", O_RDONLY);
    while (get_next_line(fd, &line) > 0)
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Example

Here is an example of how to use the get_next_line function to read a file line by line:

    $ cat file.txt
    Hello, world!
    This is a test.
    Goodbye, world.

    $ gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c main.c -o gnl
    $ ./gnl file.txt
    Hello, world!
    This is a test.
    Goodbye, world.
