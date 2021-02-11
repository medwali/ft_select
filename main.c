/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 21:54:36 by mel-idri          #+#    #+#             */
/*   Updated: 2021/02/10 19:47:57 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_termios	g_orig_term_attrs;
t_winsize	g_winsize;
static void	init_terminal(void)
{
	if (tcgetattr(get_term_fd(), &g_orig_term_attrs) == -1)
		print_fatal_error(E_CANT_TCGETATTR);
	if (tgetent(NULL, getenv("TERM")) < 1)
		print_fatal_error(E_CANT_GET_TERM_DESC);
}

int			main(int argc, char **argv)
{
	t_selection_state	*selection_state;

	(void)argc;
	selection_state = init_selection_state(argv);
	if (selection_state == NULL)
		print_fatal_error(E_NO_ARGS_GIVEN);
	init_terminal();
	init_select_mode();
	init_signals();
	update_terminal(selection_state);
	main_loop(&selection_state);
	exit_select_mode();
	if (selection_state == NULL)
		return (0);
	print_selected_elements(selection_state->vector);
	return (0);
}
