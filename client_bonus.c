/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 05:36:02 by kben-ham          #+#    #+#             */
/*   Updated: 2022/12/28 16:29:03 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_r;

void	handl(int pid)
{
	if (pid == SIGUSR1)
		g_r = 1;
}

void	ft_write(int g_r)
{
	write(1, "Recived", 7);
	if (g_r == 1)
		write(1, "Yes", 3);
	else
		write(1, "No", 2);
}

int	main(int ac, char **av)
{
	int					i;
	char				c;
	struct sigaction	sa;
	int					num;

	if ((ac == 3) && (av[1] > 0))
	{
		sa.sa_handler = &handl;
		sigaction(SIGUSR1, &sa, NULL);
		i = -1;
		while (av[2][++i])
		{
			c = av[2][i];
			num = 8;
			while (--num >= 0)
			{
				kill(ft_atoi(av[1]), ((c >> num) & 1) + 30);
				usleep(800);
			}
		}
		ft_write(g_r);
	}
}
