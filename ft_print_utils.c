/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:14:19 by badam             #+#    #+#             */
/*   Updated: 2020/04/02 18:03:28 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#define BUFFLEN 256

static void	move_minus(char *str)
{
	size_t	minus;
	size_t	firstzero;

	minus = 0;
	firstzero = 0;
	while (str[minus] && str[minus] != '-')
		minus++;
	while (str[firstzero] && str[firstzero] != '0')
		firstzero++;
	if (str[minus] && str[firstzero] && firstzero < minus)
	{
		str[minus] = '0';
		str[firstzero] = '-';
	}
}

char		*tobase(size_t n, bool caps, int basesize)
{
	char	buff[BUFFLEN];
	int		i;
	char	*str;
	char	*strcpy;
	size_t	len;

	i = BUFFLEN - 1;
	while ((n || i == BUFFLEN - 1) && i >= 0)
	{
		buff[i--] = caps ? HEXACAPS[n % basesize] : HEXA[n % basesize];
		n /= basesize;
	}
	i++;
	len = BUFFLEN - i;
	if (!(str = malloc((len + 1) * sizeof(char))))
		return (NULL);
	strcpy = str;
	while (len--)
		*(strcpy++) = buff[i++];
	*strcpy = '\0';
	return (str);
}

t_segment	pad_free(t_segment sgmt, int n, char blankchar, bool alignleft)
{
	size_t	nblanks;
	size_t	nblankscpy;
	char	*blanks;
	char	*str;

	str = sgmt.content;
	if (!str || (size_t)n <= sgmt.length)
		return (sgmt);
	nblanks = n - sgmt.length;
	if (!(blanks = malloc(nblanks * sizeof(char))))
	{
		free(sgmt.content);
		sgmt.content = NULL;
		return (sgmt);
	}
	nblankscpy = nblanks;
	while (nblankscpy--)
		blanks[nblankscpy] = blankchar;
	sgmt = alignleft ? join_segment(str, sgmt.length, blanks, nblanks) :
			join_segment(blanks, nblanks, str, sgmt.length);
	free(str);
	free(blanks);
	return (sgmt);
}

t_segment	autopad_free(t_segment sgmt, t_flags flags)
{
	bool	number;
	
	if (!(sgmt.content))
		return (sgmt);
	number = (flags.conv != 's' && flags.conv != 'p' && flags.conv != 'c');
	if (number && flags.precision)
		sgmt = (pad_free(sgmt, flags.precision + (*(sgmt.content) == '-'),
				'0', false));
	if (flags.right_pad)
		sgmt = (pad_free(sgmt, flags.right_pad, ' ', false));
	if (flags.left_pad)
		sgmt = (pad_free(sgmt, flags.left_pad, ' ', true));
	else if (flags.zero_pad)
	{
		if (flags.explicit_precision)
			sgmt = (pad_free(sgmt, flags.zero_pad, ' ', false));
		else
			sgmt = (pad_free(sgmt, flags.zero_pad, '0', false));
	}
	if (number)
		move_minus(sgmt.content);
	return (sgmt);
}

t_segment	autotrunc(t_segment sgmt, t_flags flags)
{
	char	*str;

	str = sgmt.content;
	if (str && flags.explicit_precision &&
			ft_strlen(str) > (size_t)flags.precision)
	{
		str[flags.precision] = '\0';
		sgmt.content = ft_strdup(str);
		sgmt.length = flags.precision;
		free(str);
	}
	return (sgmt);
}
