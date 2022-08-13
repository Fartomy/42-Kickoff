/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:52:57 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/03/06 13:33:03 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <signal.h>

int		ft_printf(const	char *s, ...);
int		type_srch(va_list vag, char str, int a);
int		ft_putchar(char c);
int		ft_putnbr_unsgnd(unsigned int n);
int		ft_putnbr(int n);
int		ft_atoi(const char *s);
void	set_bit(int x);
void	ft_take(int pid, int s);
int		ft_putstr(char *s);
void	set_bit(int x);
void	sgl_catch(int x);

#endif