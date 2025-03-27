Background Context

/*****Write our own printf function.*****/

====This function produces output according to a format====

1. c
2. s
3. %
4. d
5. i

====Features====

Note :

Not required to reproduce the buffer handling of the C library printf function
Not required to have to handle the flag characters
Not required to have to handle field width
Not required to have to handle precision
Not requiredcto have to handle the length modifiers


====It handles the following cases====

1. %s - Prints a string: The corresponding argument should be a pointer to a null-terminated character array.

2. %c - Prints a char: The corresponding argument should be a character value.

3. % - Prints a %: To include a literal '%' character in your output, use the '%%' format specifier.

4. %d - Print a decimal (base 10) number: The corresponding argument should be an integer value.

5. %i - Prints an int (base 10): The corresponding argument should be an integer value.


====Installation====

1. Clone the repository.

2. Git Configuration.


====Compiling and executing:====

alex@ubuntu:~/c/printf$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c
alex@ubuntu:~/c/printf$ ./printf


====Credits====
Ying Tai
Jarryd Barrah
Sophie Kyi Oo
