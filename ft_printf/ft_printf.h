/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-ham <kben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:28:22 by kben-ham          #+#    #+#             */
/*   Updated: 2022/11/02 15:33:36 by kben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_printf(const char *s, ...);
int		ft_check(va_list args, char c);
int		ft_printc(int c);
int		ft_prints(char *c);
void	ft_printd(int c, int *count);
void	ft_printu(unsigned int c, int *count);
void	ft_printx(unsigned long c, char x, int *count);

#endif