#include "main.h"

/**
 * create_file - Creates a file and writes content to it.
 * @filename: A pointer to the name of the file to be created.
 * @text_content: A pointer to the string to be written to the file.
 *
 * Return: If the function fails to create or write - returns -1.
 *         Otherwise, returns 1 to indicate success.
 */
int create_file(const char *filename, char *text_content)
{
int file_descriptor;
int write_result;
int content_length = 0;

if (filename == NULL)
return (-1);

if (text_content != NULL)
{
for (content_length = 0; text_content[content_length]; content_length++)
	;
}

file_descriptor = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);


if (file_descriptor == -1)
return (-1);

write_result = write(file_descriptor, text_content, content_length);

if (write_result == -1)
{
close(file_descriptor);
return (-1);
}
close(file_descriptor);

return (1);
}
