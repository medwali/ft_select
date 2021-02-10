/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_select_mode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:06:13 by mel-idri          #+#    #+#             */
/*   Updated: 2021/02/10 00:50:42 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	exit_select_mode(void)
{
	tputs(tgetstr("te", NULL), 1, ft_putchar_term);
	tputs(tgetstr("ve", NULL), 1, ft_putchar_term);
	if (tcsetattr(0, TCSANOW, &g_orig_term_attrs) == -1)
		print_fatal_error(E_CANT_TCSETATTR);
}
