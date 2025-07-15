#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *buffer);
char	*ft_update_buffer(char *chunk, char *buffer);
char	*ft_extract_line(char *buffer);


# endif