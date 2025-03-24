#include <stdio.h>
#include "main.h"


/**
 * main -  prints _putchar, followed by a new line
 * description: putchar
 * Return: Always 0 (Success)
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
