#include "main.h"
/**
 * print_char - function that prints a char
 * @types: arguments
 * @buffer: Buffer array to print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size
 * Return: Number of characters printed
 */
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char c = va_arg(types, int);
return (handle_write_char(c, buffer, flags, width, precision, size));
}
/**
 * print_string - function that prints a string
 * @types: arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int len = 0, i;
char *string = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (string == NULL)
{
string = "(null)";
if (precision >= 6)
string = "      ";
}
while (string[len] != '\0')
len++;
if (precision >= 0 && precision < len)
len = precision;
if (width > len)
{
if (flags & F_MINUS)
{
write(1, &string[0], len);
for (i = width - len; i > 0; i--)
write(1, " ", 1);
return (width);
}
else
{
for (i = width - len; i > 0; i--)
write(1, " ", 1);
write(1, &string[0], len);
return (width);
}
}
return (write(1, string, len));
}
/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
UNUSED(types);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
return (write(1, "%%", 1));
}
/**
 * print_int - function printing an int
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
int is_negative = 0;
long int n = va_arg(types, long int);
unsigned long int num;
n = convert_size_number(n, size);
if (n == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
num = (unsigned long int)n;
if (n < 0)
{
num = (unsigned long int)((-1) * n);
is_negative = 1;
}
while (num > 0)
{
buffer[i--] = (num % 10) + '0';
num /= 10;
}
i++;
return (write_number(is_negative, i, buffer, flags, width, precision, size));
}
/**
 * print_binary - function printing an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to print
 * @flags: Calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size
 * Return: Numbers of characters to print
 */
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
unsigned int a, b, i, total;
unsigned int r[32];
int compter;
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
a = va_arg(types, unsigned int);
b = 2147483648; /* (2 ^ 31) */
r[0] = a / b;
for (i = 1; i < 32; i++)
{
b /= 2;
r[i] = (a / b) % 2;
}
for (i = 0, total = 0, compter = 0; i < 32; i++)
{
total += r[i];
if (total || i == 31)
{
char c = '0' + r[i];
write(1, &c, 1);
compter++;
}
}
return (compter);
}
