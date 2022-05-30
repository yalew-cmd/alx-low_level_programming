#include "main.h"

/**
 * create_file - Creates a file.
 * @filename: a pointer to the name of the file.
 * @text_content:  is a NULL terminated string to write to the file
 * Return: 1 on success, -1 on failure
 * if filename is NULL return -1
 */
int create_file(const char *filename, char *text_content)
{
	int opn, wrt, len = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
		{
			len++;
		}
	}
	opn = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wrt = write(opn, text_content, len);
	if (opn == -1 || wrt == -1)
		return (-1);
	close(opn);
	return (1);
}
