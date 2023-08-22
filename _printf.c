#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFF_SIZE 1024

void print_buffer(char buffer[], int *buff_ind);

int _printf(const char *format, ...)
{
    int i, buff_ind = 0, printed_chars = 0;
    va_list list;
    char buffer[BUFF_SIZE];

    if (format == NULL)
        return (-1);

    va_start(list, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE)
            {
                print_buffer(buffer, &buff_ind);
                printed_chars += buff_ind;
            }
        }
        else
        {
            i++;
            if (format[i] == 'c')
            {
                char c = va_arg(list, int);
                buffer[buff_ind++] = c;
                if (buff_ind == BUFF_SIZE)
                {
                    print_buffer(buffer, &buff_ind);
                    printed_chars += buff_ind;
                }
            }
            else if (format[i] == 's')
            {
                char *str = va_arg(list, char *);
                while (*str != '\0')
                {
                    buffer[buff_ind++] = *str++;
                    if (buff_ind == BUFF_SIZE)
                    {
                        print_buffer(buffer, &buff_ind);
                        printed_chars += buff_ind;
                    }
                }
            }
            else if (format[i] == '%')
            {
                buffer[buff_ind++] = '%';
                if (buff_ind == BUFF_SIZE)
                {
                    print_buffer(buffer, &buff_ind);
                    printed_chars += buff_ind;
                }
            }
        }
    }

    print_buffer(buffer, &buff_ind);
    printed_chars += buff_ind;

    va_end(list);

    return printed_chars;
}

void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
        write(1, &buffer[0], *buff_ind);

    *buff_ind = 0;
}

int main(void)
{
    int len = _printf("Hello, %s! The character is %c and a percent sign %%.\n", "world", 'A');
    printf("Number of characters printed: %d\n", len);
    return 0;
}

