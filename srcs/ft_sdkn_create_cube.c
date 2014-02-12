/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdkn_create_cube.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/20 00:54:57 by apergens          #+#    #+#             */
/*   Updated: 2014/01/24 14:25:33 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sokoban.h"

int		ft_sdkn_create_cube(SDL_Surface ***cube, int nbr)
{
	int				i;
	Uint32			color;
	SDL_Surface		*donut;

	i = -1;
	*cube = (SDL_Surface **)malloc(sizeof(SDL_Surface *) * (nbr + 1));
	*(*cube + nbr) = NULL;
	while (cube && *cube && ++i < nbr)
		*(*cube + i) = SDL_CreateRGBSurface(0, CUBE_W, CUBE_H, 32, 0, 0, 0, 0);
	ft_sdkn_create(&donut, CUBE_W / 2, CUBE_H / 2, 0);
	SDL_FillRect(donut, NULL, SDL_MapRGB(donut->format, 29, 29, 29));
	color = SDL_MapRGB((*(*cube + 0))->format, 29, 29, 29);
	SDL_FillRect(*(*cube + 0), NULL, color);
	color = SDL_MapRGB((*(*cube + 1))->format, 0, 1, 0);
	SDL_FillRect(*(*cube + 1), NULL, color);
	color = SDL_MapRGB((*(*cube + 2))->format, 0, 149, 252);
	SDL_FillRect(*(*cube + 2), NULL, color);
	ft_sdkn_putimg(*(*cube + 2), donut, ft_sdkn_rect(CUBE_W / 4, CUBE_H / 4, CUBE_W / 2, CUBE_H / 2), -1);
	color = SDL_MapRGB((*(*cube + 3))->format, 196, 109, 0);
	SDL_FillRect(*(*cube + 3), NULL, color);
	ft_sdkn_putimg(*(*cube + 3), donut, ft_sdkn_rect(CUBE_W / 4, CUBE_H / 4, CUBE_W / 2, CUBE_H / 2), -1);
	color = SDL_MapRGB((*(*cube + 4))->format, 255, 216, 0);
	SDL_FillRect(*(*cube + 4), NULL, color);
	ft_sdkn_create(&donut, CUBE_W / 2, CUBE_H / 2, 1);
	SDL_FillRect(donut, NULL, SDL_MapRGB(donut->format, 255, 216, 0));
	color = SDL_MapRGB((*(*cube + 5))->format, 0, 149, 252);
	SDL_FillRect(*(*cube + 5), NULL, color);
	ft_sdkn_putimg(*(*cube + 5), donut, ft_sdkn_rect(CUBE_W / 4, CUBE_H / 4, CUBE_W / 2, CUBE_H / 2), -1);
	color = SDL_MapRGB((*(*cube + 6))->format, 196, 109, 0);
	SDL_FillRect(*(*cube + 6), NULL, color);
	ft_sdkn_putimg(*(*cube + 6), donut, ft_sdkn_rect(CUBE_W / 4, CUBE_H / 4, CUBE_W / 2, CUBE_H / 2), -1);
	SDL_FreeSurface(donut);
	return (i);
}
