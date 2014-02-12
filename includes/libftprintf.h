/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:42:17 by apergens          #+#    #+#             */
/*   Updated: 2014/01/12 08:47:35 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct	s_v_arg
{
	int				i;
	char			c;
	char			*s;
	int				type;
	struct s_v_arg	*next;
}				t_v_arg;

/*
** Functions of ft_printf
*/

size_t	ft_get_v_arg(va_list ap, char **format, char **out, int fd);
char	*ft_pf_c(va_list ap, char *opts, int *ret);
char	*ft_pf_d(va_list ap, char *opts, int *ret);
char	*ft_pf_f(va_list ap, char *opts, int *ret);
char	*ft_pf_s(va_list ap, char *opts, int *ret);
char	*ft_pf_x(va_list ap, char *opts, int *ret);
int		ft_printf(const char *format, ...);
int		ft_printf_fd(const char *format, int fd, ...);
int		ft_printf_arg(va_list ap, char *format, char **out);
char	*ft_set_v_arg(const char *format, t_v_arg **init);
t_v_arg	*ft_v_arg_new(void);

#endif
