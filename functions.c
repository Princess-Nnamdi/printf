#include "main.h"


int _printf(const char *format, ...)
{
    int compteur = 0; // to keep track of the number of characters printed

    const char *pontr = format; // pointer to iterate through the format string

    while (*pontr != '\0') {
        if (*pontr == '%') {
            pontr++; // move past the '%'

            // handle the conversion specifiers with if-else statements
            if (*pontr == 'c') {
                // fetch the next argument of type int (promoted to int in variadic functions)

                int c = va_arg(args, int);
                putchar(c);
                compteur++;
            } else if (*pontr == 's') {
                // fetch the next argument of type char*
                char *str = va_arg(args, char*);
                while (*str != '\0') {
                    putchar(*str);
                    compteur++;
                    str++;
                }
            } else if (*pontr == '%') {
                putchar('%');
                compteur++;
            } else {
                putchar(*pontr);
                compteur++;
            }
        } else {
            putchar(*pontr);
            compteur++;
        }

        pontr++;
    }

    return compteur;
}

