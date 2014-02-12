/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/17 02:05:01 by apergens          #+#    #+#             */
/*   Updated: 2014/01/03 02:07:19 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *s1, const char *s2)
{
	int	i;

	i = -1;
	while (s2[++i] != '\0')
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}
