# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/04 10:51:36 by mel-idri          #+#    #+#              #
#    Updated: 2021/02/04 11:07:25 by mel-idri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror
ifeq ($(DEBUG), true)
	CFLAGS = -g
endif
CC = gcc
SRCS = $(wildcard *.c) # TODO write down sources filenames
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
