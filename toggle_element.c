/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggle_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:05:41 by mel-idri          #+#    #+#             */
/*   Updated: 2021/02/07 10:01:35 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	toggle_element(t_selection_state *selection_state)
{
	t_selection_element *current_element;

	current_element =
		selection_state->vector->array + selection_state->cursor_pos;
	current_element->is_selected = !current_element->is_selected;
	move_cursor_to_next_element(selection_state);
}
