#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char *allocate_buffer(char *file);
void close_file(int fd);

/**
 * allocate_buffer - Allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *allocate_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_descriptor - Close a file descriptor.
 * @fd: The file descriptor to be closed.
 */
void close_descriptor(int fd)
{
int close_result;

close_result = close(fd);

if (close_result == -1)
{
dprintf(STDERR_FILENO, "Error: Unable to close file descriptor %d.\n", fd);
exit(100);
}
}

/**
 * main - Copy the contents of one file to another.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the command-line arguments.
 *
 * Return: 0 on success.
 *
 * Description: Exit codes:
 * 97: Incorrect argument count.
 * 98: Source file cannot be read.
 * 99: Destination file cannot be created or written to.
 * 100: Issues closing file descriptors.
 */
int main(int argc, char *argv[])
{
int source_fd, dest_fd, read_result, write_result;
char *buffer;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp source_file destination_file\n");
exit(97);
}

buffer = allocate_buffer(argv[2]);
source_fd = open(argv[1], O_RDONLY);

read_result = read(source_fd, buffer, 1024);

dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

do {
if (source_fd == -1 || read_result == -1)
{
dprintf(STDERR_FILENO, "Error: Unable to read from source file %s\n", argv[1]);
free(buffer);
exit(98);
}

write_result = write(dest_fd, buffer, read_result);

if (dest_fd == -1 || write_result == -1)
{
dprintf(STDERR_FILENO,
"Error: Unable to write to destination file %s\n", argv[2]);
free(buffer);
exit(99);
}

read_result = read(source_fd, buffer, 1024);

dest_fd = open(argv[2], O_WRONLY | O_APPEND);
} while (read_result > 0);

free(buffer);


close_descriptor(source_fd);
close_descriptor(dest_fd);

return (0);
}
