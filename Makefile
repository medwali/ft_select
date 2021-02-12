# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-idri <mel-idri@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/04 10:51:36 by mel-idri          #+#    #+#              #
#    Updated: 2021/02/12 09:16:18 by mel-idri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror
ifeq ($(DEBUG), true)
	CFLAGS += -g
endif
CC = gcc
SRCS =	delete_element.c \
		exit_select_mode.c \
		free_selection_state.c \
		ft_putchar_term.c \
		get_term_fd.c \
		init_select_mode.c \
		init_selection_state.c \
		init_signals.c \
		main.c \
		main_loop.c \
		move_cursor_to_next_column.c \
		move_cursor_to_next_element.c \
		move_cursor_to_previous_column.c \
		move_cursor_to_previous_element.c \
		print_selected_elements.c \
		toggle_element.c \
		update_dimensions.c \
		update_terminal.c

OBJS = $(addprefix  objs/, $(SRCS:.c=.o))
INCLUDES = ft_select.h ft_select_typedefs.h

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -ltermcap $(LIBFT)

objs/%.o : %.c | objs
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS) : $(INCLUDES)

$(LIBFT): force
	$(MAKE) -C libft/

objs:
	mkdir objs

clean:
	$(MAKE) -C libft/ clean
	rm -rf objs

fclean: clean
	$(MAKE) -C libft/ fclean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

force:

.PHONY: all fclean re clean force
