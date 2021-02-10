/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_dimensions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 10:37:52 by mel-idri          #+#    #+#             */
/*   Updated: 2021/02/10 12:22:13 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	update_dimensions(void)
{
	if (ioctl(get_term_fd(), TIOCGWINSZ, &g_winsize) == -1)
	{
		exit_select_mode();
		print_fatal_error(E_CANT_GET_WINSZ);
	}
}
