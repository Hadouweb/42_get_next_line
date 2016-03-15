/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttotab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 00:32:17 by nle-bret          #+#    #+#             */
/*   Updated: 2015/11/25 03:18:59 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_lsttotab(t_list *l)
{
	void	**tab;
	int		size;
	size_t	i;
	t_list	*list;

	list = l;
	size = ft_lstsize(l);
	i = 0;
	if ((tab = (void **)ft_memalloc(size + 1)) == NULL)
		return (NULL);
	while (list)
	{
		if ((tab[i] = (void *)ft_memalloc(list->content_size)) == NULL)
			return (NULL);
		ft_memcpy(tab[i], list->content, list->content_size);
		list = list->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
