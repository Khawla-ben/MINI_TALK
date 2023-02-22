/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 03:02:03 by kben-ham          #+#    #+#             */
/*   Updated: 2023/02/21 16:05:29 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	again(int *pid, char *c, int *i, struct __siginfo *info)
{
	*c = 0;
	*i = 0;
	*pid = info->si_pid;
}

void	handl(int a, struct __siginfo *info, void *ptr)
{
	static char	c;
	static int	i;
	static int	pid;

	(void)ptr;
	if (pid != info->si_pid)
		again(&pid, &c, &i, info);
	if (a == SIGUSR1)
		c = c << 1;
	if (a == SIGUSR2)
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
	sa.sa_sigaction = &handl;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PID >>>>%d\n", getpid());
	while (1)
		pause();
}
