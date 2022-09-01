/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mylibs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptejero- <ptejero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:57:00 by rcarnero          #+#    #+#             */
/*   Updated: 2022/09/01 13:48:15 by ptejero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIBS
#define MYLIBS

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct t_data
{
    char obs;
    char fill;
    char empty;
    int rows;
    int cols;
}   s_data;

typedef struct t_matrix
{
    char **matrix;
    char *first_line;
    int max_lenght;
    int max_lenght_square;
    int pos_row;
    int pos_col;
    s_data data;
} 	s_matrix;

void	            ft_putchar(char c);
void	            ft_putnbr(int num);
void	            ft_putstr(char *str);
int	                ft_strlen(char *str);
unsigned int		ft_atoi(char *str);
char	            *ft_strdup(char *src);
int		            ft_get_matrix_file(char *file, s_matrix *aux_matrix);
int	                ft_iterative_power(int nb, int power);
int	                ft_control_atoi(char *str, int cont);
int                 ft_is_it_unsigned_int(char *str);
int             	ft_check_matrix_errors(s_matrix *my_struct);
int                 ft_check_character_errors(s_matrix *my_struct);
int	                ft_check_lines_error(int fd);
void            	ft_find_obstacles(s_matrix *my_struct, int row, int col);
int		        read_from_std_input(void);

#endif