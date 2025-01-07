#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <fcntl.h>

char *get_next_line(int fd);
int ft_strlen(char *str);
void ft_strcpy(char *des, char *src);
char *make_line(char *str, int *index);
char *ft_strjoin(char *prev_line, char *curr_line);
void create_merge(char **final_line, char *buf);

#endif