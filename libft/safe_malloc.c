/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 17:52:08 by mel-idri          #+#    #+#             */
/*   Updated: 2021/02/11 19:35:14 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*safe_malloc(size_t size)
{
	void	*ptr;

	if ((ptr = malloc(size)) == NULL)
	{
		ft_putendl_fd("malloc: failed to allocate memory", 2);
		exit(1);
	}
	return (ptr);
}
