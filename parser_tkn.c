#include "shell.h"

/**
 * **strg_wrd - splits a string into words. Repeat delimiters are ignored
 * @strg: the input string
 * @de: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strg_wrd(char *strg, char *de)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (strg == NULL || strg[0] == 0)
		return (NULL);
	if (!de)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delim(strg[i], de) && (is_delim(strg[i + 1], de) || !strg[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(strg[i], de))
			i++;
		k = 0;
		while (!is_delim(strg[i + k], de) && strg[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = strg[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strg_wrd2 - splits a string into words
 * @strg: the input string
 * @de: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strg_wrd2(char *strg, char de)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (strg == NULL || strg[0] == 0)
		return (NULL);
	for (i = 0; strg[i] != '\0'; i++)
		if ((strg[i] != de && strg[i + 1] == de) ||
		    (strg[i] != de && !strg[i + 1]) || strg[i + 1] == de)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (strg[i] == de && strg[i] != de)
			i++;
		k = 0;
		while (strg[i + k] != de && strg[i + k] && strg[i + k] != de)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = strg[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
