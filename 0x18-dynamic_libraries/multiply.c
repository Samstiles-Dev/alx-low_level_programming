#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * main - this is the main function, multiply 2 big number strings
 * @argc: the number of arguments
 * @argv: the argument vector
 *
 * Return: Always 0 on success.
 */
int main(int argc, char **argv)
{
	char *res;
	int a, c, x;

	if (argc != 3)
		printf("Error\n"), exit(98);

	x = _strlen(argv[1]) + _strlen(argv[2]);
	res = big_multiply(argv[1], argv[2]);
	c = 0;
	a = 0;
	while (c < x)
	{
		if (res[c])
			a = 1;
		if (a)
			_putchar(res[c] + '0');
		c++;
	}
	if (!a)
		_putchar('0');
	_putchar('\n');
	free(res);
	return (0);
}

/**
 * _strlen - this function returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int k = 0;

	while (*s++)
		k++;
	return (k);
}

/**
 * _isdigit - this function checks if char is digit
 * @c: the character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * big_multiply - this function multiply two big number strings
 * @s1: this is the 1st big number string
 * @s2: this is the 2nd big number string
 *
 * Return: the product big number string
 */
char *big_multiply(char *s1, char *s2)
{
	char *r;
	int number1, number2, a, b, c, x;

	number1 = _strlen(s1);
	number2 = _strlen(s2);
	r = malloc(a = x = number1 + number2);
	if (!r)
		printf("Error\n"), exit(98);
	while (a--)
		r[a] = 0;

	for (number1--; number1 >= 0; number1--)
	{
		if (!_isdigit(s1[number1]))
		{
			free(r);
			printf("Error\n"), exit(98);
		}
		a = s1[number1] - '0';
		c = 0;

		for (number2 = _strlen(s2) - 1; number2 >= 0; number2--)
		{
			if (!_isdigit(s2[number2]))
			{
				free(r);
				printf("Error\n"), exit(98);
			}
			b = s2[number2] - '0';

			c += r[number1 + number2 + 1] + (a * b);
			r[number1 + number2 + 1] = c % 10;

			c /= 10;
		}
		if (c)
			r[number1 + number2 + 1] += c;
	}
	return (r);
}
