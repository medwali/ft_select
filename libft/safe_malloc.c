/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 17:52:08 by mel-idri          #+#    #+#             */
/*   Updated: 2020/11/28 01:45:23 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*safe_malloc(size_t size)
{
	void	*ptr;

	if((ptr = malloc(size)) == NULL)
	{
		ft_putendl_fd("malloc: failed to allocate memory", 2);
		exit(1);
	}
	return (ptr);
}
