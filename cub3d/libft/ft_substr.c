/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 02:57:33 by syildiri          #+#    #+#             */
/*   Updated: 2022/01/13 03:08:27 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*new_str;

	if (!s)
		return (NULL);
	if (start >= (ft_strlen(s)))
		return (ft_strdup(""));
		i = 0;
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	new_str = (char *)malloc(sizeof(char) *(len + 1));
	if (!new_str)
		return (0);
	while (len--)
	{
		new_str[i++] = s[start++];
	}
	new_str[i] = '\0';
	return (new_str);
}
