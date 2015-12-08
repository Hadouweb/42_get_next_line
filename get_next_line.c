#include "get_next_line.h"
#include "./libft/libft.h"

char	*ft_strcpy_limit(char *str)
{
	int		i;
	char	*dst;	

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	dst = (char *)malloc(i + 1);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

t_save	*ft_create_fd(int fd_pnum)
{
	t_save		*fd;

	fd = (t_save *)malloc(sizeof(t_save));
	fd->rest = ft_memalloc(1);
	fd->fd_num = fd_pnum;
	fd->next = NULL;
	return (fd);
}

int		ft_save(t_save **s, char *buf, char **line)
{
	char	*eol;
	
	//printf("\n____LIST %p\n", *s);
	//printf("REST [%s]\n", (*s)->rest);
	if ((eol = ft_strchr(buf, '\n')) != NULL)
	{
		//printf("EOL\n");
		ft_strdel(line);
		if (*eol == '\n')
			eol++;
		if ((*s)->rest && ft_strchr((*s)->rest, '\n') == NULL)
			*line = ft_strjoin((*s)->rest, ft_strcpy_limit(buf));
		else
			*line = ft_strcpy_limit(buf);
		//printf("_REST_ [%s]\n", (*s)->rest);
		//ft_strdel(&(*s)->rest);
		(*s)->rest = ft_strdup(eol);
		//printf("REST [%s]\n", (*s)->rest);
		return (1);
	}
	else
	{
		//printf("PAS DE EOL\n");
		if ((*s)->rest)
			(*s)->rest = ft_strjoin((*s)->rest, buf);
		else
			(*s)->rest = ft_strdup(buf);
	}	
	return (0);
}

t_save	*ft_get_list(t_save **s, int fd)
{
	t_save			*lst;

	if (!*s)
		*s = ft_create_fd(fd);
	lst = *s;
	while (lst->next && lst->fd_num != fd)
		lst = lst->next;
	if (lst->next == NULL && lst->fd_num != fd)
		lst->next = ft_create_fd(fd);
	lst = *s;
	while (lst && lst->fd_num != fd)
		lst = lst->next;
	return (lst);
}

int     get_next_line(int const fd, char **line)
{
	char            buf[BUFF_SIZE + 1];
	int             ret;
	static t_save	*s;
	t_save			*lst;

	if (!line)
		return (-1);
	*line = NULL;
	lst = ft_get_list(&s, fd);
	if (lst && lst->rest && ft_strchr(lst->rest, '\n') && 
		ft_save(&lst, lst->rest, line))
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (ft_save(&lst, buf, line))
			return (1);
	}
	if (ret == 0 && lst->rest && (*line = ft_strdup(lst->rest)) != NULL)
		ft_strdel(&lst->rest);
	if (ret == -1)
		return (-1);
	return (0);
}
