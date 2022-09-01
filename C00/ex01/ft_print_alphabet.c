/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:48:24 by rcarnero          #+#    #+#             */
/*   Updated: 2022/08/10 13:57:25 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void);

void	ft_print_alphabet(void)
{
	char	ascii;
	int		i;

	i = 0;
	while (i < 26)
	{
		ascii = i + 'a';
		write(1, &ascii, 1);
		i++;
	}
}
