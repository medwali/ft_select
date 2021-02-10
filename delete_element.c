/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:05:47 by mel-idri          #+#    #+#             */
/*   Updated: 2021/02/09 17:10:02 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	delete_element(t_selection_state *selection_state)
{
	vector_remove((t_vector*)selection_state->vector,
		selection_state->cursor_pos);
	if (selection_state->cursor_pos == selection_state->vector->length)
		selection_state->cursor_pos--;
	update_terminal(selection_state);
}
