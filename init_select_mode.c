/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_select_mode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:58:34 by mel-idri          #+#    #+#             */
/*   Updated: 2021/02/05 15:23:22 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	init_select_mode(void)
{
	t_termios term_attrs;

	term_attrs = g_orig_term_attrs;
	term_attrs.c_lflag &= ~(ECHO | ICANON);
	term_attrs.c_cc[VTIME] = 0;
	term_attrs.c_cc[VMIN] = 1;
	if (tcsetattr(0, TCSANOW, &term_attrs) == -1)
		print_fatal_error(E_CANT_TCSETATTR);
	tputs(tgetstr("ti", NULL), 1, ft_putchar_term);
	tputs(tgetstr("vi", NULL), 1, ft_putchar_term);
	tputs(tgetstr("ho", NULL), 1, ft_putchar_term);
}
