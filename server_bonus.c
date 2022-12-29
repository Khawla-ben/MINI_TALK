/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 05:37:19 by kben-ham          #+#    #+#             */
/*   Updated: 2022/12/28 16:16:54 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_t;

void	handl(int pid, struct __siginfo *info, void *ptr)
{
	static char	c;
	static int	i;

	(void)ptr;
	g_t = 0;
	if (pid == SIGUSR1)
		c = c << 1;
	if (pid == SIGUSR2)
	{
		c = c << 1;
		c = c | 1;
	}
	if (i++ >= 7)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	if (g_t++ == 0)
		kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction= &handl;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PID >>>>%d\n", getpid());
	while (1)
		pause();
}
