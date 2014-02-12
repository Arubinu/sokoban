/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 01:49:59 by apergens          #+#    #+#             */
/*   Updated: 2014/01/03 02:05:58 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_flag_return(char *str)
{
	int		i;

	i = -1;
	while (*(str + (++i)))
	{
		if (ft_isalpha(*(str + i)))
			break ;
	}
	return (i);
}

int		ft_printf_arg(va_list ap, char *format, char **out)
{
	int		ret;
	char	*opts;

	*out = NULL;
	opts = ft_strsub(format, 1, ft_flag_return(format));
	*out = ft_strcmp(opts, "c") ? *out : ft_pf_c(ap, opts, &ret);
	*out = ft_strcmp(opts, "%") ? *out : ft_pf_c(ap, opts, &ret);
	*out = ft_strcmp(opts, "d") ? *out : ft_pf_d(ap, opts, &ret);
	*out = ft_strcmp(opts, "f") ? *out : ft_pf_f(ap, opts, &ret);
	*out = ft_strcmp(opts, "s") ? *out : ft_pf_s(ap, opts, &ret);
	*out = ft_strcmp(opts, "x") ? *out : ft_pf_x(ap, opts, &ret);
	*out = ft_strcmp(opts, "X") ? *out : ft_pf_x(ap, opts, &ret);
	*out = (*out == NULL) ? "" : *out;
	return (ret);
}
