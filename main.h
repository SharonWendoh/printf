#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

int _printf(const char *format, ...);
int _printf_int(int n);
int _print_ch(va_list args);
int _print_str(va_list args);
int _print_pct(va_list args);
int _print_int(va_list args);
char *int_to_str(int n, char *b);
char *strrev(char *s);

#endif /* MAIN_H */