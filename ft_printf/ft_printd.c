/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:25:36 by kben-ham          #+#    #+#             */
/*   Updated: 2022/11/01 17:27:57 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printd(int c, int *count)
{
	long		nb ;

	nb = c;
	if (nb < 0)
	{
		ft_putchar('-');
		*count = *count + 1;
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_printd((nb / 10), count);
		ft_printd((nb % 10), count);
	}
	else
	{
		ft_putchar("0123456789"[nb]);
		*count = *count + 1;
	}
}
