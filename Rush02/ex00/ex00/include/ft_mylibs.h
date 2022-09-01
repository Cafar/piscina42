/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mylibs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:57:00 by rcarnero          #+#    #+#             */
/*   Updated: 2022/08/28 23:17:30 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct t_dict
{
    int key;
    char *value;
} 	s_dict;


void	            ft_putchar(char c);
void	            ft_putnbr(int num);
void	            ft_putstr(char *str);
int	                ft_strlen(char *str);
unsigned int		ft_atoi(char *str);
char	            *ft_strdup(char *src);
s_dict              *ft_get_dict_from_file(char *file);
int	                ft_iterative_power(int nb, int power);
int	                ft_control_atoi(char *str, int cont);
int                 ft_is_it_unsigned_int(char *str);
