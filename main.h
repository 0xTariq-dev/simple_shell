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
 * file: main.h
 * author: 0xTariq-dev, mostafa1jamal1
 * describtion: Header file contains declarations for functions
 *		used in the ALX Simple Shell project.
 */
int exec_cmd(const char *pathname, char **argv);

ssize_t prompt(char **line, size_t *buffsize);

#endif
