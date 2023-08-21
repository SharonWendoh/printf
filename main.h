#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _print_ch(va_list args);
int _print_str(va_list args);
int _print_pct(va_list args);


#endif /* MAIN_H */
