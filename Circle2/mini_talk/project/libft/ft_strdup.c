/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 11:44:36 by hsabah            #+#    #+#             */
/*   Updated: 2023/01/12 00:27:14 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*sd;
	size_t	len;

	len = ft_strlen(s) + 1;
	sd = malloc(len);
	if (!len)
		return (0);
	ft_memcpy(sd, s, len);
	return (sd);
}
