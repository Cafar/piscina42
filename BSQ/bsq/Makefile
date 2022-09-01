# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptejero- <ptejero-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/27 12:58:47 by alvgomez          #+#    #+#              #
#    Updated: 2022/09/01 11:44:20 by ptejero-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/main.c src/ft_putchar.c src/ft_read_file.c src/ft_atoi.c src/ft_putstr.c src/ft_find_obstacles.c src/ft_check_errors.c src/ft_putnbr.c


all:
	@	gcc -o bsq -Wall -Wextra -Werror ${SRCS}
	
fclean:		
	@	rm  bsq 2>/dev/null || true
	@	rm  .* 2>/dev/null || true

.PHONY: all fclean
	

