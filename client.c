/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 03:02:18 by kben-ham          #+#    #+#             */
/*   Updated: 2022/12/28 16:25:56 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	int		i;
	int		num;
	char	c;

	if ((ac == 3) && (av[1] > 0))
	{
		i = 0;
		num = 7;
		while (av[2][i])
		{
			c = av[2][i];
			if (c < 0 || c > 127)
				return (0);
			while (num >= 0)
			{
				kill(ft_atoi(av[1]), ((c >> num) & 1) + 30);
				usleep(800);
				num--;
			}
			num = 7;
			i++;
		}
	}
}
