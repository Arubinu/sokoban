/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by apergens          #+#    #+#             */
/*   Updated: 2014/01/03 02:07:50 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(const char *s, char c);
static char	*ft_strcut(const char *s, int c);
static void	ft_while(int **n, char ***tab, const char *s, char c);

char		**ft_strsplit(const char *s, char c)
{
	int		*n;
	char	*slen;
	char	**tab;

	slen = 0;
	n = (int *)malloc(sizeof(int) * 2);
	*n = 0;
	*(n + 1) = -1;
	if (s == NULL)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 2));
	*(tab + (ft_count(s, c))) = NULL;
	if (ft_count(s, c) <= 0)
		return (tab);
	ft_while(&n, &tab, s, c);
	*(tab + (ft_count(s, c) + 1)) = NULL;
	return (tab);
}

static void	ft_while(int **n, char ***tab, const char *s, char c)
{
	int		len;

	len = 0;
	while (*(s + **n))
	{
		if (*(s + **n) == c)
		{
			if (*(s + **n + 1) != c)
			{
				*(*n + 1) += 1;
				len = ft_strclen(s + **n + 1, c);
				*(*tab + *(*n + 1)) = ft_strnew(len + 1);
			}
		}
		else if ((!**n && *s != c) || (**n && *(s + **n - 1) == c))
		{
			*(*n + 1) += (*(*n + 1) < 0) ? 1 : 0;
			*(*tab + *(*n + 1)) = ft_strcut(s + **n, c);
			**n += ft_strclen(s + **n, c) - 1;
		}
		**n += 1;
	}
	return ;
}

static char	*ft_strcut(const char *s, int c)
{
	return (ft_strsub(s, 0, ft_strclen(s, c)));
}

static int	ft_count(const char *s, char c)
{
	int		i;
	int		n;
	int		a;

	i = -1;
	n = 0;
	a = 0;
	while (*(s + (++i)))
	{
		if (*(s + i) == c)
		{
			if ((i > 0 && *(s + i - 1) != c) || i <= 0)
				n++;
		}
		else
			a++;
	}
	if (!a)
		return (0);
	else if (!n && ft_strlen(s))
		return (1);
	return (n);
}
