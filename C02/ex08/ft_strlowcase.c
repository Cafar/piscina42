/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:20:22 by rcarnero          #+#    #+#             */
/*   Updated: 2022/08/15 18:48:24 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	char	*aux;

	aux = str;
	while (*aux != '\0')
	{
		if (*aux >= 'A' && *aux <= 'Z')
		{
			*aux = *aux + 32;
		}
		aux++;
	}
	return (str);
}

// int main()
// {
// 	char hola[40] = "aasd";    
// 	printf("%s", ft_strupcase(hola));
// }