#include "main.h"
#include <string.h>

/**
 * get_hex - Get the hex object
 * @num: the number
 *
 * Return: string representation of the hex
 */
char *get_hex(int num)
{
	char *hex = malloc(sizeof(char) * 5);
	int dig_1 = num / 16, dig_2 = num % 16;

	hex[0] = '\\';
	hex[1] = 'x';
	hex[2] = dig_1 < 9 ? dig_1 + '0' : (dig_1 - 10) + 'A';
	hex[3] = dig_2 < 9 ? dig_2 + '0' : (dig_2 - 10) + 'A';
	hex[4] = '\0';

	return (hex);
}

/**
 * print_S_hex - get a pointer to a formatted string containing the
 * passed string with non printable characters in hex
 * @args: the arguments
 *
 * Return: pointer to a string or NULL if it fails
 */
char *print_S_hex(va_list args)
{
	char *str, *temp_hex;
	char *s_arg = va_arg(args, char *);
	int len, i = 0, j = 0, k = 0, non_print_count = 0;

	if (s_arg == NULL)
		s_arg = "(null)";
	len = strlen(s_arg);
	while (i < len)
	{
		if ((s_arg[i] > 0 &&  s_arg[i] < 32) || (s_arg[i] >= 127))
			non_print_count++;
		i++;
	}

	str = malloc(sizeof(char) * (len + non_print_count * 3 + 1));
	if (str == NULL)
		return (NULL);
	k = 0;
	for (i = 0; s_arg[i] != '\0'; i++)
	{
		if ((s_arg[i] > 0 &&  s_arg[i] < 32) || (s_arg[i] >= 127))
		{
			temp_hex = get_hex((unsigned int)s_arg[i]);
			for (j = 0; temp_hex[j] != '\0'; j++)
			{
				str[k] = temp_hex[j];
				k++;
			}

			free(temp_hex);
		}
		else
		{
			str[k] = s_arg[i];
			k++;
		}
	}
	str[k] = '\0';
	return (str);
}
