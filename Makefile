# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdelattr <jdelattr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/27 14:54:48 by jdelattr          #+#    #+#              #
#    Updated: 2025/07/25 17:15:21 by jdelattr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap

CC= cc

CFLAGS= -Wextra -Werror -Wall -g3

CFILES= algorithm.c main.c parsing_utils.c parsing.c sort_utils.c sort.c\
split_args.c stack_utils.c stack.c cost.c move_r_rotate.c move_rotate.c\
algorithm_utils.c


DOFILES =.obj/
OFILES= $(addprefix $(DOFILES), $(CFILES:.c=.o))

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $(NAME)

$(DOFILES)%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(DOFILES)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re