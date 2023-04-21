#include "main.h"
/**
 * execmd - help us get path of commands
 * @argv: argument vector
*/
void execmd(char **argv)
{
	char *cmd = NULL, *actual_cmd = NULL;

	if (argv)
	{
		cmd = argv[0];
		actual_cmd = get_location(cmd);
		if (execve(actual_cmd, argv, NULL) == -1)
		{
			perror("Error:");
		};
	}
}
