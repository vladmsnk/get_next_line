#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct sizes
{
	size_t	rd;
	size_t	ind_of_n;
} sizes;


char	*get_next_line(int fd);
int		has_slesh_n(char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*str_join(char *lhs, char *rhs);
char	*reload_rem(char *old_rem, size_t index_n);
size_t	ft_strlen(const char *s);
char	*parse_line(char *rem, size_t ind_of_n);
size_t	find_index_n(char *str);
char	*parse_rem(char *rem);
void	clean_buff(char *buff);
#endif