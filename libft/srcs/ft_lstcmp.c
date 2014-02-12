/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by apergens          #+#    #+#             */
/*   Updated: 2014/01/03 02:06:35 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcmp(t_list *lst, char *str)
{
	int		len;
	int		start;

	if (lst == NULL || str == NULL)
		return (NULL);
	start = 0;
	len = ft_strlen(str);
	while (!start++ || ((lst = lst->next) != NULL && lst->content != NULL))
	{
		if (!ft_memcmp(lst->content, str, len - 1))
			return (lst);
	}
	return (NULL);
}
