/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 22:40:32 by badam             #+#    #+#             */
/*   Updated: 2019/11/17 06:31:01 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

int	ft_printf(const char *format, ...);
int	putchar(char c);
int	print_int(int n);
int	print_uint(unsigned int n);

#endif
