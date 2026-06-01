#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Keygen generator for crackme5.
 * @argc: Argument count.
 * @argv: Argument vector (username passed as argv[1]).
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	unsigned int i, sum = 0;
	size_t len;
	char key[7];
	char *mask = "A-CHASING-NEVER-ELEMENTS-BUT-SUSTAINED-EXCELLENCE-IN-EVERY-STEP-THAT-WE-TAKE";

	if (argc != 2)
	{
		printf("Usage: %s username\n", argv[0]);
		return (1);
	}

	len = strlen(argv[1]);

	/* Logic 1: Find offset character from string length */
	key[0] = mask[(len ^ 59) & 63];

	/* Logic 2: Calculate sum of char ascii values */
	for (i = 0; i < len; i++)
		sum += argv[1][i];
	key[1] = mask[(sum ^ 79) & 63];

	/* Logic 3: Multiply characters */
	sum = 1;
	for (i = 0; i < len; i++)
		sum *= argv[1][i];
	key[2] = mask[(sum ^ 85) & 63];

	/* Logic 4: Max char calculation */
	sum = argv[1][0];
	for (i = 0; i < len; i++)
	{
		if ((char)sum < argv[1][i])
			sum = argv[1][i];
	}
	srand(sum ^ 14);
	key[3] = mask[rand() & 63];

	/* Logic 5: Squares sum loop */
	sum = 0;
	for (i = 0; i < len; i++)
		sum += argv[1][i] * argv[1][i];
	key[4] = mask[(sum ^ 239) & 63];

	/* Logic 6: Random iterations loop mapping */
	sum = 0;
	for (i = 0; i < (unsigned int)argv[1][0]; i++)
		sum = rand();
	key[5] = mask[(sum ^ 229) & 63];

	key[6] = '\0';

	printf("%s", key);

	return (0);
}
