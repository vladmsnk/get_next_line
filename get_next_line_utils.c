#include "get_next_line.h"

#include <unistd.h>

int	has_slesh_n(char *str)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	find_index_n(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (s)
	{
		while (s[len] != '\0')
		{
			len++;
		}
	}
	return (len);
}


void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*tmp_src;
	char	*tmp_dest;

	if (dst == NULL && src == NULL && n > 0)
	{
		return (NULL);
	}
	tmp_src = (char *)src;
	tmp_dest = (char *)dst;
	while (n--)
	{
		*tmp_dest = *tmp_src;
		tmp_dest++;
		tmp_src++;
	}
	return (dst);
}

char	*str_join(char *lhs, char *rhs)
{
	char	*lhs_cpy;
	size_t	lhs_len;
	size_t	rhs_len;

	lhs_len = ft_strlen(lhs);
	rhs_len = ft_strlen(rhs);
	if (lhs_len > 0)
	{
		lhs_cpy = (char *)malloc(sizeof(char) * lhs_len);
		ft_memcpy(lhs_cpy, lhs, lhs_len);
		free(lhs);
	}
	lhs = (char *)malloc(sizeof(char) * (lhs_len + rhs_len + 1));
	if (lhs_len > 0)
		ft_memcpy(lhs, lhs_cpy, lhs_len);
	ft_memcpy(lhs + lhs_len, rhs, rhs_len);
	lhs[lhs_len + rhs_len] = '\0';
	if (lhs_len > 0)
		free(lhs_cpy);
	return (lhs);
}


char	*parse_line(char *gotten_line, size_t index)
{
	char	*line;
	size_t	i;

	line = (char *)malloc(sizeof(char) * (index + 1));
	i = 0;
	while (i < index + 1)
	{
		line[i] = gotten_line[i];
		i++;
	}
	return (line);
}

char	*reload_rem(char *old_rem, size_t index_n)
{
	char	*rem_cpy;
	size_t	rem_len;

	rem_len = ft_strlen(old_rem);
	if (rem_len == 0)
	{
		free(old_rem);
		return (NULL);
	}
	rem_cpy = (char *)malloc(sizeof(char) * (rem_len - (index_n + 1)));
	ft_memcpy(rem_cpy, old_rem + index_n + 1, rem_len - index_n + 1);
	free(old_rem);
	old_rem = (char *)malloc(sizeof(char) * rem_len - index_n + 1);
	ft_memcpy(old_rem, rem_cpy, rem_len - index_n + 1);
	return (old_rem);
}

