#include "main.h"
#include <math.h>

/**
 * print_p_hex - gets pointer to a string containing a hex
 * representation of a void *
 * @args: the arguments
 *
 * Return: a pointer to a string or NULL if it fails
 */
char *print_p_hex(va_list args)
{
	char *str;
	void *ptr = va_arg(args, void *);
	unsigned long int num = (unsigned long int)ptr, pow = 1;
	int count = 1, i = 2, digit;

	while (pow <= num / 16)
	{
		pow *= 16;
		count++;
	}

	str = malloc(sizeof(char) * (count + 3));
	if (str == NULL)
		return (NULL);

	str[0] = '0';
	str[1] = 'x';

	if (num == 0)
		str[i++] = '0';

	for (; i < count + 2; i++)
	{
		digit = num / pow;
		if (digit > 9)
			str[i] = (digit - 10) + 'a';
		else
			str[i] = digit + '0';
		num %= pow;
		pow /= 16;
	}

	str[i] = '\0';
	return (str);
}
