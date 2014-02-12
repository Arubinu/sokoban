/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdkn_base64.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 01:04:18 by apergens          #+#    #+#             */
/*   Updated: 2014/01/21 02:00:55 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sokoban.h"

/*
** Translation Table as described in RFC1113
*/
static const char cb64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

/*
** Translation Table to decode (created by author)
*/
static const char cd64[] = "|$$$}rstuvwxyz{$$$$$$$>?@ABCDEFGHIJKLMNOPQRSTUVW$$$$$$XYZ[\\]^_`abcdefghijklmnopq";

static void		ft_sdkn_base64_realloc(int c, char **str)
{
	char	*join;

	if (!str || !*str)
		return ;
	join = ft_ctoa(c);
	*str = ft_strfjoin(str, &join, 2);
	return ;
}

/*
** encodeblock
**
** encode 3 8-bit binary bytes as 4 '6-bit' characters
*/
static void		encodeblock(unsigned char *in, unsigned char *out, int len)
{
	out[0] = (unsigned char) cb64[(int)(in[0] >> 2)];
	out[1] = (unsigned char) cb64[(int)(((in[0] & 0x03) << 4) | ((in[1] & 0xf0) >> 4))];
	out[2] = (unsigned char) (len > 1 ? cb64[(int)(((in[1] & 0x0f) << 2) | ((in[2] & 0xc0) >> 6))] : '=');
	out[3] = (unsigned char) (len > 2 ? cb64[(int)(in[2] & 0x3f)] : '=');
}

/*
** encode
**
** base64 encode a stream adding padding and line breaks as per spec.
*/
static char		*encode(char **str, int linesize)
{
	int				i;
	int				j;
	int				len;
	int				blocksout;
	char			*ret;
	unsigned char	in[3];
	unsigned char	out[4];

	i = 0;
	j = 0;
	len = 0;
	blocksout = 0;
	ret = ft_strnew(0);
	*in = (unsigned char)0;
	*out = (unsigned char)0;
	while (*str[j] && !(len = 0) && (i = -1) == -1)
	{
		while (++i < 3)
		{
			in[i] = (unsigned char)*str[j++];
			if (*str[j])
				len++;
			else
				in[i] = (unsigned char)0;
		}
		if (len > 0 && (i = -1) == -1)
		{
			encodeblock(in, out, len);
			while (++i < 4)
				ft_sdkn_base64_realloc((int)(out[i]), &ret);
			blocksout++;
		}
		if (blocksout >= (linesize / 4) || !*str[j])
			blocksout = 0;
	}
	return (ret);
}

/*
** decodeblock
**
** decode 4 '6-bit' characters into 3 8-bit binary bytes
*/
static void		decodeblock(unsigned char *in, unsigned char *out)
{
	out[ 0 ] = (unsigned char) (in[0] << 2 | in[1] >> 4);
	out[ 1 ] = (unsigned char) (in[1] << 4 | in[2] >> 2);
	out[ 2 ] = (unsigned char) (((in[2] << 6) & 0xc0) | in[3]);
}

/*
** decode
**
** decode a base64 encoded stream discarding padding, line breaks and noise
*/
static char		*decode(char **str)
{
	int				i;
	int				j;
	int				v;
	int				len;
	char			*ret;
	unsigned char	in[4];
	unsigned char	out[3];

	j = 0;
	ret = ft_strnew(0);
	*in = (unsigned char)0;
	*out = (unsigned char)0;
	while (*str[j] && !(len = 0) && (i = -1) == -1)
	{
		while (++i < 4 && *str[j] && (v = 0))
		{
			while (*str[j] && v == 0)
			{
				if ((v = *str[j++]))
				{
					v = ((v < 43 || v > 122) ? 0 : (int)cd64[v - 43]);
					if (v != 0)
						v = ((v == (int)'$') ? 0 : v - 61);
				}
			}
			if (*str[j] && ++len)
			{
				if (v != 0)
					in[i] = (unsigned char)(v - 1);
			}
			else
				in[i] = (unsigned char)0;
		}
		if (len > 0 && (i = -1) == -1)
		{
			decodeblock(in, out);
			while (++i < len - 1)
				ft_sdkn_base64_realloc((int)(out[i]), &ret);
		}
	}
	return (ret);
}

#define B64_DEF_LINE_SIZE   72
#define B64_MIN_LINE_SIZE	4

char			*ft_sdkn_base64(char *str, int opt)
{
	int linesize = B64_DEF_LINE_SIZE;

	if (!str || !*str)
		return (NULL);
	if(opt)
		return (encode(&str, linesize));
	return (decode(&str));
}
