#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    int written = 0;

    va_start(args, format);

    // Implement _printf logic here

    va_end(args);

    return written;
}

int _putchar(char c)
{
    return write(STDOUT_FILENO, &c, 1);
}

int _puts(char *str)
{
    int len = 0;
    while (str[len])
    {
        _putchar(str[len]);
        len++;
    }
    return len;
}

