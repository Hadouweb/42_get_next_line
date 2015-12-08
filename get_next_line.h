#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./libft/libft.h"
# define BUFF_SIZE 1

typedef struct		s_save
{
	int				fd_num;
	char			*rest;
	struct s_save	*next;
}					t_save;

int			ft_save(t_save **lst, char *buf, char **line);
int			get_next_line(int const fd, char **line);
t_save		*ft_create_fd(int fd_pnum);

#endif
