/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 22:40:32 by badam             #+#    #+#             */
/*   Updated: 2020/02/14 05:40:28 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

# define MAX_FLAG 16

typedef struct	s_conv
{
	char	type;
	char	flag[MAX_FLAG];
}				t_conv;

int				ft_printf(const char *format, ...);
int				ft_print_int(int n);
int				ft_print_uint(unsigned int n);

int				freeup(t_list **print_sgmt, va_list *ap);
void			print(void *s);

#endif
