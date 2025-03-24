#include <stdio.h>
#include "main.h"
#include <unistd.h>


/**
 * _putchar - to print
 * @c: char
 * Return: Always 0 (Success)
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
