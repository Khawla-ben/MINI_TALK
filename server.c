/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 03:02:03 by kben-ham          #+#    #+#             */
/*   Updated: 2022/12/28 16:04:07 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handl(int pid)
{
	static char	c;
	static int	i;

	if (pid == SIGUSR1)
		c = c << 1;
	if (pid == SIGUSR2)
	{
		c = c << 1;
		c = c | 1;
	}
	if (i++ == 7)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_handler = &handl;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PID >>>>%d\n", getpid());
	while (1)
		pause();
}
