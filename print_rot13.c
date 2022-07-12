#include "main.h"
#include <string.h>

/**
 * rot13 - encodes a string using ROT13
 * @str: the string
 *
 * Return: returns a pointer to the modified string
 */
char *rot13(char *str)
{
	int i = 0, j, count = 52, is_lwr_caps = 0, is_upr_caps = 0;
	char *keys = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *encs = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	while (*(str + i) != '\0')
	{
		is_lwr_caps = *(str + i) >= 'a' && *(str + i) <= 'z';
		is_upr_caps = *(str + i) >= 'A' && *(str + i) <= 'Z';

		j = 0;
		while (j < count && (is_lwr_caps || is_upr_caps))
		{
			if (*(str + i) == *(keys + j))
			{
				*(str + i) = *(encs + j);
				break;
			}
			j++;
		}

		i++;
	}
	return (str);
}

/**
 * print_rot13 - encodes the passed string in rot13 encrytion
 * and returns a pointer to the encoded string
 * @args: the arguments
 *
 * Return: pointer to a string or NULL if it fails
 */
char *print_rot13(va_list args)
{
	char *str;
	char *s_arg = va_arg(args, char *);
	int len;

	if (s_arg == NULL)
		s_arg = "(ahyy)";

	len = strlen(s_arg);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	strcpy(str, s_arg);
	rot13(str);

	return (str);
}
