/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 02:50:48 by badam             #+#    #+#             */
/*   Updated: 2020/03/10 17:06:16 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

// DO NOT INCLUDE WITH THE PROJECT
int	main(void)
{
	long long	n;

	n = 1;
	ft_printf("ftpr: :%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d:\n", n, n, n, n, n, n, n, n);
	printf("orig: :%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d:\n", n, n, n, n, n, n, n, n);
}
