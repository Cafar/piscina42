/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:20:22 by rcarnero          #+#    #+#             */
/*   Updated: 2022/08/19 09:19:00 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n <= 0)
	{
		return (0);
	}
	while (s1[i] == s2[i])
	{
		if (i >= n - 1)
		{
			return (0);
		}
		if (s1[i] == '\0' && s2[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

// int main()
// {

// 	char str1[15] = "";
// 	char str2[15] = "";
// 	int ret;

// 	ret = ft_strncmp(str1, str2, 5);
// 	//ret = strncmp(str1, str2, 5);

//    if(ret < 0) {
//       printf("str1 is less than str2");
//    } else if(ret > 0) {
//       printf("str2 is less than str1");
//    } else {
//       printf("str1 is equal to str2");
//    }
//    return(0);
// }