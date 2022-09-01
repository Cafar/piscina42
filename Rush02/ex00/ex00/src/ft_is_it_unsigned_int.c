/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_it_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:47:30 by alvgomez          #+#    #+#             */
/*   Updated: 2022/08/28 22:22:22 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_control_atoi(char *str, int cont)
{
	unsigned long int	nbr;
	unsigned int		final;
	int					rest;

	nbr = 0;
	rest = 0;
	while (str[cont] >= '0' && str[cont] <= '9')
	{
		rest = str[cont] - '0';
		nbr = nbr * 10 + rest;
		cont++;
	}
	if (nbr > 4294967295)
		return (0);
	else
	{
		final = nbr;
		return (final);
	}
}

int	ft_is_it_unsigned_int(char *str)
{
	int				cont;
	unsigned int	nbr;

	cont = 0;
	while (str[cont] == ' '
		|| (str[cont] >= 9 && str[cont] <= 13))
		cont++;
	if (str[cont] < '0' || str[cont] > '9' )
		return (0);
	else
	{
		if (str[cont] == '0')
			return (1);
		else
		{
			nbr = ft_control_atoi(str, cont);
			if (nbr == 0)
				return (0);
			else
				return (1);
		}
	}
}

/*int	main(void)
{
	int	a;

	a = ft_is_it_unsigned_int("  429497796");
	printf("%d\n", a);
}*/
