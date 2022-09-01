/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:20:22 by rcarnero          #+#    #+#             */
/*   Updated: 2022/08/15 17:26:48 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	flag;

	flag = 1;
	while (*str != '\0')
	{
		if ((*str < 'a' || *str > 'z') && (*str < 'A' || *str > 'Z'))
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
// 	char hola[40] = "!";    
// 	printf("%d", ft_str_is_alpha(&hola));
// }