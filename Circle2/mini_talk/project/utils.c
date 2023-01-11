/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:37:37 by hsabah            #+#    #+#             */
/*   Updated: 2023/01/12 00:00:46 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	moder(int chrNbr)
{
	return (chrNbr % 2);
}

int	divider(int chrNbr)
{
	return (chrNbr / 2);
}

int	*fill_bits(int *bits)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		bits[i] = 1 << i;
		i++;
	}
	return (bits);
}
