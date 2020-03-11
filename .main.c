/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 02:50:48 by badam             #+#    #+#             */
/*   Updated: 2020/03/11 03:33:46 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

// DO NOT INCLUDE WITH THE PROJECT
int	main(void)
{
	ft_printf("ftpr: :%.s:\n", "hello");
	printf("orig: :%.s:\n", "hello");
}
