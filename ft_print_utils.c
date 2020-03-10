/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:14:19 by badam             #+#    #+#             */
/*   Updated: 2020/03/10 00:39:06 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#define BUFFLEN 256

char	*tobase(size_t n, bool caps, int basesize)
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

char	*pad_free(char *str, size_t n, char blankchar, bool alignleft)
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
	if (alignleft)
		padded = ft_strjoin(str, blanks);
	else
		padded = ft_strjoin(blanks, str);
	free(blanks);
	free(str);
	return (padded);
}

char	*autopad_free(char *str, t_flags flags)
{
	if (flags.precision)
		str = (pad_free(str, flags.precision, '0', false));
	if (flags.right_pad) // What about priority ?
		str = (pad_free(str, flags.right_pad, ' ', false));
	if (flags.left_pad)
		str = (pad_free(str, flags.left_pad, ' ', true));
	else if (flags.zero_pad)
		str = (pad_free(str, flags.zero_pad, flags.precision ? ' ' : '0', false));
	return (str);
}
