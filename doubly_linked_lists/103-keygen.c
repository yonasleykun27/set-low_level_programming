#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * get_key - generates a 6-character key for a given username
 * @username: the username string
 * @n: length of the username
 * @key: output buffer for the generated key
 *
 * Return: nothing, fills key array
 */
static void get_key(char *username, int n, char *key)
{
	char cs[] = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+";
	char cs2[] = "4mjW6fxqZeF3Qa1rPhdKIouk";
	char charset[65];
	int i, sum, product, max_val, r;

	strcpy(charset, cs);
	strcat(charset, cs2);
	key[0] = charset[(n ^ 0x3b) & 0x3f];

	sum = 0;
	for (i = 0; i < n; i++)
		sum += (int)username[i];
	key[1] = charset[(sum ^ 0x4f) & 0x3f];

	product = 1;
	for (i = 0; i < n; i++)
		product *= (int)username[i];
	key[2] = charset[(product ^ 0x55) & 0x3f];

	max_val = (int)username[0];
	for (i = 0; i < n; i++)
		if ((int)username[i] > max_val)
			max_val = (int)username[i];
	srand((unsigned int)(max_val ^ 0x0e));
	r = rand();
	key[3] = charset[r & 0x3f];

	sum = 0;
	for (i = 0; i < n; i++)
		sum += (int)username[i] * (int)username[i];
	key[4] = charset[(sum ^ 0xef) & 0x3f];

	r = 0;
	for (i = 0; i < (int)username[0]; i++)
		r = rand();
	key[5] = charset[(r ^ 0xe5) & 0x3f];
	key[6] = '\0';
}

/**
 * main - entry point, prints key for given username
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	char key[7];

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s username\n", argv[0]);
		return (1);
	}
	get_key(argv[1], strlen(argv[1]), key);
	printf("%s\n", key);
	return (0);
}
