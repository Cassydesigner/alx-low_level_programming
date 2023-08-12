#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Read text file and print to standard output (STDOUT).
 * @filename: The name of the text file to be read.
 * @letters: The number of letters (characters) to be read and printed.
 * Return: The actual number of bytes read and printed on success,
 * or 0 on failure or if filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
char *buffer;
ssize_t file_descriptor;
ssize_t total_bytes_read;
ssize_t bytes_written;
file_descriptor = open(filename, O_RDONLY);
if (file_descriptor == -1)
return (0);
buffer = malloc(sizeof(char) * letters);
total_bytes_read = read(file_descriptor, buffer, letters);
bytes_written = write(STDOUT_FILENO, buffer, total_bytes_read);
free(buffer);
close(file_descriptor);
return (bytes_written);
}
