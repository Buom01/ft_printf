/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:14:19 by badam             #+#    #+#             */
/*   Updated: 2020/03/11 05:07:36 by badam            ###   ########.fr       */
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

char		*pad_free(char *str, size_t n, char blankchar, bool alignleft)
{
	size_t	len;
	int		nblanks;
	char	*blanks;
	char	*padded;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (n <= len)
		return (str);
	nblanks = n - len;
	if (!(blanks = malloc((nblanks + 1) * sizeof(char))))
	{
		free(str);
		return (NULL);
	}
	blanks[nblanks] = '\0';
	while (nblanks--)
		blanks[nblanks] = blankchar;
	padded = alignleft ? ft_strjoin(str, blanks) : ft_strjoin(blanks, str);
	free(str);
	free(blanks);
	return (padded);
}

char		*autopad_free(char *str, t_flags flags)
{
	bool	number;

	number = (flags.conv != 's' && flags.conv != 'p' && flags.conv != 'c');
	if (number && flags.precision)
		str = (pad_free(str, flags.precision + (*str == '-'), '0', false));
	if (flags.right_pad)
		str = (pad_free(str, flags.right_pad, ' ', false));
	if (flags.left_pad)
		str = (pad_free(str, flags.left_pad, ' ', true));
	else if (flags.zero_pad)
	{
		if (flags.explicit_precision)
			str = (pad_free(str, flags.zero_pad, ' ', false));
		else
			str = (pad_free(str, flags.zero_pad, '0', false));
	}
	if (number)
		move_minus(str);
	return (str);
}

char		*autotrunc(char *str, t_flags flags)
{
	if (str && flags.explicit_precision && ft_strlen(str) > flags.precision)
		str[flags.precision] = '\0';
	return (str);
}
