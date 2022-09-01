/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:57:41 by rcarnero          #+#    #+#             */
/*   Updated: 2022/08/10 13:59:51 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void);

void	ft_print_reverse_alphabet(void)
{
	int		i;
	int		b;
	char	ascii;

	i = 0;
	b = 'z';
	while (i < 26)
	{
		ascii = 'z' - i;
		write(1, &ascii, 1);
		i++;
	}
}
