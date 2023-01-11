/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:50:39 by hsabah            #+#    #+#             */
/*   Updated: 2023/01/11 22:38:18 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_bsend_bits(int pid, char i, int sleepRatio)
{
	static int		total;
	int				bit;

	total++;
	total = check_len_limit(total);
	if (total >= 99)
		handle_errors("Error occured while send bits");
	bit = 0;
	while (bit < 8)
	{
		if ((i & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		if (sleepRatio > 0)
			usleep(sleepRatio * 200);
		else
			usleep(200);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	init_signals(client_handler);
	check_args(argc, argv, 0);
	i = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
	{
		ft_bsend_bits(pid, argv[2][i], (ft_strlen(argv[2]) / 96));
		i++;
	}
	ft_bsend_bits(pid, '\n', 1);
	return (0);
}
