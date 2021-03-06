/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 05:32:59 by mel-idri          #+#    #+#             */
/*   Updated: 2020/11/12 14:11:13 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/vector_internal.h"

t_vector	*vector_init(size_t element_size,
		void (*free_element)(void *element))
{
	t_vector *vec;

	vec = safe_malloc(sizeof(t_vector));
	vec->array = safe_malloc(element_size * 16);
	vec->capacity = 16;
	vec->element_size = element_size;
	vec->length = 0;
	vec->free_element = free_element;
	return (vec);
}
