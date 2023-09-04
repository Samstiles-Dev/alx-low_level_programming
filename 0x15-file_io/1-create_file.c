#include "main.h"

/**
 * create_file - A function that creates a file.
 * @filename: A pointer to the files name to be create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: If the function fails - -1.
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	/* Variable Declaration */
	int ftocreate, strtow, file_length_22 = 0;

	if (filename == NULL)
	{
		/* Return null if file is empty */
		return (-1);
	}

	if (text_content != NULL)
	{
		for (file_length_22 = 0; text_content[file_length_22];)
			file_length_22++;
	}

	ftocreate = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	strtow = write(ftocreate, text_content, file_length_22);

	if (ftocreate == -1 || strtow == -1)
	{
		return (-1);
	}

	close(ftocreate);

	return (1);
}
