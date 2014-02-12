/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdkn_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 14:15:17 by apergens          #+#    #+#             */
/*   Updated: 2014/01/24 14:17:20 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sokoban.h"

void	ft_sdkn_create(SDL_Surface **surf, int width, int height, int pfree)
{
	if (pfree && *surf != NULL)
	{
		SDL_FreeSurface(*surf);
		*surf = NULL;
	}
	*surf = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
	return ;
}
