#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
/*
 * Header File: main.h
 * Author: 0xTariq-dev, mostafa1jamal1
 * Describtion: Header file contains declarations for functions
 *		used in the ALX Simple Shell project.
 */

/* Global variables */
extern char **environ;

/* Functions in the string.c file */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strncmp(char *s1, char *s2, size_t n);
int _strcmp(char *s1, char *s2);
/**********************/

/**
 * struct command - A struct to hold the command name and arguments passed.
 * @cmd: The command name.
 * @args: The arguments passed to the program.
 * @Gline: A pointer to the full command (line);
 */

typedef struct command
{
	char *cmd;
	char **args;
	char *Gline;
} full_cmd;

/**
 * struct built_in_t - A struct for built-in name and a function pointer.
 * @name: The built-in name.
 * @func: the function pointer of the built-in.
 */

typedef struct built_in_t
{
	char *name;
	void (*func)(full_cmd);
} builtin_t;

/** Prototypes for the functions used by the shell. */

int exec_cmd(const char *pathname, char **argv);
ssize_t prompt(char **line, size_t *buffsize);
char **tokenize(char *string);
full_cmd get_args(char *line);
char *_which(char *cmd);
char *get_envpath();

/* Prototypes for built-in functions */
int built_in(full_cmd c);
void our_exit(full_cmd);

#endif
