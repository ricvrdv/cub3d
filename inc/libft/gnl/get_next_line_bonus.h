/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 12:40:50 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/09/27 12:40:51 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define OPEN_MAX 1024

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft.h"

char	*get_next_line(int fd);
char	*ft_strjoin_gnl_bonus(char const *s1, char const *s2);
size_t	ft_strlen_until(const char *s, char c);

#endif
