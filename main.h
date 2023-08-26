#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#ifndef PRINTF_H
#define PRINTF_H

#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/**
 * struct for_mat - Provide an alternative wording for Struct op
 *
 * @for_mat: The structure or the format 
 * @fmm: The linked function..
 */

struct for_mat
{
	char for_mat;
	int (*fmm)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct for_mat mat_f - Struct op
 *
 * @for_mat: The structure or the format
 * @mat_f: The linked function.
 */

typedef struct for_mat mat_f;

int _printf(const char *for_mat, ...);
int handle__of__print(const char *for_mat, int *y,
va_list the_list, char the_buffer[], int the_flags, int the_width, int the_precision, int the_size);

/************ FUNCTIONS ************/

/* Functions to print numbers */
int print__the__int(va_list types, char the_buffer[],
	int the_flags, int the_width, int the_precision, int the_size);
int print__the__binary(va_list types, char the_buffer[],
	int the_flags, int the_width, int the_precision, int the_size);
int print__the__unsigned(va_list types, char the_buffer[],
	int the_flags, int the_width, int the_precision, int the_size);
int print__the__octal(va_list types, char the_buffer[],
	int the_flags, int the_width, int the_precision, int the_size);
int print__the__hexadecimal(va_list types, char the_buffer[],
	int the_flags, int the_width, int the_precision, int the_size);
int print__the__hexa_upper(va_list types, char the_buffer[],
	int the_flags, int the_width, int the_precision, int the_size);

int print__the__hexa(va_list types, char the_map_to[],
char the_buffer[], int the_flags, char the_flag_ch, int the_width, int the_precision, int the_size);

/* Funtions to print chars and strings */
int print__the__char(va_list types, char the_buffer[],
	int the_flags, int the_width, int the_precision, int the_size);
int print__the__string(va_list types, char the_buffer[],
	int the_flags, int the_width, int the_precision, int the_size);
int print__the__percent(va_list types, char the_buffer[],
	int the_flags, int the_width, int the_precision, int the_size);

/* Funcion to print memory address */
int print__the__pointer(va_list types, char the_buffer[],
	int the_flags, int the_width, int the_precision, int the_size);

/* Function to print non printable characters */
int print__non__the__printable(va_list types, char the_buffer[],
	int the_flags, int the_width, int the_precision, int the_size);

/* Funciotns to handle other specifiers */
int get__the__flags(const char *for_mat, int *y);
int get__the__width(const char *for_mat, int *y, va_list _list);
int get__the__precision(const char *for_mat, int *y, va_list _list);
int get__the__size(const char *for_mat, int *y);

/*Function to print a string in rot 13*/
int print__the__rot13string(va_list types, char the_buffer[],
	int the_flags, int the_width, int the_precision, int the_size);

/*Function to print string in reverse*/
int print__the__reverse(va_list types, char the_buffer[],
	int the_flags, int the_width, int the_precision, int the_size);

/* width handler */
int handle__the__write__char(char u, char the_buffer[],
	int the_flags, int width, int precision, int size)
int write__the__number(int is_negative, int ind, char the_buffer[],
	int the_flags, int width, int precision, int size)
int write__the__num(int ind, char the_buffer[],
	int the_flags, int width, int prec,
	int length, char _padd, char extra_c)
int write__the__pointer(char the_buffer[], int ind, int length,
	int width, int the_flags, char _padd, char extra_c, int padd_start)

int write__the__unsgnd(int is_negative, int ind,
	char the_buffer[],
	int the_flags, int width, int precision, int size)

/************ UTILS ************/
int is__the__printable(char);
int append__hexa__the__code(char, char[], int);
int is__the__digit(char);

long int convert__size__the__number(long int _num, int size);
long int convert__size__the__unsgnd(unsigned long int _num, int size);

#endif /* PRINTF_H */
