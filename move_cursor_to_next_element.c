/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor_to_next_element.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:05:35 by mel-idri          #+#    #+#             */
/*   Updated: 2021/02/07 10:23:38 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	move_cursor_to_next_element(t_selection_state *selection_state)
{
	selection_state->cursor_pos =
		(selection_state->cursor_pos + 1) % selection_state->vector->length;
	update_terminal(selection_state);
}
