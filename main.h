#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * struct builtin_d - Defines the builtins functions.
 * @built: The name of the build in command.
 * @f: A pointer to the right builtin function.
 */
typedef struct builtin_d
{
	char *built;
	void (*f)(char *);
} builtin_t;

void execmd(char **argv);
char *get_location(char *command);

/*Builtin functions*/
int built_in(char **, char *);
void (*check_built_ins(char *))(char *);
void exit_b(char *);
void env_b(char *);
void cd_b(char *);

/*functions*/
extern char **environ;

char **token_interface(char *, const char *, int);
int count_token(char *, const char *);
int _strcmp(char *, char *);

/*path handling*/
char **tokenize(int, char *, const char *);
char *path_finder(char *);
int find_path(char *);
char **tokenize_path(int, char *);
char *search_directories(char **, char *);
char *build_path(char *, char *);

#endif
