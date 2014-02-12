/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdkn_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/20 01:34:21 by apergens          #+#    #+#             */
/*   Updated: 2014/01/20 13:03:49 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sokoban.h"

static int	ft_sdkn_move1(char ****file, int nbr, int x, int y);
static int	ft_sdkn_move2(char ****file, int nbr, int x, int y, int h);
static int	ft_sdkn_move3(char ****file, int nbr, int x, int y);
static int	ft_sdkn_move4(char ****file, int nbr, int x, int y, int w);

char	***ft_sdkn_move(int move)
{
	int		x;
	int		y;
	int		w;
	int		h;
	int		nbr;
	char	****file;

	ft_sdkn_filelevel(0, 0, &file);
	if ((y = -1) == -1 && (!*file || !**file || move <= 0))
		return (NULL);
	w = ft_sdkn_mapsize(0, 0, 0);
	h = ft_sdkn_mapsize(0, 0, 1);
	while (++y < h && (x = -1) && *(*file + y) && *(*(*file + y) + (x + 1)))
	{
		while (move && ++x < w && *(*(*file + y) + x))
		{
			if ((nbr = ft_atoi(*(*(*file + y) + x))) != 2 && nbr != 5)
				continue ;
			if (move == 1 && y > 0 && !(move = 0))
				ft_sdkn_move1(file, nbr, x, y);
			if (move == 2 && h - y > 0 && !(move = 0))
				ft_sdkn_move2(file, nbr, x, y, h);
			if (move == 3 && x > 0 && !(move = 0))
				ft_sdkn_move3(file, nbr, x, y);
			if (move == 4 && w - x > 0 && !(move = 0))
				 ft_sdkn_move4(file, nbr, x, y, w);
			break ;
		}
	}
	return (*file);
}

static int	ft_sdkn_move1(char ****file, int nbr, int x, int y)
{
	int		block1;
	int		block2;

	block1 = ft_atoi(*(*(*file + (y - 1)) + x));
	if ((block1 == 3 || block1 == 6) && y > 1)
	{
		block2 = ft_atoi(*(*(*file + (y - 2)) + x));
		if ((block2 == 0 || block2 == 4))
		{
			**(*(*file + (y - 2)) + x) = (block2 == 0) ? '3' : '6';
			**(*(*file + (y - 1)) + x) = (block1 == 6) ? '4': '0';
			block1 = (block1 == 6) ? 4 : 0;
		}
	}
	if (block1 == 0 || block1 == 4)
	{
		**(*(*file + (y - 1)) + x) = (block1 == 0) ? '2' : '5';
		**(*(*file + y) + x) = (nbr == 5) ? '4' : '0';
		ft_sdkn_putinfos(NULL, 1, 0, -1);
	}
	return (1);
}

static int	ft_sdkn_move2(char ****file, int nbr, int x, int y, int h)
{
	int		block1;
	int		block2;

	block1 = ft_atoi(*(*(*file + (y + 1)) + x));
	if ((block1 == 3 || block1 == 6) && h - y > 1)
	{
		block2 = ft_atoi(*(*(*file + (y + 2)) + x));
		if ((block2 == 0 || block2 == 4))
		{
			**(*(*file + (y + 2)) + x) = (block2 == 0) ? '3' : '6';
			**(*(*file + (y + 1)) + x) = (block1 == 6) ? '4': '0';
			block1 = (block1 == 6) ? 4 : 0;
		}
	}
	if (block1 == 0 || block1 == 4)
	{
		**(*(*file + (y + 1)) + x) = (block1 == 0) ? '2' : '5';
		**(*(*file + y) + x) = (nbr == 5) ? '4' : '0';
		ft_sdkn_putinfos(NULL, 1, 0, -1);
	}
	return (1);
}

static int	ft_sdkn_move3(char ****file, int nbr, int x, int y)
{
	int		block1;
	int		block2;

	block1 = ft_atoi(*(*(*file + y) + (x - 1)));
	if ((block1 == 3 || block1 == 6) && x > 1)
	{
		block2 = ft_atoi(*(*(*file + y) + (x - 2)));
		if ((block2 == 0 || block2 == 4))
		{
			**(*(*file + y) + (x - 2)) = (block2 == 0) ? '3' : '6';
			**(*(*file + y) + (x - 1)) = (block1 == 6) ? '4': '0';
			block1 = (block1 == 6) ? 4 : 0;
		}
	}
	if (block1 == 0 || block1 == 4)
	{
		**(*(*file + y) + (x - 1)) = (block1 == 0) ? '2' : '5';
		**(*(*file + y) + x) = (nbr == 5) ? '4' : '0';
		ft_sdkn_putinfos(NULL, 1, 0, -1);
	}
	return (1);
}

static int	ft_sdkn_move4(char ****file, int nbr, int x, int y, int w)
{
	int		block1;
	int		block2;

	block1 = ft_atoi(*(*(*file + y) + (x + 1)));
	if ((block1 == 3 || block1 == 6) && w - x > 1)
	{
		block2 = ft_atoi(*(*(*file + y) + (x + 2)));
		if ((block2 == 0 || block2 == 4))
		{
			**(*(*file + y) + (x + 2)) = (block2 == 0) ? '3' : '6';
			**(*(*file + y) + (x + 1)) = (block1 == 6) ? '4': '0';
			block1 = (block1 == 6) ? 4 : 0;
		}
	}
	if (block1 == 0 || block1 == 4)
	{
		**(*(*file + y) + (x + 1)) = (block1 == 0) ? '2' : '5';
		**(*(*file + y) + x) = (nbr == 5) ? '4' : '0';
		ft_sdkn_putinfos(NULL, 1, 0, -1);
	}
	return (1);
}
