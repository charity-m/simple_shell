#include "shell.h"
/**
 * _strgcomp - performs lexicogarphic comparison of two strings.
 * @s1: the first string
 * @s2: the second string
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strgcomp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * strts_wth - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *strts_wth(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strgct - concatenates two strings
 * @dstn: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strgct(char *dstn, char *src)
{
	char *ret = dstn;

	while (*dstn)
		dstn++;
	while (*src)
		*dstn++ = *src++;
	*dstn = *src;
	return (ret);
}
/**
 * _strglen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strglen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}
