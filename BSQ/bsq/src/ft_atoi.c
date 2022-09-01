/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:01:54 by rcarnero          #+#    #+#             */
/*   Updated: 2022/08/28 23:12:54 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int					ft_isodd(unsigned int num);
unsigned int		ft_atoi(char *str);
int					ft_check_sign(int sign);

int	ft_isodd(unsigned int num)
{
	return (num % 2);
}

unsigned int	ft_atoi(char *str)
{
	unsigned int	num;
	int				i;
	int				sign;

	num = 0;
	i = 0;
	sign = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign--;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	sign = ft_check_sign(sign);
	return (sign * num);
}

int	ft_check_sign(int sign)
{
	if (sign % 2 == 0)
		sign = 1;
	else
		sign = -1;
	return (sign);
}
