/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:18:07 by rcarnero          #+#    #+#             */
/*   Updated: 2022/09/01 16:38:09 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	int	num;

	num = nb;
	if (nb == 0 && power == 0)
		return (1);
	if (power < 0)
		return (0);
	if (power == 1)
		return (nb);
	num = num * nb;
	if (nb < 0)
		num = -num;
	return (ft_recursive_power(num, power - 1));
}
