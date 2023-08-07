#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- a function that reads text file print to STDOUT.
 * @filename: filename
 * @letters: num of letters to be read
 * Return: w- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	/* Pointer and Variable declaration */
	char *file_pointer;
	ssize_t ftopen;
	ssize_t writetostdout;
	ssize_t textfile;

	ftopen = open(filename, O_RDONLY);
	if (ftopen == -1)
	{
		return (0);
	}
	file_pointer = malloc(sizeof(char) * letters);
	textfile = read(ftopen, file_pointer, letters);
	writetostdout = write(STDOUT_FILENO, file_pointer, textfile);

	free(file_pointer);
	close(ftopen);
	return (writetostdout);
}
