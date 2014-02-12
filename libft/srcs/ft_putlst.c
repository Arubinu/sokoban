/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by apergens          #+#    #+#             */
/*   Updated: 2014/01/03 02:07:06 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putlst_reverse(t_list *lst, char *(*f)(int), int i, int j);

void			ft_putlst(t_list *lst, char *(*f)(int), int reverse, int debug)
{
	int		start;
	char	*ptr;

	(void)reverse;
	if (lst == NULL || lst->content == NULL)
		return ;
	start = 0;
	if (reverse)
	{
		ft_putlst_reverse(lst, f, 0, debug);
		return ;
	}
	while (!start++ || ((lst = lst->next) != NULL && lst->content != NULL))
	{
		if (start == 1 && debug)
			ft_putendl("\033[32m/* Start Display List */\033[0m");
		ptr = f ? f((int)*((int *)lst->content)) : (char *)lst->content;
		if (debug)
			ft_printf(" [\033[33m%d\033[0m] %s\n", start - 1, ptr);
		else
			ft_putendl(ptr);
	}
	if (start > 1 && debug)
		ft_putendl("\033[32m/* End Display List */\033[0m");
	return ;
}

static void		ft_putlst_reverse(t_list *lst, char *(*f)(int), int i, int j)
{
	char	*ptr;

	if (j && !i)
		ft_putendl("\033[32m/* Start Display List */\033[0m");
	if (lst->next != NULL)
		ft_putlst_reverse(lst->next, f, i + 1, j);
	if (lst->content != NULL)
	{
		ptr = f ? f((int)*((int *)lst->content)) : (char *)lst->content;
		if (j)
			ft_printf(" [\033[33m%d\033[0m] %s\n", i + 1, ptr);
		else
			ft_putendl(ptr);
		if (j && !i)
			ft_putendl("\033[32m/* End Display List */\033[0m");
	}
	return ;
}
