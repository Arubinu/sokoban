/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdkn_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/20 01:02:53 by apergens          #+#    #+#             */
/*   Updated: 2014/01/24 13:04:39 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sokoban.h"

/*static SDL_Surface	*ft_sdkn_xxd_image(unsigned char *pngBytes, unsigned int pngLength);*/

SDL_Surface		*ft_sdkn_menu(t_game *game, int level, int *move, int pfree)
{
	static int			y;
	static SDL_Surface	*menu;
	static SDL_Surface	*select;

	if (pfree)
	{
		SDL_FreeSurface(select);
		SDL_FreeSurface(menu);
		menu = NULL;
		return (menu);
	}
	if (!menu && !(y = 0) && (menu = IMG_Load("content/images/menu_mini.png")))
		select = IMG_Load("content/images/select.png");
	if (move && *move != 0)
		y += (*move > 0) ? 1 : -1;
	y = (y < 0) ? 0 : y;
	y = (y > 2) ? 2 : y;
	if (move)
		*move = y;
	ft_sdkn_background(game, &game->image.surf, 0);
	ft_sdkn_putimg(game->image.surf, select, ft_sdkn_rect(483, 169 + (y * 36), WIN_W, WIN_H), -1);
	ft_sdkn_putimg(game->image.surf, menu, ft_sdkn_rect(0, 0, WIN_W, WIN_H), -1);
	ft_sdkn_call_map(game, level, 0, -2);
	return (menu);
}
/*
static SDL_Surface	*ft_sdkn_xxd_image(unsigned char *pngBytes, unsigned int pngLength)
{
	NSData *pngData = [NSData dataWithBytesNoCopy:pngBytes length:(NSUInteger)pngLength freeWhenDone:NO];
	UIImage *image = [UIImage imageWithData: pngData];
	if (!image)
		return (NULL);
	return (Create_SDL_Surface_From_CGImage(image));
}
*/
