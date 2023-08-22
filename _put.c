#include "main.h"
#include <unistd.h> 

#define OUTPUT_BUF_SIZE 1024 
#define BUF_FLUSH -1

/**
 * _puts - Outputs a string followed by a line break or prints a string with newline.
 * @str: The string for output.
 *
 * Return: Number of characters printed.
 */
int _puts(char *str) {
    char *a = str;
    while (*str)
        _putchar(*str++);
    _putchar('\n'); 
    return (str - a + 1); 
}

/**
 * _putchar - Outputs the character c to the standard output stdout.
 * @c: The character for output.
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(int c) {
    static int i;
    static char buf[OUTPUT_BUF_SIZE];

    if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE) {
        write(1, buf, i);
        i = 0;
    }
    if (c != BUF_FLUSH)
        buf[i++] = c;
    return (1);
}
