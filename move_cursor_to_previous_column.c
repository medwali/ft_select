/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor_to_previous_column.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:05:37 by mel-idri          #+#    #+#             */
/*   Updated: 2021/02/08 09:32:02 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	move_cursor_to_previous_column(t_selection_state *selection_state)
{
	t_selection_state *const sel = selection_state;

	if ((int)(sel->cursor_pos - g_winsize.ws_row) < 0)
	{
		sel->cursor_pos +=
			sel->vector->length - (sel->vector->length % g_winsize.ws_row);
		if (sel->cursor_pos >= sel->vector->length)
			sel->cursor_pos -= g_winsize.ws_row;
	}
	else
		sel->cursor_pos -= g_winsize.ws_row;
	update_terminal(sel);
}
