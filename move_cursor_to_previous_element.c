/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor_to_previous_element.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:05:38 by mel-idri          #+#    #+#             */
/*   Updated: 2021/02/07 17:07:40 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	move_cursor_to_previous_element(t_selection_state *selection_state)
{
	selection_state->cursor_pos--;
	if ((int)selection_state->cursor_pos < 0)
		selection_state->cursor_pos = selection_state->vector->length - 1;
	update_terminal(selection_state);
}
