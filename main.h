#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

typedef int (*format_function)(va_list);

/**
 * struct format_mapper - struct to map format specifiers to
 * their respective handler functions.
 * @specifier: first member.
 * @handler: second member.
 */
typedef struct format_mapper
{
	char specifier;
	format_function handler;
} format_mapper_t;

int _printf(const char *format, ...);
int _print_ch(va_list args);
int _print_str(va_list args);
int _print_pct(va_list args);
int _print_int(va_list args);
int _print_binary(va_list args);
char *int_to_str(int n, char *b);
char *strrev(char *s);
void init_format_handlers(format_mapper_t *format_mappers);
format_function fetch_handler
(format_mapper_t *format_mappers, char specifiers);
char *unsigned_int_to_binary(unsigned int n);

#endif /* MAIN_H */
