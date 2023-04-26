#include "main.h"
/**
 * token_interface - Meant to interact with other token functions, and make
 * them more accessible to other parts of the program.
 * @line: A string containing the raw user input.
 * @delim: A constant string containing the desired delimeter to tokenize line.
 * @token_count: A holder for the amount of tokens in a string.
 * Return: Upon success an array of tokens representing the command. Otherwise
 * returns NULL.
 */
char **token_interface(char *line, const char *delim, int token_count)
{
	char **param_array;

	token_count = count_token(line, delim);
	if (token_count == -1)
	{
		free(line);
		return (NULL);
	}
	param_array = tokenize(token_count, line, delim);
	if (param_array == NULL)
	{
		free(line);
		return (NULL);
	}

	return (param_array);
}

/**
 * count_token - Counts tokens in the passed string.
 * @line: String that is separated by an specified delimeter
 * @delim: The desired delimeter to separate tokens.
 * Return: Upon success the total count of the tokens. Otherwise -1.
 */
int count_token(char *line, const char *delim)
{
	char *str;
	char *token;
	int i;

	str = _strdup(line);
	if (str == NULL)
		return (-1);
	token = strtok(str, delim);
	for (i = 0; token != NULL; i++)
		token = strtok(NULL, delim);
	free(str);
	return (i);
}

/**
 * _strcmp - compares two strings
 * @s1: First string
 * @s2: Second string
 * Return: 0 if strings match. -1 Otherwise.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	if (str_len(s1) != str_len(s2))
		return (-1);
	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (-1);
	}
	return (0);
}

