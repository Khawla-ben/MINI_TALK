/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:31:11 by kben-ham          #+#    #+#             */
/*   Updated: 2022/11/01 17:31:57 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printx(unsigned long c, char x, int *count)
{
	char	*str;

	if (x == 'x')
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	if (c >= 16)
	{
		ft_printx((c / 16), x, count);
		ft_printx((c % 16), x, count);
	}
	else
	{
		ft_putchar(str[c]);
		*count = *count + 1;
	}
}
