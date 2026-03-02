#include "main.h"

/**
 * print_triangle - prints a triangle, followed by a new line
 * @size: the size of the triangle
 */
void print_triangle(int size)
{
	int row, spaces, hashes;

	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (row = 1; row <= size; row++)
		{
			for (spaces = size - row; spaces > 0; spaces--)
			{
				_putchar(' ');
			}
			for (hashes = 0; hashes < row; hashes++)
			{
				_putchar('#');
			}
			_putchar('\n');
		}
	}
}
