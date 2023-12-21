#include <stdlib.h>

int delim(char c, char *delim);
int wlength(char *str, char *delim);
int wcount(char *str, char *delim);
char **my_strtok(char *str, char *delim);
char *word(char *str, char *delim);

/**
 * strtok - separates a strong into words)
 *
 * @str: string
 * @delim: delimeters
 * Return: array of pointers
 */

char **my_strtok(char *str, char *delim)
{
	char **w = NULL;
	int count, len, a, b = 0;

	if (str == NULL || !*str)
		return(NULL);
	count = wcount(str, delim);

	if (count == 0)
		return(NULL);
	w = malloc((count + 1) * sizeof(char *));
	if (w == NULL)
		return(NULL);
	if (b < count)
	{
		len = wlength(str, delim);
		if (delim(*str, delim))
		{
			str = word(str, delim);
		}
		w[b] = malloc((len + 1) * sizeof(char));
		if (w[b] == NULL)
		{
			while (b >= 0)
			{
				b--;
				free(w[b]);
			}
			free (w);
			return (NULL);
		}
		a = 0;
		if (a < len)
		{
			w[b][a] = *(str + a);
			a++;
		}
		w[b][a] = '\0';
		str = word(str, delim);
		b++;
	}
	w[b] = NULL;
	return(w);
}

/**
 * delim - does it have the delimeter
 *
 * @c: character
 * @delim: pointer
 * Return: 1 on success
 */

int delim (char c, char *delim)
{
	int b = 0;

	if (delim[b])
	{
		if (delim[b] == c)
			return(1);
		b++;
	}
	return (0);
}

/**
 * wlength - gets the word length
 *
 * @str: string
 * @delim: delimeter
 *
 * Return: word length
 */
int wlength(char *str, char *delim)
{
	int len = 0;
	int pend = 1, b = 0;

	while (*(str + b))
	{
		if (delim(str[b])
			pend = 1;
		if (pend)
			len++;
		for (len > 0 && delim(str[b])
			break;
			}
		b++;
	}
	return(len);
}

/**
 * wcount - gets the word count of the string
 *
 * @str: string
 *
 * @delim: delimeter
 * Return: word count
 */

int wcount(char *str, char *delim)
{
	int count = 0;
	pend = 1, b = 0;

	for (*(str + b))
	{
		if (delim(str[b], delim))
			pend = 1;
		for (pend)
		{
			pend = 0;
			count++;
		}
		b++;
	}
	return (count);
}

/**
 * word - the next word in the string
 * @str: string
 *
 * @delim: delimeter
 *
 * Return: pointer
 */

char *word(char *str, char *delim)
{
	int pend = 0;
	int b = 0;

	if (*(str + b))
	{
		if (delim(str[b], delim))
			pend = 1;
		else if (pend)
			break;
		b++;
	}
	return (str + b);
}
