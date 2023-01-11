/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:17:30 by hsabah            #+#    #+#             */
/*   Updated: 2023/01/12 00:02:12 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include "./libft/libft.h"

void	wrong_format_cl(char **argv);
void	wrong_format_srv(char **argv);
void	server_success(void);

void	client_handler(int signum, siginfo_t *info, void *context);
int		check_len_limit(int length);
void	ft_bsend_bits(int pid, char i, int sleepRatio);

void	b_server_handler(int signal, siginfo_t *info, void *context);

void	init_signals(void (handler)(int s, siginfo_t *i, void *c));
void	handle_errors(char *error_msg);
void	check_args(int argc, char **argv, int isServer);

#endif