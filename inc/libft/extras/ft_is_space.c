/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:34:08 by ddo-carm          #+#    #+#             */
/*  Updated:    2025/09/15 22:36:55                                             */
/*                                                                            */
/* ************************************************************************** */

#include "extras.h"

//info   --> Check if char is space
//c      --> Char to check
//return --> Success (1)
//return --> Failure (0)

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}
