#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - A function that allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)
{
	/* Declare the buffer variable */
	char *buffer_322;

	/* Allocate some memory to the buffer */
	buffer_322 = malloc(sizeof(char) * 1024);

	if (buffer_322 == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: This cannot write to the %s\n", file);
		exit(99);
	}

	return (buffer_322);
}

/**
 * close_file - A function that closes file descriptors.
 * @fd: This is the file descriptor to be closed.
 */
void close_file(int fd)
{
	/* Declare the close file variable */
	int close_322;

	close_322 = close(fd);

	if (close_322 == -1)
	{
		dprintf(STDERR_FILENO, "Error: This cannot close the file fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - A function that copies a files content to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	/* Variables Declaration */
	int file_from_322, file_to_322, read_file_322, write_file_322;
	char *file_buffer_322;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_buffer_322 = create_buffer(argv[2]);
	file_from_322 = open(argv[1], O_RDONLY);
	read_file_322 = read(file_from_322, file_buffer_322, 1024);
	file_to_322 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (file_from_322 == -1 || read_file_322 == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: This cannot read file_from_322 file %s\n", argv[1]);
			free(file_buffer_322);
			exit(98);
		}

		write_file_322 = write(file_to_322, file_buffer_322, read_file_322);
		if (file_to_322 == -1 || write_file_322 == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: This cannot write to %s\n", argv[2]);
			free(file_buffer_322);
			exit(99);
		}

		read_file_322 = read(file_from_322, file_buffer_322, 1024);
		file_to_322 = open(argv[2], O_WRONLY | O_APPEND);

	} while (read_file_322 > 0);

	free(file_buffer_322);
	close_file(file_from_322);
	close_file(file_to_322);

	return (0);
}
