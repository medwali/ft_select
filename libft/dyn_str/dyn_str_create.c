/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_str_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:37:05 by mel-idri          #+#    #+#             */
/*   Updated: 2020/12/08 15:33:35 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/dyn_str_internal.h"

t_dyn_str	*dyn_str_create(size_t initial_capacity)
{
	t_dyn_str	*dyn_str;

	if (initial_capacity <= 0)
		initial_capacity = 16;
	else
		initial_capacity = get_close_power_of_2(initial_capacity);
	dyn_str = (t_dyn_str*)safe_malloc(sizeof(t_dyn_str));
	dyn_str->str = (char*)safe_malloc(initial_capacity * sizeof(char));
	dyn_str->str[0] = '\0';
	dyn_str->capacity = initial_capacity;
	dyn_str->len = 0;
	return (dyn_str);
}
