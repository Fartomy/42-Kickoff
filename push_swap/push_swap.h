/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:11:56 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/06/06 20:36:04 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct push_swap
{
	int	*a_stack;
	int	*b_stack;
	int	*bg_sorted;
	int	a_len;
	int	b_len;
	int	big;
	int	mid;
	int	sml;
}				t_pdata;

int		ft_atoi(const char *s);
char	**ft_split(char const *s, char c);
int		arg_cnt_finder(char **av, int *ac);
void	subzero(t_pdata *data, int *nb);
void	storage_to_a_stack(t_pdata *data, char **av, int *ac, int *arg_cnt);
void	alloction(t_pdata *data, int *nb);
void	bg_sort_min(t_pdata *data);
void	is_it_sorted(t_pdata *data);
void	is_it_same(t_pdata *data);
void	ft_error(int i);
void	ft_free(t_pdata *data);
void	sort_p(t_pdata *data);
void	for_three(t_pdata *data);
void	for_five(t_pdata *data);
void	slide_down_a(t_pdata *data);
void	slide_down_b(t_pdata *data);
void	slide_up_a(t_pdata *data);
void	slide_up_b(t_pdata *data);
void	ss(t_pdata *data);
void	rr(t_pdata *data);
void	rrr(t_pdata *data);
void	sa(t_pdata *data);
void	pa(t_pdata *data);
void	ra(t_pdata *data);
void	rra(t_pdata *data);
void	sb(t_pdata *data);
void	pb(t_pdata *data);
void	rb(t_pdata *data);
void	rrb(t_pdata *data);

#endif