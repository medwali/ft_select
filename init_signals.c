/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:13:51 by mel-idri          #+#    #+#             */
/*   Updated: 2021/02/09 19:13:26 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	signals_handler(int sig_num)
{
	if (sig_num == SIGWINCH)
	{
		update_dimensions();
		ioctl(0, TIOCSTI, "u");
	}
	else if (sig_num == SIGTSTP)
	{
		exit_select_mode();
		signal(SIGTSTP, SIG_DFL);
		ioctl(0, TIOCSTI, "\x1a");
	}
	else if (sig_num == SIGCONT)
	{
		init_select_mode();
		ioctl(0, TIOCSTI, "u");
		signal(SIGTSTP, signals_handler);
	}
}

void		init_signals(void)
{
	int i;

	i = 1;
	while (i < 32)
	{
		signal(i++, signals_handler);
	}
}
