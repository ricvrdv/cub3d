/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:39:10 by ddo-carm          #+#    #+#             */
/*   Updated: 2025/04/18 15:42:40 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRAS_H
# define EXTRAS_H

# include "../libft.h"

void	close_pipe(int *fd);
void	errors(char *message, char *complete, int if_exit);
void	free_arrays(void **array);
void	free_matrix(void ***matrix);
int		ft_atoi_base(const char *str, int base);
long	ft_atol(const char *nptr);
int		ft_is_space(char c);
int		ft_is_directory(const char *path);

#endif
