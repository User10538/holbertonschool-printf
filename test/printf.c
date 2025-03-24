#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int print_char(va_list args);
int print_string(va_list args);
int handle_specifier(char specifier, va_list args);

/**
 * _printf -  function that produces output according to a format
 * @format: is the format
 *
 * Return: number of characters
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;


	if (format == NULL)
	return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (!*format)
				return (-1);

			count += handle_specifier(*format, args);
		}
		else
			count += _putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}

/**
 * handle_specifier - handle the format specifiers
 * @specifier: specifier
 * @args: the arg list.
 *
 * Return: return specifiers
 */
int handle_specifier(char specifier, va_list args)
{
	if (specifier == 'c')
		return (print_char(args));
	if (specifier == 's')
		return (print_string(args));
	if (specifier == '%')
		return (_putchar('%'));

	_putchar('%');
	return (_putchar(specifier) + 1);
}

/**
 * print_char - to print char
 * @args: the variable arg list
 *
 * Return: the number of character printed.
 */
int print_char(va_list args)
{
	return (_putchar(va_arg(args, int)));
}

/**
 * print_string - to print the string
 * @args: the variable arg list
 *
 * Return: the number of char printed.
 */
int print_string(va_list args)
{
	char *str;
	int count = 0;

	str = va_arg(args, char*);
	if (str == NULL)
		str = "(null)";

	while (*str)
		count += _putchar(*str++);

	return (count);
}
