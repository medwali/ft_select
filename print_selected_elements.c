/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_selected_elements.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:16:35 by mel-idri          #+#    #+#             */
/*   Updated: 2021/02/08 09:47:24 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_selected_elements(t_selection_element_vec *vec)
{
	size_t	i;
	int		is_first_selected;

	i = 0;
	is_first_selected = 1;
	while (i < vec->length)
	{
		if (vec->array[i].is_selected)
		{
			if (is_first_selected)
				is_first_selected = 0;
			else
				ft_putchar(' ');
			ft_putstr(vec->array[i].value);
		}
		i++;
	}
	if (is_first_selected == 0)
		ft_putchar('\n');
}
