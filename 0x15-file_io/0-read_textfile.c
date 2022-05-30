#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to POSIX standard output.
 * @filename: A name of file.
 * @letters: The number of letters the file should read abd print.e
 * Return: the actual number of letters it could print or read.
 * if the file cannot be opened, return 0
 * if filename is NULL, return 0
 * if write fails, return 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t opn, rd, wrt;
	char *buffer;

	if (filename == NULL)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);
	opn = open(filename, O_RDONLY);
	rd = read(opn, buffer, letters);
	wrt = write(STDOUT_FILENO, buffer, rd);
	if (opn == -1 || rd == -1 || wrt == -1 || wrt != rd)
	{
		free(buffer);
		return (0);
	}
	free(buffer);
	close(opn);
	return (wrt);
}
