/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_obstacles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptejero- <ptejero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:49:05 by ptejero-          #+#    #+#             */
/*   Updated: 2022/08/31 18:15:10 by ptejero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_mylibs.h"

void	ft_check_squares(int row, int col, s_matrix *my_struct);
void	ft_count(int *count, int *count_col);
int		ft_check_found(int *x, int *y, s_matrix my_struct);

void	ft_find_obstacles(s_matrix *my_struct, int row, int col)
{
	int	count_row;
	int	count_col;
	int	aux_col;
	int	aux_row;	

	count_row = 0;
	count_col = 0;
	aux_col = col;
	aux_row = row;
	if (my_struct->matrix[row][col] == my_struct->data.obs)
		return ;
	while (col < my_struct->data.cols
		&& my_struct->matrix[row][col] != my_struct->data.obs)
		ft_count(&col, &count_col);
	col = aux_col;
	while (row < my_struct->data.rows
		&& my_struct->matrix[row][col] != my_struct->data.obs)
		ft_count(&row, &count_row);
	row = aux_row;
	my_struct->max_lenght = count_row;
	if (count_row > count_col)
		my_struct->max_lenght = count_col;
	my_struct->max_lenght_square = my_struct->max_lenght;
	ft_check_squares(row, col, my_struct);
}

void	ft_count(int *count, int *count_col)
{
	*count = *count + 1;
	*count_col = *count_col + 1;
}

void	ft_check_squares(int row, int col, s_matrix *my_struct)
{
	int	x;
	int	y;
	int	temp;
	int	found;

	x = row + my_struct->max_lenght - 1;
	y = col + my_struct->max_lenght - 1;
	temp = x;
	found = 0;
	if (my_struct->max_lenght > 1)
	{
		while (x > row && found == 0)
			found = ft_check_found(&x, &y, *my_struct);
		x = temp;
		while (y > col && found == 0)
		{
			if (my_struct->matrix[x][y] == my_struct->data.obs)
				found = 1;
			y--;
		}
		my_struct->max_lenght--;
		if (found == 1)
			my_struct->max_lenght_square = my_struct->max_lenght;
		ft_check_squares(row, col, my_struct);
	}
}

int	ft_check_found(int *x, int *y, s_matrix my_struct)
{
	int	found;

	found = 0;
	if (my_struct.matrix[*x][*y] == my_struct.data.obs)
	{
		found = 1;
	}
	*x = *x - 1;
	return (found);
}
