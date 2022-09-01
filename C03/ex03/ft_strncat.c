/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:20:22 by rcarnero          #+#    #+#             */
/*   Updated: 2022/08/21 20:41:05 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	cont;
	int				i;
	int				j;

	i = 0;
	cont = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0' && cont < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
		cont++;
	}
	dest[i] = '\0';
	return (dest);
}

// int main()
// {

// 	char str1[15] = "HOLA";
// 	char str2[15] = "ADIOS";
// 	char str3[15] = "HOLA";
// 	char str4[15] = "ADIOS";

//    printf("%s\n", ft_strncat(str1, str2, 10));
//    printf("%s\n", strncat(str3, str4, 10));
//    return(0);
// }