#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#ifndef PRINTF_H
#define PRINTF_H

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED  2

/**
 * struct parameters - parameters struct
 *
 * @unsign: Flag indicating an unsigned value
 *
 * @plus_flag: If the plus_flag is specified
 * @space_flag: If the hashtag_flag is specified
 * @hashtag_flag: If the _flag is specified
 * @zero_flag: If the _flag is indicated
 * @minus_flag: If the _flag is specified
 *
 * @width: when a field width is indicated
 * @precision: when the field precision is specified
 *
 * @h_modifier: if the h modifier is specified
 * @l_modifier: if the l modifier is specified
 *
 */

 typedef struct parameters {
    unsigned int unsign		: 1;

	unsigned int plus_flag :  1;
	unsigned int space_flag	: 1;
	unsigned int hashtag_flag : 1;
	unsigned int zero_flag : 1;
	unsigned int minus_flag	: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier	: 1;
	unsigned int l_modifier	: 1;
} 
params_t;

/**
 * struct specifier - Struct token
 *
 * @specifier:format specifier _ format token
 * @f: The function associated or The corresponding function
 */

 typedef struct specifier {

	char *specifier;
	int (*f)(va_list, params_t *);
} 
specifier_t;

/* print_functions.c module */
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);

/* _put.c module */
int _puts(char *str);
int _putchar(int c);

/* specifier.c module */
int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);

/* number.c module */
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

/* convert_number.c module */
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);

/* simple_printers.c module */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);

/* params.c module */
void init_params(params_t *params, va_list ap);

/* string_fields.c modoule */
char *get_precision(char *p, params_t *params, va_list ap);

/* print_number.c module */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

/* _prinf.c module */
int _printf(const char *format, ...);

#endif
