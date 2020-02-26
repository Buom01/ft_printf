/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 22:40:32 by badam             #+#    #+#             */
/*   Updated: 2020/02/26 22:36:52 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <unistd.h>
# include "libft/libft.h"

# define CONVERTERS "cspdiuxX%"
# define FLAGS "-0.*"

typedef struct	s_flags
{
	char	conv;
	bool	zero_pad;
	bool	left;
	int		precision;
}				t_flags;

int				ft_printf(const char *format, ...);

char			*print_char(t_flags flags, va_list ap);
char			*print_string(t_flags flags, va_list ap);
char			*print_pointer(t_flags flags, va_list ap);
char			*print_decimal(t_flags flags, va_list ap);
char			*print_integer(t_flags flags, va_list ap);
char			*print_uinteger(t_flags flags, va_list ap);
char			*print_uhexint(t_flags flags, va_list ap);
char			*print_uhexint_upcase(t_flags flags, va_list ap);
char			*print_percent(t_flags flags, va_list ap);

int				freeup(t_list **print_sgmt, va_list *ap);
void			print(void *s);
char			is_converter(char c);
char			is_flag(char c);

void			init_flags(t_flags *flags);
char			parse_flag(t_flags *flags, char **str, char c, va_list *ap);
char			*convert(t_flags flags, va_list *ap);

#endif
