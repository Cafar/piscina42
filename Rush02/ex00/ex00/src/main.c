/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:29:33 by rcarnero          #+#    #+#             */
/*   Updated: 2022/08/28 23:26:25 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_mylibs.h"

void	ft_print_dict(int leftNumber, int div, s_dict *my_dict);
void	ft_print_value(s_dict *my_dict, int num);
int		how_long_num(int num);
void	ft_do_the_magic(s_dict *my_dict, int num);

int	main(int argc, char **argv)
{
	unsigned int	number;
	s_dict			*my_dict;

	number = 0;
	if (argc == 2)
	{
		if (ft_is_it_unsigned_int(argv[1]) == 1)
		{
			number = ft_atoi(argv[1]);
			my_dict = ft_get_dict_from_file("src/numbers.dict");
			if(number == 0)
				ft_putstr(my_dict[0].value);
			else
				ft_do_the_magic(my_dict, number);
		}
		else
			ft_putstr("Error\n");
	}
	else if (argc == 3)
	{
		if (ft_is_it_unsigned_int(argv[1]) == 1)
		{
			number = ft_atoi(argv[1]);
			my_dict = ft_get_dict_from_file(argv[2]);
			if(number == 0)
				ft_putstr(my_dict[0].value);
			else
				ft_do_the_magic(my_dict, number);
		}
		else
			ft_putstr("Dict Error\n");
	}
	else
		ft_putstr("Error\n");
	return (0);
}

void	ft_do_the_magic(s_dict *my_dict, int num)
{
	int toDiv = 1;
    int length = how_long_num(num);
    int i = 1;
    int leftNumber;
    int myPow = 0;
    while(i < length)
    {
        toDiv *= 10;
        i++;
    }
    while(length > 3)
    {
 	length--;
        while (length % 3 != 0)
            length--;
        myPow = ft_iterative_power(10, length);
        ft_do_the_magic(my_dict, num / myPow);
        i=0;
        ft_print_value(my_dict, myPow);
        num %= myPow;
        length--;
        toDiv = 100;
    }
    if(num != 0)
    {
        if(toDiv == 10)
        {
            if(num >= 10 && num <= 19)
            {
                ft_print_dict(num, toDiv, my_dict);
                return;
            }
        }
        leftNumber = num / toDiv;
        ft_print_dict(leftNumber, toDiv, my_dict);
        ft_do_the_magic(my_dict, num % toDiv);
	}
}

void	ft_print_dict(int leftNumber, int div, s_dict *my_dict)
{
	if (div > 99)
	{
		ft_print_value(my_dict, leftNumber);
		ft_print_value(my_dict, div);
	}
	else if (leftNumber >= 10 && leftNumber <= 19)
	{
		ft_print_value(my_dict, leftNumber);
	}
	else if (div == 10 && leftNumber > 1)
	{
		leftNumber *= div;
		ft_print_value(my_dict, leftNumber);
	}
	else
	{
		ft_print_value(my_dict, leftNumber);
	}
}

void	ft_print_value(s_dict *my_dict, int num)
{
	int	i;

	i = 0;
	while (my_dict[i].key != num)
		i++;
	ft_putstr (my_dict[i].value);
	ft_putstr (" ");
}

int	how_long_num(int num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}
