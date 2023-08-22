#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#ifndef MAIN_H
#define MAIN_H
/**
 * struct specifier - structure for different specifiers
 *
 * @s: type of specifier
 * @function: function to perform
 */
typedef struct specifier
{
	char *s;
	int (*function)(va_list);
} format_specifier;

int (*get_specifier(char *format))(va_list);
int _printf(char *format, ...);
int _putchar(char c);
int c(va_list c);
int s(va_list s);