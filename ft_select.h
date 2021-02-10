/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 22:16:48 by mel-idri          #+#    #+#             */
/*   Updated: 2021/02/10 16:57:35 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "ft_select_typedefs.h"
# define E_CANT_TCGETATTR "ft_select: cannot get terminal attributes"
# define E_CANT_TCSETATTR "ft_select: cannot set terminal attributes"
# define E_CANT_GET_TERM_DESC "ft_select: cannot get terminal description"
# define E_NO_ARGS_GIVEN "ft_select: no arguments were given"
# define E_CANT_GET_WINSZ "ft_select: cannot get window size"
# define E_CANT_OPEN_TTY "ft_select: cannot open \"/dev/tty\""

extern t_termios
g_orig_term_attrs;
extern t_winsize
g_winsize;
void
init_select_mode(void);
t_selection_state
*init_selection_state(char **argv);
void
main_loop(t_selection_state **selection_state);
void
exit_select_mode(void);
void
print_selected_elements(t_selection_element_vec *vec);
void
move_cursor_to_previous_element(t_selection_state *selection_state);
void
move_cursor_to_next_column(t_selection_state *selection_state);
void
move_cursor_to_next_element(t_selection_state *selection_state);
void
move_cursor_to_previous_column(t_selection_state *selection_state);
void
toggle_element(t_selection_state *selection_state);
void
delete_element(t_selection_state *selection_state);
void
update_terminal(t_selection_state *selection_state);
void
update_dimensions(void);
void
free_selection_state(t_selection_state **selection_state);
void
init_signals(void);
int
get_term_fd(void);
int
ft_putchar_term(int c);

#endif
