/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:36:53 by hsabah            #+#    #+#             */
/*   Updated: 2023/01/12 00:15:23 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	client_handler(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signum == SIGUSR2)
		write(1, "Character has been sucessfully receieved!\n", 42);
}

void	server_handler(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static int	i;
	int			arr[8];

	ft_memcpy(arr, fill_bits(arr), 8);
	(void)context;
	(void)info;
	if (signal == SIGUSR1)
		i += arr[bit];
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
}

void	b_server_handler(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static int	i;
	int			arr[8];

	ft_memcpy(arr, fill_bits(arr), 8);
	(void)context;
	(void)info;
	if (signal == SIGUSR1)
		i += arr[bit];
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
		if (kill(info->si_pid, SIGUSR2) == -1)
			handle_errors("Server failed to send SIGUSR2");
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		handle_errors("Failed to send SIGUSR1");
}
