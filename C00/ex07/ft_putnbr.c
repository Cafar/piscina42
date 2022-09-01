/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:49:31 by rcarnero          #+#    #+#             */
/*   Updated: 2022/08/11 16:24:01 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_putnbr(int num);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int num)
{
	char	cadena[10];
	int		rest;
	int		i;

	i = 0;
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
		i++;
	}
	while (num > 10)
	{
		rest = num % 10;
		num = num / 10;
		cadena[i] = rest;
		i++;
	}
	cadena[i] = num;
	while (i >= 0)
	{
		ft_putchar(cadena[i] + 48);
		i--;
	}
}
