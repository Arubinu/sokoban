/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdkn_free_cube.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/20 00:57:33 by apergens          #+#    #+#             */
/*   Updated: 2014/01/20 08:20:48 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sokoban.h"

void	ft_sdkn_free_cube(SDL_Surface ***cube, int nbr)
{
	int		i;

	i = -1;
	while (cube && *cube && *(*cube + (++i)) && i < nbr)
		SDL_FreeSurface(*(*cube + i));
	return ;
}
