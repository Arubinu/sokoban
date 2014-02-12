/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdkn_mapsave.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/20 04:54:25 by apergens          #+#    #+#             */
/*   Updated: 2014/01/20 07:21:20 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sokoban.h"

char	****ft_sdkn_mapsave(void)
{
	static char		****save;

	if (save == NULL)
	{
		save = (char ****)malloc(sizeof(char ***));
		*save = NULL;
	}
	return (save);
}
