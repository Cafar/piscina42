/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:59:59 by frdescam          #+#    #+#             */
/*   Updated: 2022/08/25 19:08:08 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_check_wrong(char *base)
{
	int		i;
	int		j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] < 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nbrl;
	char	nbrc[32];
	int		length;
	int		i;

	if (!ft_check_wrong(base))
		return ;
	length = ft_strlen(base);
	if (nbr < 0)
	{
		nbrl = nbr;
		nbrl = -nbrl;
		ft_putchar('-');
	}
	else
		nbrl = nbr;
	i = 0;
	while (nbrl > 0)
	{
		nbrc[i] = base[nbrl % length];
		nbrl = nbrl / length;
		i++;
	}
	while (--i >= 0)
		ft_putchar(nbrc[i]);
}

int main()
{
	return 0;
}