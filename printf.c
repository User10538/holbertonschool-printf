#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
/**
 * printf - function that produces output according to a format
 * @format: characters to be printed
 */

int _printf(const char *format, ...)
{
        va_list args;
        int count = 0;
        char *str;

        if (format == NULL)
        return (-1);

        va_start(args, format);

        while (*format)
        {
                if (*format == '%')
                {
                        format++;
                        if(*format == 'c')
                                count += _putchar(va_arg(args, int));

                        else if (*format == 's')
                        {
                                str = va_arg(args, char*);
                                if (str == NULL)
                                str = "(null)";
                                while (*str)
                                count += _putchar(*str++);
                        }
                        else if (*format == '%')
                        {
                                count += _putchar('%');
                        }
                        else /*invalid specifier */
                        {
                                count += _putchar('%');
                                count += _putchar(*format);
                        }
                }
                else
                        count += _putchar(*format);
                format++;
        }
        va_end(args);
        return(count);
}
