/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:17:43 by rcarnero          #+#    #+#             */
/*   Updated: 2022/09/01 13:36:57 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max);

int	*ft_range(int min, int max)
{
	int		i;
	int		res;
	int		*num;

	i = 0;
	res = max - min;
	if (max <= min)
	{
		return (NULL);
	}
	num = (int *)malloc(res);
	while (i < res)
	{
		num[i] = i + min;
		i++;
	}
	return (num);
}

// int main()
// {
// 	int start;
// 	int end;

// 	start = 5;
// 	end = 10;
// 	int *array;

// 	array = ft_range(start, end);
// 	int i = 0;
// 	while(i < 5)
// 	{
// 		printf("%d", array[i]);
// 		i++;
// 	}
// }