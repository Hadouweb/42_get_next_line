/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 03:54:11 by nle-bret          #+#    #+#             */
/*   Updated: 2015/12/09 06:07:48 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE 10

typedef struct		s_save
{
	int				fd_num;
	char			*rest;
	struct s_save	*next;
}					t_save;

int					ft_save(t_save **lst, char *buf, char **line);
int					get_next_line(int const fd, char **line);
t_save				*ft_create_fd(int fd_pnum);
char				*ft_strcpy_limit(char *str, char n);
t_save				*ft_get_list(t_save **s, int fd);

#endif
