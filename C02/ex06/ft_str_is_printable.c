/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:20:22 by rcarnero          #+#    #+#             */
/*   Updated: 2022/08/15 18:23:20 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	flag;

	flag = 1;
	while (*str != '\0')
	{
		if (*str < 32 || *str > 127)
		{
			flag = 0;
			return (flag);
		}
		str++;
	}
	return (flag);
}

// int main()
// {
// 	char hola[40] = "aasd";    
// 	printf("%d", ft_str_is_lowercase(hola));
// }