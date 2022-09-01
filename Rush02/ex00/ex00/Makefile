# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/27 12:58:47 by alvgomez          #+#    #+#              #
#    Updated: 2022/08/28 22:34:10 by alvgomez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/main.c src/ft_read_file.c src/ft_atoi.c src/ft_strdup.c src/ft_putstr.c src/ft_iterative_power.c src/ft_is_it_unsigned_int.c


all:
	@	gcc -o rush-02 -Wall -Wextra -Werror ${SRCS}
	
fclean:		
	@	rm  rush-02 2>/dev/null || true
	@	rm  .* 2>/dev/null || true

.PHONY: all fclean
	

