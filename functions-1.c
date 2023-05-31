#include "main.h"

/**
 * print_unsigned - prints an unsigned number
 * Description: prints an unsigned number
 * @types: list of arguements
 * @buffer: tmp memory space
 * @flags: calculates active flags
 * @width: egts width
 * @precision: precision specifier
 * @size: size specifier
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
 * print_octal - prints unsigned number in octal notation
 * Description: prints unsigned number in octal notation
 * @types: list of arguements
 * @flags: calculates active flags
 * @buffer: tmp mempry space
 * @width: egts width
 * @precision: precision specifier
 * @size: size specifier
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
