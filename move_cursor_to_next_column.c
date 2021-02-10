/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor_to_next_column.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:05:32 by mel-idri          #+#    #+#             */
/*   Updated: 2021/02/08 09:07:02 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	move_cursor_to_next_column(t_selection_state *selection_state)
{
	t_selection_state *const sel = selection_state;

	sel->cursor_pos += g_winsize.ws_row;
	if (sel->cursor_pos >= sel->vector->length)
			sel->cursor_pos %= g_winsize.ws_row;
	update_terminal(sel);
}
