/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdkn_putrect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/20 01:01:47 by apergens          #+#    #+#             */
/*   Updated: 2014/01/23 04:29:04 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sokoban.h"

void	ft_sdkn_putrect(SDL_Surface *win, t_surf surface)
{
	SDL_FillRect(surface.surf, NULL, surface.color);
	ft_sdkn_putimg(win, surface.surf, surface.rect, -1);
	return ;
}
