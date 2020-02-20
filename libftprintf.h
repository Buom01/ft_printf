/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 22:40:32 by badam             #+#    #+#             */
/*   Updated: 2020/02/20 06:22:52 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

# define CONVERTERS "cspdiuxX%"
# define FLAGS "-0.*"

enum {
	FALSE = 0,
	TRUE = 1
}				e_bool;

typedef struct	s_flags
{
	char	conv;
	e_bool	zero_pad;
	e_bool	left;
	size_t	precision;
}				t_flags;

int				ft_printf(const char *format, ...);
int				ft_print_int(int n);
int				ft_print_uint(unsigned int n);

int				freeup(t_list **print_sgmt, va_list *ap);
void			print(void *s);
char			is_converter(char c);
char			is_flag(char c);

void			init_flags(t_flags *flags);
char			parse_flag(t_flags flags, char c);
char			*convert(t_flags flags, va_list *ap, size_t *ai);

#endif
