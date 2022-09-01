/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptejero- <ptejero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:59:14 by ptejero-          #+#    #+#             */
/*   Updated: 2022/08/31 20:25:37 by ptejero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_mylibs.h"

void	ft_read_first_line(int fd, char *t, int *bytes_read);

int	ft_check_matrix_errors(s_matrix *my_struct)
{
	int	i;
	int	j;

	i = 0;
	while (i < my_struct->data.rows)
	{
		j = 0;
		while (j < my_struct->data.cols)
		{
			if (my_struct->matrix[i][j] != my_struct->data.empty
				&& my_struct->matrix[i][j] != my_struct->data.obs)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_character_errors(s_matrix *my_struct)
{
	if (my_struct->data.cols == 0 || my_struct->data.rows == 0)
		return (1);
	if (my_struct->data.fill == '\0' || my_struct->data.empty == '\0'
		|| my_struct->data.obs == '\0')
		return (1);
	if (my_struct->data.fill == my_struct->data.obs
		|| my_struct->data.fill == my_struct->data.empty
		|| my_struct->data.obs == my_struct->data.empty)
		return (1);
	if (my_struct->data.fill < 32 || my_struct->data.fill > 126)
		return (1);
	if (my_struct->data.obs < 32 || my_struct->data.obs > 126)
		return (1);
	if (my_struct->data.empty < 32 || my_struct->data.empty > 126)
		return (1);
	return (0);
}

int	ft_check_lines_error(int fd)
{	
	char	t;
	int		bytes_read;		
	int		row_long;
	int		aux_row_long;

	row_long = 0;
	aux_row_long = 0;
	t = '\0';
	ft_read_first_line(fd, &t, &bytes_read);
	while (bytes_read != 0)
	{
		while (bytes_read != 0 && t != '\n')
		{
			row_long++;
			bytes_read = read(fd, &t, 1);
		}
		bytes_read = read(fd, &t, 1);
		if (aux_row_long == 0)
			aux_row_long = row_long;
		else if (aux_row_long != row_long)
			return (1);
		row_long = 0;
	}	
	return (0);
}

void	ft_read_first_line(int fd, char *t, int *bytes_read)
{
	*bytes_read = read(fd, t, 1);
	while (*bytes_read != 0 && *t != '\n')
		*bytes_read = read(fd, t, 1);
}
