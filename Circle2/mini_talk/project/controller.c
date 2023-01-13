/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:12:55 by hsabah            #+#    #+#             */
/*   Updated: 2023/01/13 14:20:52 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check_len_limit(int length)
{
	if (length >= 98)
	{
		sleep(1);
		return (0);
	}
	return (length);
}

void	init_signals(void (handler)(int signal, siginfo_t *info, void *context))
{
	struct sigaction	s_sigaction;

	s_sigaction.sa_sigaction = handler;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigemptyset(&s_sigaction.sa_mask);
	if (sigaction(SIGUSR1, &s_sigaction, NULL) == -1)
		handle_errors("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &s_sigaction, NULL) == -1)
		handle_errors("Failed to change SIGUSR2's behavior");
}

char	*chr_to_bin(char chr)
{
	char	*bin_arr;
	int		modered;
	int		divided;
	int		i;
	int		tmp_chr;

	bin_arr = malloc(sizeof(char) * (8 + 1));
	tmp_chr = (int)chr;
	i = 7;
	while (i >= 0)
	{
		modered = moder(tmp_chr);
		divided = divider(tmp_chr);
		bin_arr[i] = modered + '0';
		tmp_chr = divided;
		i--;
	}
	bin_arr[8] = '\0';
	return (bin_arr);
}
