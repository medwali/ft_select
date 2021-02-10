/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_selection_state.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:17:14 by mel-idri          #+#    #+#             */
/*   Updated: 2021/02/07 17:57:24 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	free_selection_state(t_selection_state **selection_state)
{
	vector_free((t_vector*)(*selection_state)->vector);
	ft_memdel((void**)selection_state);
}
