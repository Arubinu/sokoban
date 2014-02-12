/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by apergens          #+#    #+#             */
/*   Updated: 2014/01/06 00:47:28 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_lsttoa_normal(t_list *lst, char **str);
static void		ft_lsttoa_reverse(t_list *lst, char **str);

char			*ft_lsttoa(t_list *lst, int reverse)
{
	int		len;
	char	*str;
	t_list	*tmp;

	len = 0;
	if ((tmp = lst) == NULL)
		return (NULL);
	while (lst != NULL)
	{
		len += (lst->content != NULL) ? ft_strlen((char *)lst->content) + 1 : 0;
		lst = lst->next;
	}
	lst = tmp;
	str = ft_strnew(len);
	if (len && reverse)
		ft_lsttoa_reverse(lst, &str);
	else if (len)
		ft_lsttoa_normal(lst, &str);
	return (str);
}

static void		ft_lsttoa_normal(t_list *lst, char **str)
{
	while (lst != NULL)
	{
		if (lst->content != NULL)
			ft_strcat(*str, (char *)lst->content);
		if ((lst = lst->next) != NULL)
			*(*str + ft_strlen(*str)) = '\n';
	}
	return ;
}

static void		ft_lsttoa_reverse(t_list *lst, char **str)
{
	if (lst->next != NULL)
		ft_lsttoa_reverse(lst->next, str);
	if (**str != '\0')
	{
		if (lst->content != NULL)
			ft_strcat(*str, (char *)lst->content);
			*(*str + ft_strlen(*str)) = '\n';
	}
	else if (lst->content != NULL)
		ft_strcpy(*str, (char *)lst->content);
	return ;
}
