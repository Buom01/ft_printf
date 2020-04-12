/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 22:40:32 by badam             #+#    #+#             */
/*   Updated: 2020/04/12 17:23:46 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>

# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <unistd.h>
# include "libft/libft.h"

# define CONVERTERS "cspdiuxX%"
# define FLAGS "-0.*"

# define HEXA "0123456789abcdef"
# define HEXACAPS "0123456789ABCDEF"

typedef struct	s_flags
{
	char	conv;
	int		zero_pad;
	int		left_pad;
	int		right_pad;
	int		precision;
	bool	explicit_precision;
}				t_flags;

typedef struct	s_segment
{
	size_t	length;
	char	*content;
}				t_segment;

int				ft_printf(const char *format, ...);

t_segment		print_char(t_flags flags, va_list ap);
t_segment		print_string(t_flags flags, va_list ap);
t_segment		print_pointer(t_flags flags, va_list ap);
t_segment		print_integer(t_flags flags, va_list ap);
t_segment		print_uinteger(t_flags flags, va_list ap);
t_segment		print_uhexint(t_flags flags, va_list ap);
t_segment		print_uhexint_upcase(t_flags flags, va_list ap);
t_segment		print_percent(t_flags flags);

int				freeup(t_list **print_sgmt, va_list *ap);
void			print(void *content);
char			is_converter(char c);
char			is_flag(char c);
void			init_flags(t_flags *flags);

char			parse_flag(t_flags *flags, char **str, char c, va_list *ap);
void			repair_flags(t_flags *flags);
t_segment		convert(t_flags flags, va_list ap);

char			*tobase(size_t n, bool caps, int basesize);
t_segment		pad_free(t_segment sgmt, int n, char blankchar,
					bool alignleft);
t_segment		autopad_free(t_segment sgmt, t_flags flags);
t_segment		autotrunc(t_segment sgmt, t_flags flags);

t_segment		*create_segment(void);
t_segment		*malloc_segment(char *str, size_t len);
t_segment		*dupli_segment(t_segment sgmt);
t_segment		join_segment(char *str, size_t len, char *str2, size_t len2);
void			free_segment(void *content);

#endif
