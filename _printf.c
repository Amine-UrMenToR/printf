#include "main.h"
#include <stdarg.h>  // For va_start, va_arg, va_end

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%' && *(format + 1))
        {
            format++;
            if (*format == 'c')
                count += print_char(va_arg(args, int));
            else if (*format == 's')
                count += print_string(va_arg(args, char *));
            else if (*format == '%')
                count += print_char('%');
            else
                count += print_char('%') + print_char(*format);
        }
        else
        {
            count += print_char(*format);
        }

        format++;
    }

    va_end(args);

    return count;
}

/**
 * print_char - Prints a character.
 * @c: The character to print.
 *
 * Return: Number of characters printed.
 */
int print_char(char c)
{
    return write(1, &c, 1);
}

/**
 * print_string - Prints a string.
 * @s: The string to print.
 *
 * Return: Number of characters printed.
 */
int print_string(char *s)
{
    if (s == NULL)
        s = "(null)";
    
    return write(1, s, strlen(s));
}

