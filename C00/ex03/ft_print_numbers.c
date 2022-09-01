/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:00:04 by rcarnero          #+#    #+#             */
/*   Updated: 2022/08/10 14:01:28 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void);

void	ft_print_numbers(void)
{
	int		i;
	char	ascii;

	i = 0;
	while (i < 10)
	{
		ascii = i + '0';
		write(1, &ascii, 1);
		i++;
	}
}
