/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:28:02 by kben-ham          #+#    #+#             */
/*   Updated: 2022/12/28 14:51:23 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	ptr;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(ptr, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			i++;
			count += ft_check(ptr, s[i]);
		}
		else if (s[i] != '\0')
			count += ft_putchar(s[i]);
		i++;
	}
	va_end(ptr);
	return (count);
}
