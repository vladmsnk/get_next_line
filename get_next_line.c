#include "get_next_line.h"
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	sizes		sizes;
	static char	*remdr;
	char		*gotten_line;

	sizes.rd = BUFFER_SIZE;

	clean_buff(buff);
	if (remdr)
	{
		if (has_slesh_n(remdr))
		{
			sizes.ind_of_n = find_index_n(remdr);
			gotten_line = parse_line(remdr, sizes.ind_of_n);
			remdr = reload_rem(remdr,sizes.ind_of_n);
			return (gotten_line);
		}
	}
	while (!has_slesh_n(buff) && sizes.rd == BUFFER_SIZE)
	{
		sizes.rd = read(fd, buff, BUFFER_SIZE);
		buff[sizes.rd] = '\0';
		remdr = str_join(remdr, buff);
	}
	if (has_slesh_n(buff))
	{
		sizes.ind_of_n = find_index_n(remdr);
		gotten_line = parse_line(remdr, sizes.ind_of_n);
		remdr = reload_rem(remdr,sizes.ind_of_n);
	}
	else 
		return remdr;
	return (gotten_line);
}

int main() 
{
  int fd = open("file", O_RDONLY);
  char *line  = get_next_line(fd);
//   char *line1  = get_next_line(fd);
  printf("%s", line);

}