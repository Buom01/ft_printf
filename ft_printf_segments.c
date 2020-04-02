/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_segments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 21:12:17 by badam             #+#    #+#             */
/*   Updated: 2020/04/02 17:28:48 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_segment	*create_segment(void)
{
	t_segment	*sgmt;

	if (!(sgmt = malloc(sizeof(t_segment))))
		return (NULL);
	return (sgmt);
}

t_segment	*malloc_segment(char *str, size_t len)
{
	t_segment	*sgmt;

	if ((sgmt = create_segment()))
	{
		sgmt->content = str;
		sgmt->length = len;
	}
	return (sgmt);
}

t_segment	*dupli_segment(t_segment sgmt)
{
	t_segment	*sgmtdup;

	if ((sgmtdup = create_segment()))
	{
		sgmtdup->content = sgmt.content;
		sgmtdup->length = sgmt.length;
	}
	return (sgmtdup);
}

t_segment	join_segment(char *str, size_t len, char *str2, size_t len2)
{
	t_segment	sgmt;
	char		*strdst;

	sgmt.length = len + len2;
	if (!(sgmt.content = malloc(sgmt.length * sizeof(char))))
		return (sgmt);
	strdst = sgmt.content;
	while (len && len--)
		*(strdst++) = *(str++);
	while (len2 && len2--)
		*(strdst++) = *(str2++);
	return (sgmt);
} 

void		free_segment(void *content)
{
	t_segment *sgmt;

	sgmt = (t_segment*)content;
	if (sgmt)
	{
		if (sgmt->content)
			free(sgmt->content);
		free(sgmt);
	}
}
