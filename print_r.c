#include "main.h"
#include <string.h>

/**
 * print_r - get a pointer to a reversed string of the passed string
 * @args: the arguments
 *
 * Return: pointer to a string or NULL if it fails
 */
char *print_r(va_list args)
{
	char *str;
	char *s_arg = va_arg(args, char *);
	int len;

	if (s_arg == NULL)
		s_arg = "(llun)";

	len = strlen(s_arg);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);

	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = *s_arg;
		s_arg++;
		len--;
	}
	return (str);
}
