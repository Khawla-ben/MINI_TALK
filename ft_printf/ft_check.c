/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:22:07 by kben-ham          #+#    #+#             */
/*   Updated: 2022/11/01 17:25:05 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_printc(va_arg(args, int));
	else if (c == 's')
		count += ft_prints(va_arg(args, char *));
	else if (c == 'p')
	{
		count += write(1, "0x", 2);
		ft_printx(va_arg(args, unsigned long), 'x', &count);
	}
	else if (c == 'd' || c == 'i')
		ft_printd(va_arg(args, int), &count);
	else if (c == 'u')
		ft_printu(va_arg(args, unsigned int), &count);
	else if (c == 'x' || c == 'X')
		ft_printx(va_arg(args, unsigned int), c, &count);
	else if (c == '%')
		count += write(1, "%%", 1);
	return (count);
}
