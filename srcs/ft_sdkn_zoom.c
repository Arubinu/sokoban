/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdkn_zoom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/20 21:55:17 by apergens          #+#    #+#             */
/*   Updated: 2014/01/21 21:18:37 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sokoban.h"
#include <stdio.h>

double	ft_sdkn_zoom(int w, int h, int wmax, int hmax)
{
	double	ratio;
	double	ratiow;
	double	ratioh;

	ratiow = (w > wmax) ? (double)wmax / (double)w : 1;
	ratioh = (h > hmax) ? (double)hmax / (double)h : 1;
	ratio = (ratiow > ratioh) ? ratioh : ratiow;
	ratio = (ratio > 1) ? 1 : ratio;
	ratio = (double)((int)(ratio * 100)) / 100;
	return (ratio);
}
