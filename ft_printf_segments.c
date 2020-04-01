/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_segments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 21:12:17 by badam             #+#    #+#             */
/*   Updated: 2020/04/01 22:43:16 by badam            ###   ########.fr       */
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
