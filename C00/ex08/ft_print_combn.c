/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:20:22 by rcarnero          #+#    #+#             */
/*   Updated: 2022/08/11 16:23:44 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_combn(int n);
void	ft_putchar(char c);
void	ft_print(int nb);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print_combn(int n)
{
	int i;
	int j;

	i = 0;
	while (i <= 99)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_print(i);
			ft_putchar(' ');
			ft_print(j);
			if (i < 98 || j < 99)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			j++;
		}
		i++;
	}
}

int main()
{
	ft_print_combn(20);
}