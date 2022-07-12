#include "main.h"
#include <math.h>

/**
 * print_octal - gets pointer to a string containing a octal
 * representation given number
 * @args: the arguments
 *
 * Return: a pointer to a string or NULL if it fails
 */
char *print_hex_x(va_list args)
{
	char *str;
	unsigned int num = va_arg(args, unsigned int), pow = 1;
	int i = 0, digit;

	while (pow <= num / 16)
	{
		pow *= 16;
		i++;
	}

	str = malloc(sizeof(char) * (i + 2));
	if (str == NULL)
		return (NULL);

	str[i + 1] = '\0';

	if (num == 0)
		str[0] = '0';

	while (num > 0)
	{
		digit = num % 16;
		if (digit > 9)
			str[i] = (digit - 10) + 'a';
		else
			str[i] = digit + '0';
		num /= 16;
		i--;
	}

	return (str);
}
