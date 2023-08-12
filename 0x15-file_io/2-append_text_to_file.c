#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to be added to the end of the file.
 *
 * Return: If the function encounters errors - returns -1.
 * If the file doesn't exist or the user lacks write permissions - returns -1.
 * Otherwise, returns 1 on successful append.
 */
int append_text_to_file(const char *filename, char *text_content)
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
file_descriptor = open(filename, O_WRONLY | O_APPEND);

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