/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_term.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 00:39:04 by mel-idri          #+#    #+#             */
/*   Updated: 2021/02/10 00:51:51 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	ft_putchar_term(int c)
{
	static int	fd;

	if (fd == 0)
		fd = get_term_fd();
	return (write(fd, &c, 1));
}
