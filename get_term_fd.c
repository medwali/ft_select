/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_term_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 23:59:58 by mel-idri          #+#    #+#             */
/*   Updated: 2021/02/10 16:58:08 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	get_term_fd(void)
{
	static int	fd;

	if (fd == 0)
	{
		fd = open("/dev/tty", O_RDWR);
		if (fd == -1)
			print_fatal_error(E_CANT_OPEN_TTY);
	}
	return (fd);
}
