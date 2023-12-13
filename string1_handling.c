#include "shell.h"
/**
 *_pts - prints an input string
 *@strg: the string to be printed
 *
 * Return: Nothing
 */
void _pts(char *strg)
{
	int i = 0;

	if (!strg)
		return;
	while (strg[i] != '\0')
	{
		_ptchar(strg[i]);
		i++;
	}
}

/**
 * _ptchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _ptchar(char c)
{
	static int i;
	static char buff[WRITE_BUFF_SIZE];

	if (c == BUFF_FLUSH || i >= WRITE_BUFF_SIZE)
	{
		write(1, buff, i);
		i = 0;
	}
	if (c != BUFF_FLUSH)
		buff[i++] = c;
	return (1);
}
/**
 * _strgcpy - copies a string
 * @dstn: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strgcpy(char *dstn, char *src)
{
	int i = 0;

	if (dsnt == src || src == 0)
		return (dstn);
	while (src[i])
	{
		dstn[i] = src[i];
		i++;
	}
	dstn[i] = 0;
	return (dstn);
}

/**
 * _strgdup - duplicates a string
 * @strg: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strgdup(const char *strg)
{
	int length = 0;
	char *ret;

	if (strg == NULL)
		return (NULL);
	while (*strg++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--strg;
	return (ret);
}
