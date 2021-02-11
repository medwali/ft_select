/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 20:58:35 by mel-idri          #+#    #+#             */
/*   Updated: 2021/02/11 19:33:39 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		update_selection_state(t_selection_state *selection_state,
	char *buf)
{
	if (ft_strequ("\e[B", buf))
		move_cursor_to_next_element(selection_state);
	else if (ft_strequ("\e[A", buf))
		move_cursor_to_previous_element(selection_state);
	else if (ft_strequ("\e[C", buf))
		move_cursor_to_next_column(selection_state);
	else if (ft_strequ("\e[D", buf))
		move_cursor_to_previous_column(selection_state);
	else if (ft_strequ(" ", buf))
		toggle_element(selection_state);
	else if (ft_strequ("\e[3~", buf) || ft_strequ("\x7f", buf))
		delete_element(selection_state);
}

void			main_loop(t_selection_state **selection_state)
{
	ssize_t	ret;
	char	buf[5];

	while (*selection_state && (ret = read(get_term_fd(), buf, 4)) > 0)
	{
		buf[ret] = '\0';
		update_selection_state(*selection_state, buf);
		if (ft_strequ("\n", buf))
			break ;
		else if (ft_strequ("u", buf))
			update_terminal(*selection_state);
		if (ft_strequ("\e", buf) ||
				(*selection_state)->vector->length == 0)
			free_selection_state(selection_state);
	}
}
