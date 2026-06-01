#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - keygen for crackme5
 */
int main(int argc, char *argv[])
{
	char charset[] = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char key[7];
	char *username;
	int n, i, sum, product, max_val, seed, r;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s username\n", argv[0]);
		return (1);
	}
	username = argv[1];
	n = strlen(username);

	/* key[0]: f1(len) = (len ^ 0x3b) & 0x3f */
	key[0] = charset[(n ^ 0x3b) & 0x3f];

	/* key[1]: f2(username, len) = (sum_chars ^ 0x4f) & 0x3f */
	sum = 0;
	for (i = 0; i < n; i++)
		sum += (int)username[i];
	key[1] = charset[(sum ^ 0x4f) & 0x3f];

	/* key[2]: f3(username, len) = (product_chars ^ 0x55) & 0x3f */
	product = 1;
	for (i = 0; i < n; i++)
		product *= (int)username[i];
	key[2] = charset[(product ^ 0x55) & 0x3f];

	/* key[3]: f4 = srand(max_char ^ 0xe), rand() & 0x3f */
	max_val = (int)username[0];
	for (i = 0; i < n; i++)
		if ((int)username[i] > max_val)
			max_val = (int)username[i];
	seed = max_val ^ 0x0e;
	srand((unsigned int)seed);
	r = rand();
	key[3] = charset[r & 0x3f];

	/* key[4]: f5 = (sum(char*char) ^ 0xef) & 0x3f */
	sum = 0;
	for (i = 0; i < n; i++)
		sum += (int)username[i] * (int)username[i];
	key[4] = charset[(sum ^ 0xef) & 0x3f];

	/* key[5]: f6(username[0]) = call rand() username[0] times, (last ^ 0xe5) & 0x3f */
	r = 0;
	for (i = 0; i < (int)username[0]; i++)
		r = rand();
	key[5] = charset[(r ^ 0xe5) & 0x3f];

	key[6] = '\0';
	printf("%s\n", key);
	return (0);
}
