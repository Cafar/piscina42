/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:20:22 by rcarnero          #+#    #+#             */
/*   Updated: 2022/08/21 20:33:56 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	res;

	i = 0;
	res = 0;
	while (src[res])
		res++;
	if (size < 1)
		return (res);
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (res);
}

// unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size)
// {
// 	unsigned int	cont;
// 	unsigned int	cont2;

// 	cont2 = 0;
// 	while (src[cont2] != '\0')
// 	{
// 		cont2++;
// 	}
// 	cont = 0;
// 	while (src[cont] != '\0' && cont < size)
// 	{
// 		dest[cont] = src[cont];
// 		cont++;
// 	}
// 	dest[cont] = '\0';
// 	return (cont2);
// }

// int main()
// {
// 	char hola[40] = "hola cara de cola";
//     char hola2[12];
// 	char hola3[40] = "hola cara de cola";
//     char hola4[12];
//     unsigned int i = ft_strlcpy(hola2, hola, 0);
// 	unsigned int j = strlcpy(hola4, hola3, 0);
// 	printf("%s con tamaño: %d \n", hola2, i);
// 	printf("%s con tamaño: %d \n", hola4, j);
// }