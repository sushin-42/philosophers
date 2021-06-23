/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sushin <sushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 21:09:07 by sushin            #+#    #+#             */
/*   Updated: 2021/06/23 21:09:08 by sushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pthread_create_error_check(int thr_err_chk)
{
	if (thr_err_chk < 0)
	{
		perror("thread create error : ");
		exit(0);
	}
}
