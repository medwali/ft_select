/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_typedefs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 22:18:46 by mel-idri          #+#    #+#             */
/*   Updated: 2021/02/09 17:10:39 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_TYPEDEFS_H
# define FT_SELECT_TYPEDEFS_H

typedef struct termios		t_termios;
typedef struct				s_selection_element
{
	char					*value;
	int						is_selected;
}							t_selection_element;
typedef struct				s_selection_element_vec
{
	size_t					capacity;
	size_t					length;
	size_t					element_size;
	void					(*free_element)(void *element);
	t_selection_element		*array;
}							t_selection_element_vec;
typedef	struct				s_selection_state
{
	unsigned int			cursor_pos;
	t_selection_element_vec	*vector;
}							t_selection_state;
typedef struct winsize		t_winsize;

#endif
