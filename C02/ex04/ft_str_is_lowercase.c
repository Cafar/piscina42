/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:20:22 by rcarnero          #+#    #+#             */
/*   Updated: 2022/08/15 18:21:31 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	flag;

	flag = 1;
	while (*str != '\0')
	{
		if (*str < 'a' || *str > 'z')
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