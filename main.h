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
#include <stdarg.h>
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
 * @prog_name: the name the the program called by
 * @c_cmd_num: the comulative number of given commands
 */

typedef struct command
{
	char *cmd;
	char **args;
	char *Gline;
	char *prog_name;
	int c_cmd_num;
	int st;
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

int exec_cmd(full_cmd c);
ssize_t get_input(char **line, size_t *buffsize);
void print_prompt(void);
char **tokenize(char *string);
full_cmd get_args(char *line);
char *_which(full_cmd c);
char *get_envpath();
void _free(void *p1, ...);
void print_err_m(char *prog_name, int c);
void print_notfound(char *prog_name, int c, char *cmd);

/* Prototypes for built-in functions */
int built_in(full_cmd c);
void our_exit(full_cmd c);
void Print_env(full_cmd c);
void print_illegal(full_cmd c);
int strtonum(char *s);
#endif
