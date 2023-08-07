#include "main.h"

/**
 * append_text_to_file - A function that appends text at the end of a file.
 * @filename: A pointer to the files name.
 * @text_content: This contains the string to add to the end of the file.
 *
 * Return: If fails - -1 else -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	/* Variable Declarations */
	int open_file_22, write_to_file, file_len_22 = 0;

	if (filename == NULL)
	{
		/* return if filename is empty */
		return (-1);
	}

	if (text_content != NULL)
	{
		for (file_len_22 = 0; text_content[file_len_22];)
			file_len_22++;
	}

	open_file_22 = open(filename, O_WRONLY | O_APPEND);
	write_to_file = write(open_file_22, text_content, file_len_22);

	if (open_file_22 == -1 || write_to_file == -1)
	{
		return (-1);
	}

	close(open_file_22);

	return (1);
}
