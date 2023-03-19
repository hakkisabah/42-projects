/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:31:24 by hsabah            #+#    #+#             */
/*   Updated: 2023/03/20 00:43:54 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	throw_error(char *str)
{
	printf("%s\n", str);
	return (1);
}

int	manage_error(int err_no)
{
	if (err_no == 1)
		printf("At least one wrong argument\n");
	if (err_no == 2)
		printf("Fatal error when intializing mutex\n");
	return (1);
}
