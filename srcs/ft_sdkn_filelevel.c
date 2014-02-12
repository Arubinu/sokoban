/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdkn_filelevel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/20 01:00:20 by apergens          #+#    #+#             */
/*   Updated: 2014/01/24 14:20:24 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sokoban.h"

static int	ft_sdkn_free_map(char ****map, char **flvl);

char		***ft_sdkn_filelevel(int level, int reset, char *****out)
{
	int				fd;
	char			*flvl;
	static char		***map;
	static int		save_level;

	if (out && (*out = &map))
		return (NULL);
	if ((!map || save_level != level || reset) && (flvl = ft_itoa(level)))
	{
		save_level = level;
		if (ft_sdkn_free_map(&map, &flvl))
			return (map);
		level = ft_get_nbr_lines(flvl);
		ft_sdkn_mapsize(0, level - 1, -1);
		map = (char ***)malloc(sizeof(char **) * (level + 1));
		if (map && !(*(map + level) = NULL) && (fd = open(flvl, O_RDONLY)))
		{
			level = -1;
			free(flvl);
			while (ft_get_next_line(fd, &flvl))
				*(map + (++level)) = ft_strfsplit(&flvl, ' ', 1);
			close(fd);
		}
		ft_sdkn_mapsize(ft_tablen(&map, 0), ft_sdkn_mapsize(0, 0, 1), -1);
	}
	else
		return (NULL);
	return (map);
}

static int	ft_sdkn_free_map(char ****map, char **flvl)
{
	int		i;

	i = -1;
	*flvl = ft_strfjoin2(DIR_MAPS, flvl, 1);
	if (access(*flvl, R_OK) == -1)
		return (1);
	if (*map != NULL)
	{
		free(*map);
		*map = NULL;
	}
	return (0);
}
