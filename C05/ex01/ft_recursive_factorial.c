/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:00:57 by rcarnero          #+#    #+#             */
/*   Updated: 2022/09/01 16:35:32 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	int	num;
	int	i;

	num = 1;
	i = 1;
	if (nb <= 0)
	{
		if (nb < 0)
			return (0);
		return (1);
	}
	else
		return (nb * ft_recursive_factorial (nb - 1));
}
