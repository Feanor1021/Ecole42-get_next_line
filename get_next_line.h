#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 12323
#endif


char *get_next_line(int fd);
char *get_till_n(int fd, char *line);

char *get_line(char *line);
char *skip_next_n(char *line);

size_t	ft_strlen(char *s);
char	*ft_strchr( const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char  *s1, char  *s2);

#endif