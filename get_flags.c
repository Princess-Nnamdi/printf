#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int a, curr_i;
	int flags = 0;
	const char flags_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flags_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (a = 0; flags_CH[a] != '\0'; a++)
			if (format[curr_i] == flags_CH[a])
			{
				flags |= flags_ARR[a];
				break;
			}

		if (flags_CH[a] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}

