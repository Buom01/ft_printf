/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:12:15 by badam             #+#    #+#             */
/*   Updated: 2020/04/02 16:27:11 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_segment	print_percent()
{
	t_segment	sgmt;

	sgmt.content = ft_strdup("%");
	sgmt.length = 1;
	return (sgmt);
}
