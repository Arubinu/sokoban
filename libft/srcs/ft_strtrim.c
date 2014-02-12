/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by apergens          #+#    #+#             */
/*   Updated: 2014/01/03 02:07:54 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c);
static void	ft_strtrim_deleg(const char *s, int *start, int *end);

char		*ft_strtrim(const char *s)
{
	int		start;
	int		end;

	start = 0;
	end = 0;
	if (s == NULL)
		return (NULL);
	ft_strtrim_deleg(s, &start, &end);
	if ((!start && !end) || (end <= start))
		return (ft_memalloc(1));
	return (ft_strsub(s, start, end - start + 1));
}

static void	ft_strtrim_deleg(const char *s, int *start, int *end)
{
	int		i;

	i = -1;
	while (++i < (int)ft_strlen(s) && ft_isspace(*(s + i)))
		;
	*start = i;
	i = ft_strlen(s) + 1;
	while (--i >= 0 && ft_isspace(*(s + i)))
		;
	*end = i;
	return ;
}

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\r')
		return (1);
	else if (c == '\t' || c == '\v' || c == '\f')
		return (1);
	return (0);
}
