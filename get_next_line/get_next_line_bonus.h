/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:11:10 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/01/30 16:42:05 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

//	utils funcs()
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
void	ft_strlcpy(char *dst, char *src, size_t size);
int		ft_chrfind(char *str, int c);
//	get_next_line funcs()
char	*get_next_line(int fd);
char	*fileread(int fd, char *s);
char	*get_first_line(char *s);
char	*after_line(char *s);

#endif