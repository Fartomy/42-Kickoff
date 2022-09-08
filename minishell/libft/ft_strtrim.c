/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:40:50 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/09/08 15:00:35 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	set_idx_start;
	size_t	set_idx_fin;

	if (!s1 || !set)
		return (0);
	set_idx_start = 0;
	set_idx_fin = ft_strlen((char *)s1);
	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, s1[set_idx_start]) && s1[set_idx_start] != '\0')
		set_idx_start++;
	while (ft_strchr(set, s1[set_idx_fin]) && set_idx_fin != '\0')
		set_idx_fin--;
	if ((int)(set_idx_fin - set_idx_start + 1) <= 0)
		return (ft_calloc(1, 1));
	return (ft_substr(s1, set_idx_start, (set_idx_fin - set_idx_start + 1)));
}
