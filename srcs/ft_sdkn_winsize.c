/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdkn_winsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 03:45:51 by apergens          #+#    #+#             */
/*   Updated: 2014/01/23 04:18:08 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sokoban.h"

SDL_Rect	ft_sdkn_winsize(t_game *game, int width, int height)
{
	int					x;
	int					y;
	SDL_Rect			winsize;

	(void)width;
	(void)height;
	SDL_GetWindowSize(game->win, &x, &y);
	winsize = ft_sdkn_rect(0, 0, x, y);
	winsize.x += width ? (winsize.w - width) / 2 : 0;
	winsize.y += height ? (winsize.h - height) / 2 : 0;
	winsize.w -= width ? winsize.x : 0;
	winsize.h -= height ? winsize.y : 0;
	return (winsize);
}
