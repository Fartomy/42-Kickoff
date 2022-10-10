/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 02:55:08 by syildiri          #+#    #+#             */
/*   Updated: 2022/01/13 03:09:33 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*new_str;
	size_t			i;

	new_str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		new_str[i++] = 0;
	}
	s = new_str;
}
