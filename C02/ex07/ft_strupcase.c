/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:20:22 by rcarnero          #+#    #+#             */
/*   Updated: 2022/08/16 15:07:01 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strupcase(char *str)
{
	char	*aux;

	aux = str;
	while (*aux != '\0')
	{
		if (*aux >= 'a' && *aux <= 'z')
		{
			*aux = *aux - 32;
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