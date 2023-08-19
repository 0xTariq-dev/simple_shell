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

/* Functions in the string.c file */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strncmp(char *s1, char *s2, size_t n);
/**********************/

/**
 * struct command - A struct to hold the command name and arguments passed.
 * @cmd: The command name.
 * @args: The arguments passed to the program.
 */

typedef struct command
{
	char *cmd;
	char **args;
} full_cmd;

/** Prototypes for the functions used by the shell. */

int exec_cmd(const char *pathname, char **argv);
ssize_t prompt(char **line, size_t *buffsize);
char **tokenize(char *string);
full_cmd get_args(char *line);

#endif
