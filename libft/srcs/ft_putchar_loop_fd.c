/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_loop_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/21 08:56:14 by apergens          #+#    #+#             */
/*   Updated: 2014/01/11 03:01:51 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writes a character to the console several times
*/

void	ft_putchar_loop_fd(int c, int fd, int nbr)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (nbr + 1));
	*(ptr + nbr) = '\0';
	ft_memset(ptr, c, nbr);
	ft_putstr_fd(ptr, fd);
	return ;
}
