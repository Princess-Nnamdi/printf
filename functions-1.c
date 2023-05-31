#include "main.h"

/**
 * print_unsigned- prints an unsigned number
 * Description: prints an unsigned number
 * @types: list of arguements
 * @flags: calculates active flags
 * @width: egts width
 * @precision: precision specifier
 * @size: size specifier
 * @buffer: temporary storage
 * Return: number of chars printed
 **/

int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int k = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);

	numb = convert_size_unsgnd(numb, size);
	if (numb == 0)
	{
		buffer[k--] = '0';
		buffer[BUFF_SIZE - 1] = '\0';
	}
	while (numb > 0)
	{
		buffer[k--] = (numb % 10) + '0';
		numb /= 10;
	}
	k++;
	return (write_unsgnd(0, k, buffer, flags, width, precision, size));
}


/**
 * print_octal- prints unsigned number in octal notation
 * Description: prints unsigned number in octal notation
 * @types: list of arguements
 * @flags: calculates active flags
 * @width: egts width
 * @precision: precision specifier
 * @size: size specifier
 * @buffer: temporary storage
 * Return: number of chars printed
 **/

int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);
	unsigned long int init_numb = numb;

	UNUSED(width);
	numb = convert_size_unsgnd(numb, size);
	if (numb == 0)
	{
		buffer[j--] = '0';
		buffer[BUFF_SIZE - 1] = '\0';
	}
	while (numb > 0)
	{
		buffer[j--] = (numb % 8) + '0';
		numb /= 8;
	}
	if (flags & F_HASH && init_numb != 0)
	{
		buffer[j--] = '0';
		j++;
	}
	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal- prints unsigned number in hexadecimal notation
 * Description: prints unsigned number in hexadeciaml notation
 * @types: list of arguements
 * @flags: calculates active flags
 * @width: egts width
 * @precision: precision specifier
 * @size: size specifier
 * @buffer: temporary storage
 * Return: number of chars printed
 **/

int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
	flags, 'x', width, precision, size));
}


/**
 * print_hexa_upper- prints unsigned number in hexadecimal upper notation
 * Description: prints unsigned number in hexadecimal upper notation
 * @types: list of arguements
 * @flags: calculates active flags
 * @width: egts width
 * @precision: precision specifier
 * @size: size specifier
 * @buffer: temporary storage
 * Return: number of chars printed
 **/

int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
	flags, 'X', width, precision, size));
}

/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * @buffer: temporary storage
 * Return: Number of chars printed
 */

int print_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);
	num = convert_size_unsgnd(num, size);
	if (num == 0)
	{
		buffer[i--] = '0';
		buffer[BUFF_SIZE - 1] = '\0';
	}
	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
