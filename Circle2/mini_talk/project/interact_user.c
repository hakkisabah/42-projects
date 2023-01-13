/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_user.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:57:07 by hsabah            #+#    #+#             */
/*   Updated: 2023/01/13 15:27:08 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "minitalk_bonus.h"

void	handle_errors(char *error_msg)
{
	write(STDERR_FILENO, "Error: ", 7);
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

void	wrong_format_cl(char **argv)
{
	ft_putstr_fd("\033[91mError: wrong format.\033[0m\n", 1);
	ft_putstr_fd("\033[33mTry: ", 1);
	ft_putstr_fd(argv[0], 1);
	ft_putstr_fd(" <PID> <MESSAGE>\033[0m\n", 1);
	exit(EXIT_FAILURE);
}

void	wrong_format_srv(char **argv)
{
	ft_putstr_fd("\033[91mError: wrong format.\033[0m\n", 1);
	ft_putstr_fd("\033[33mTry: ", 1);
	ft_putstr_fd(argv[0], 1);
	ft_putstr_fd("\033[0m\n", 1);
	exit(EXIT_FAILURE);
}

void	server_success(void)
{
	ft_putstr_fd("\033[94mPID\033[0m \033[96m->\033[0m", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n\033[90mWaiting for a message...\033[0m\n", 1);
}

void	check_args(int argc, char **argv, int isServer)
{
	int	i;

	i = 0;
	if (isServer && argc != 1)
	{
		wrong_format_srv(argv);
	}
	if (!isServer && argc != 3)
		wrong_format_cl(argv);
	while (!isServer && argv[1][i])
		if (!ft_isdigit(argv[1][i++]))
			handle_errors("Invalid PID");
	if (!isServer && *argv[2] == 0)
		handle_errors("Invalid message (empty)");
	if (isServer)
		server_success();
}
