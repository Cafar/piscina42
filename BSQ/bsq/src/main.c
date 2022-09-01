/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptejero- <ptejero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:29:33 by rcarnero          #+#    #+#             */
/*   Updated: 2022/09/01 14:16:21 by ptejero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_mylibs.h"

void	ft_check_if_arg_good(int argc, char **argv);
void	ft_do_the_magic(s_matrix my_struct);
int		find_max_lenth_square(s_matrix *my_struct);
void	ft_free_memory(char **matrix, int rows);

int	main(int argc, char **argv)
{
	s_matrix	my_struct;

	if (argc == 1)
	{
		if (read_from_std_input() == 0)
		{
			if (ft_get_matrix_file("my_input.txt", &my_struct) == 0)
			{
				ft_do_the_magic(my_struct);
				ft_free_memory(my_struct.matrix, my_struct.data.rows);
			}
		}
	}
	else
	{
		ft_check_if_arg_good(argc, argv);
	}
	return (0);
}

void	ft_check_if_arg_good(int argc, char **argv)
{
	int			i;
	s_matrix	*my_struct;

	i = 1;
	my_struct = (s_matrix *)malloc((argc - 1) * sizeof(s_matrix));
	while (i < argc)
	{
		my_struct[i - 1].data.cols = 0;
		my_struct[i - 1].data.rows = 0;
		my_struct[i - 1].data.obs = '\0';
		my_struct[i - 1].data.empty = '\0';
		if (ft_get_matrix_file(argv[i], &my_struct[i - 1]) == 0)
		{
			ft_do_the_magic(my_struct[i - 1]);
			ft_free_memory(my_struct[i - 1].matrix, my_struct[i - 1].data.rows);
			ft_putchar('\n');
		}
		else
		{
			ft_putstr("Map Error\n");
			return ;
		}
		i++;
	}
}

void	ft_free_memory(char **matrix, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	ft_do_the_magic(s_matrix my_struct)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = 0;
	max = find_max_lenth_square(&my_struct);
	while (i < my_struct.data.rows)
	{
		j = 0;
		while (j < my_struct.data.cols)
		{
			if ((i >= my_struct.pos_row && i < my_struct.pos_row + max)
				&& j >= my_struct.pos_col && j < my_struct.pos_col + max)
				ft_putchar(my_struct.data.fill);
			else
				ft_putchar(my_struct.matrix[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	find_max_lenth_square(s_matrix *my_struct)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = 0;
	max = 0;
	while (i < my_struct->data.rows)
	{
		j = 0;
		while (j < my_struct->data.cols)
		{
			ft_find_obstacles(my_struct, i, j);
			if (max < my_struct->max_lenght_square)
			{
				my_struct->pos_row = i;
				my_struct->pos_col = j;
				max = my_struct->max_lenght_square;
			}
			j++;
		}
		i++;
	}
	return (max);
}
