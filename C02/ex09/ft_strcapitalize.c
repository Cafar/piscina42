/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:20:22 by rcarnero          #+#    #+#             */
/*   Updated: 2022/08/21 20:30:52 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	isnonum;

	i = 0;
	isnonum = 1;
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9')
			|| (str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z'))
		{
			if (isnonum == 1 && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] = str[i] - 32;
			else if (isnonum == 0 && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] = str[i] + 32;
			isnonum = 0;
		}
		else
			isnonum = 1;
		i++;
	}
	return (str);
}

// char	*ft_strcapitalize(char *str)
// {
// 	int		i;

// 	ft_tolower(str);
// 	i = 1;
// 	if (str[0] != '\0' && (str[i] >= 'a' && str[i] <= 'z'))
// 	{
// 		str[0] = str[0] - 32;
// 	}
// 	while (str[i] != '\0')
// 	{
// 		if ((str[i - 1] <= 47 || str[i - 1] >= 123)
// 			|| (str[i - 1] >= 58 && str[i - 1] <= 64)
// 			|| (str[i - 1] >= 91 && str[i - 1] <= 96))
// 		{
// 			if ((str[i] >= 'a' && str[i] <= 'z'))
// 			{
// 				str[i] = str[i] - 32;
// 			}
// 		}
// 		i++;
// 	}
// 	return (str);
// }

// void	ft_tolower(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] >= 'A' && str[i] <= 'Z')
// 		{
// 			str[i] = str[i] + 32;
// 		}
// 		i++;
// 	}
// }

// int main()
// {
// 		char hola[] = "salut, cOMMent tu vas 
//? 42mots quarante-deux; cinquante+et+un";    
// 		printf("%s", ft_strcapitalize(hola));
// }