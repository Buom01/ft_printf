/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:14:19 by badam             #+#    #+#             */
/*   Updated: 2020/03/04 20:04:23 by badam            ###   ########.fr       */
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

char	*pad_zero_free(char *str, size_t n)
{
	size_t	len;
	int		nzeros;
	char	*zeros;
	char	*padded;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (n <= len)
		return (str);
	nzeros = n - len;
	if (!(zeros = malloc((nzeros + 1) * sizeof(char))))
	{
		free(str);
		return (NULL);
	}
	zeros[nzeros] = '\0';
	while (nzeros--)
		zeros[nzeros] = '0';
	padded = ft_strjoin(zeros, str);
	free(zeros);
	free(str);
	return (padded);
}
