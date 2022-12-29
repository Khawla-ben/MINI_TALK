/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:31:01 by kben-ham          #+#    #+#             */
/*   Updated: 2022/11/01 17:34:20 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printu(unsigned int c, int *count)
{
	if (c > 9)
		ft_printu((c / 10), count);
	ft_putchar("0123456789"[c % 10]);
	*count = *count + 1;
}
