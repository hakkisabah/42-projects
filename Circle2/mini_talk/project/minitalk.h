/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:20:41 by hsabah            #+#    #+#             */
/*   Updated: 2023/01/12 00:02:19 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include "./libft/libft.h"

void	wrong_format_cl(char **argv);
void	wrong_format_srv(char **argv);
void	server_success(void);

int		moder(int chrNbr);
int		divider(int chrNbr);
char	*chr_to_bin(char chr);
void	ft_send_bits(int pid, char i, int sleepRatio);
void	collect_and_send(char **argv);

int		*fill_bits(int *bits);
void	server_handler(int signal, siginfo_t *info, void *context);

void	init_signals(void (handler)(int s, siginfo_t *i, void *c));
void	handle_errors(char *error_msg);
void	check_args(int argc, char **argv, int isServer);

#endif