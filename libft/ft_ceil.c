/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 11:01:59 by mel-idri          #+#    #+#             */
/*   Updated: 2021/02/07 11:31:20 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_ceil(unsigned int dividend, unsigned int divisor)
{
	int result;

	result = dividend / divisor;
	result += dividend % divisor != 0 ? 1 : 0;
	return (result);
}
