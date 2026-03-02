#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: string to evaluate
 * @accept: string containing list of characters to match in s
 *
 * Return: number of bytes in initial segment of s matching accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int i, match;

	while (*s)
	{
		match = 0;
		for (i = 0; accept[i]; i++)
		{
			if (*s == accept[i])
			{
				match = 1;
				break;
			}
		}
		if (match == 0)
			return (count);
		count++;
		s++;
	}
	return (count);
}
