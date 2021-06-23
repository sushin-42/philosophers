/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sushin <sushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:35:03 by sushin            #+#    #+#             */
/*   Updated: 2021/06/23 17:35:05 by sushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	r_value;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	minus = 1;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	r_value = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r_value = (r_value * 10) + (str[i] - 48);
		i++;
	}
	return (r_value * minus);
}
