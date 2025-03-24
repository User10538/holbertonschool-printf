#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int print_char(va_list args);
int print_string(va_list args);
int print_integer(va_list args);
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
	if (specifier == 'i' || specifier == 'd')
		return (print_integer(args));

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

/**
 * print_integer - to print i
 * @args: the variable arg list
 *
 * Return: the number of int printed
 */
int print_integer(va_list args)
{
	int i = va_arg(args, int), count = 0, num;
	int divisor = 1;

	 if (i == INT_MIN)
	 {
		 count += _putchar('-');
		 count += _putchar('2');
		 num = 147483648;
	 }
	 
	 else
	    /* Handle negative numbers */
	if (i < 0)
	{
		count += _putchar('-');
		/* convert to positive using int*/
		num = (unsigned int)(-i);
	}
	else 
	{
		num = (unsigned int)(i);
	}

	/* find the divisor, finds the largest power of 10*/

	while ((num / divisor) >= 10)
        divisor *= 10;

	while (divisor)
	{
		/* get the leftmost digit of num*/
		count += _putchar(num / divisor + '0');
		num %= divisor; /*remove the printed digit*/

		divisor /= 10; /*move to the next digit*/


	}
	
	return (count);

}






