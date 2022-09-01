/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:20:22 by rcarnero          #+#    #+#             */
/*   Updated: 2022/08/21 20:44:37 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	while (i < (size - dest_len - 1) && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	if (size > dest_len)
	{
		return (dest_len + src_len);
	}
	return (src_len + size);
}

// unsigned	int	ft_strlcat(char *dest, char *src, unsigned int size)
// {
// 	unsigned int	i;
// 	int				j;
// 	unsigned int	cont;

// 	i = 0;
// 	cont = 0;
// 	while (src[cont] != '\0')
// 	{
// 		cont++;
// 	}
// 	cont += size;
// 	while (dest[i] != '\0')
// 	{
// 		i++;
// 	}
// 	j = 0;
// 	while (src[j] != '\0' && size > i)
// 	{
// 		dest[i] = src[j];
// 		i++;
// 		j++;
// 	}
// 	dest[i] = '\0';
// 	return (cont);
// }

// int main()
// {

// 	char str1[15] = "HOLA";
// 	char str2[15] = "ADIOSS";
// 	unsigned int a = strlcat(str1, str2, 10);
// 	char str3[15] = "HOLA";
// 	char str4[15] = "ADIOSS";
// 	unsigned int b = ft_strlcat(str3, str4, 10);

// 	printf("%s y tamaño: %d\n",str1, a);
//    printf("%s y tamaño: %d",str3, b);
//    return(0);
// }