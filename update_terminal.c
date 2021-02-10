/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_terminal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 10:26:13 by mel-idri          #+#    #+#             */
/*   Updated: 2021/02/10 00:50:42 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	get_element_padding(t_selection_element_vec *vec)
{
	unsigned int i;
	unsigned int max_len;
	unsigned int curr_len;

	i = 0;
	max_len = 0;
	while (i < vec->length)
	{
		curr_len = ft_strlen(vec->array[i].value);
		if (curr_len > max_len)
			max_len = curr_len;
		i++;
	}
	max_len++;
	return (max_len);
}

static void	print_element(t_selection_element *elem, int is_under_cursor)
{
	if (elem->is_selected)
		tputs(tgetstr("mr", NULL), 1, ft_putchar_term);
	if (is_under_cursor)
		tputs(tgetstr("us", NULL), 1, ft_putchar_term);
	ft_putstr(elem->value);
	tputs(tgetstr("me", NULL), 1, ft_putchar_term);
}

static void	print_elements(t_selection_state *selection_state,
		int element_padding)
{
	unsigned int i;
	unsigned int j;
	t_selection_state *const sel = selection_state;

	i = 0;
	j = 0;
	while (j < sel->vector->length)
	{
		print_element(sel->vector->array + j, sel->cursor_pos == j);
		tputs(tgoto(tgetstr("LE", NULL), 0,
			ft_strlen(sel->vector->array[j].value)), 1, ft_putchar_term);
		tputs(tgoto(tgetstr("DO", NULL), 0, 1), 1, ft_putchar_term);
		i++;
		if (i == g_winsize.ws_row)
		{
			tputs(tgoto(tgetstr("UP", NULL), 0,
				g_winsize.ws_row), 1, ft_putchar_term);
			tputs(tgoto(tgetstr("RI", NULL), 0,
				element_padding), 1, ft_putchar_term);
			i = 0;
		}
		j++;
	}
}

void		update_terminal(t_selection_state *selection_state)
{
	int element_padding;
	t_selection_state *const sel = selection_state;

	if (!g_winsize.ws_col && !g_winsize.ws_row)
		update_dimensions();
	tputs(tgetstr("cl", NULL), 1, ft_putchar_term);
	element_padding = get_element_padding(sel->vector);
	if (ft_ceil(sel->vector->length, g_winsize.ws_row) * element_padding >
			g_winsize.ws_col)
		ft_putendl("Please, enlarge the window to print selections");
	else
		print_elements(selection_state, element_padding);
}
