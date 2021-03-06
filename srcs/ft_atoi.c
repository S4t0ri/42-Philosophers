/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructio.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:48:02 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/03/08 19:32:46 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sophos.h"

static	int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\v'
		|| c == '\n' || c == '\r' || c == '\t')
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

bool	ft_atoi(const char *str, int *res)
{
	int		sign;
	long	result;
	int		counter;

	sign = 1;
	result = 0;
	counter = 0;
	while (ft_isspace (str[counter]))
		counter ++;
	if (str[counter] == '+')
		counter++;
	else if (str[counter] == '-')
	{
		sign = -1;
		counter++;
	}
	while (ft_isdigit(str[counter]))
	{
		result = result * 10 + (str[counter] - '0');
		if (result > INT_MAX || result * sign < INT_MIN)
			return (false);
		counter++;
	}
	*res = result * sign;
	return (true);
}
