/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:48:56 by hsabah            #+#    #+#             */
/*   Updated: 2023/01/11 23:21:00 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_bits(int pid, char i, int sleepRatio)
{
	char	*bit;
	int		j;

	bit = chr_to_bin(i);
	j = 7;
	while (j >= 0)
	{
		if (bit[j] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		if (sleepRatio > 0)
			usleep(sleepRatio * 200);
		else
			usleep(300);
		j--;
	}
	free(bit);
}

void	collect_and_send(char **argv)
{
	int		pid;
	int		i;

	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
	{
		ft_send_bits(pid, argv[2][i], (ft_strlen(argv[2]) / 96));
		i++;
	}
	ft_send_bits(pid, '\n', 1);
}

int	main(int argc, char **argv)
{
	check_args(argc, argv, 0);
	collect_and_send(argv);
	return (0);
}
