# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maboulho <maboulho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 14:55:49 by maboulho          #+#    #+#              #
#    Updated: 2022/06/17 21:45:46 by maboulho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
SRCS = push_swap.c push_swap_utils.c push_swap_utils2.c operations.c operations2.c small_sort.c \
		check_args.c ft_atoi.c index.c  big_sort.c push_swap_utils3.c sort.c mid_sort.c sort_100.c
BONUS_SRCS = checker_utils_bonus3.c  get_next_line_utils.c get_next_line.c push_swap_utils.c push_swap_utils2.c push_swap_utils3.c checker_utils_bonus.c checker_utils_bonus2.c check_args.c ft_atoi.c index.c checker.c
FLAGS	=	-Wall -Werror -Wextra

CC		=	gcc

	
${NAME} :
	${CC} ${CFLAGS} -o ${NAME} ${SRCS}
${BONUS} :
	${CC} ${CFLAGS} -o ${BONUS} ${BONUS_SRCS}

all: ${NAME} 

bonus: ${BONUS} 


	
clean:
	rm -f ${NAME}
fclean: clean
	rm -f $(BONUS)

re: fclean all

.PHONY: all clean fclean re