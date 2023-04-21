#include "main.h"
/**
 * main - main function
 * @argc: argument count
 * @argv: argumetn vector
 * Return: zero
*/
int main(int argc, char **argv)
{
	char *prompt = "(My_Shell)$ ";
	char *lineptr = NULL, *lineptr_copy = NULL, *token;
	const char *delim = " \n";
	size_t n = 0;
	ssize_t nchars_read;
	int i, num_tokens = 0;

	(void)argc;
	while (1)
	{
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);
		if (nchars_read == -1)
		{
			return (-1);
		}
		lineptr_copy = malloc(sizeof(char) * nchars_read);
		if (lineptr_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
		strcpy(lineptr_copy, lineptr);
		token = strtok(lineptr, delim);
		while (token != NULL) /* determine how many tokens are there*/	
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;
		argv = malloc(sizeof(char *) * num_tokens);
		token = strtok(lineptr_copy, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		execmd(argv);
	}
	free(lineptr_copy);
	free(lineptr);
	return (0);
}
