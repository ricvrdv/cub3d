/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:38:27 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/11/05 22:38:27 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int			ft_printf(const char *format, ...);
int			ft_print_args(va_list args, char letter);
int			ft_print_char(char c);
int			ft_print_str(char *str);
int			ft_print_int(int nbr);
int			ft_print_unsign(unsigned int i);
int			ft_print_ptr(unsigned long ptr);
int			ft_print_hex(unsigned int nbr, int lower);

#endif
