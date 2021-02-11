/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_selection_state.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 18:11:08 by mel-idri          #+#    #+#             */
/*   Updated: 2021/02/11 19:29:00 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_selection_state	*init_selection_state(char **argv)
{
	t_selection_state	*selection_state;
	t_selection_element	selection_element;

	if (argv[0] == NULL || argv[1] == NULL)
		return (NULL);
	selection_state = safe_malloc(sizeof(t_selection_state));
	selection_state->cursor_pos = 0;
	selection_state->vector = (t_selection_element_vec *)
		vector_init(sizeof(t_selection_element), NULL);
	selection_element.is_selected = 0;
	argv++;
	while (*argv)
	{
		selection_element.value = *argv;
		vector_push((t_vector *)selection_state->vector,
					&selection_element);
		argv++;
	}
	return (selection_state);
}
