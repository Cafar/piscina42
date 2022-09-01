/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptejero- <ptejero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 21:02:28 by rcarnero          #+#    #+#             */
/*   Updated: 2022/09/01 14:38:34 by ptejero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_mylibs.h"

void		ft_fill_matrix(s_matrix *mystruct, int fd);
void		ft_fill_the_data(int fd, s_matrix *my_struct);
void		ft_set_matrix_memory(s_matrix *mystruct);
int			read_from_std_input(void);

int	ft_get_matrix_file(char *file, s_matrix *aux_matrix)
{
	int			fd;	

	fd = open(file, O_RDONLY);
	if (fd == -1 || ft_check_lines_error(fd) == 1)
	{
		close(fd);
		return (1);
	}	
	close(fd);
	fd = open(file, O_RDONLY);
	ft_fill_the_data(fd, aux_matrix);
	close(fd);
	ft_set_matrix_memory(aux_matrix);
	fd = open(file, O_RDONLY);
	ft_fill_matrix(aux_matrix, fd);	
	if (ft_check_character_errors(aux_matrix) == 1
		|| ft_check_matrix_errors(aux_matrix) == 1)
	{
		return (1);
		close(fd);
	}
	close(fd);
	return (0);
}

void	ft_set_matrix_memory(s_matrix *mystruct)
{
	int	i;

	i = 0;
	mystruct->matrix = (char **)malloc(mystruct->data.rows * sizeof(char *));
	if (mystruct->matrix == NULL)
	{
		ft_putstr("no dinamic memory for col");
	}
	else
	{
		while (i <= mystruct->data.cols)
		{
			mystruct->matrix [i]
				= (char *)malloc(mystruct->data.cols * sizeof(char));
			if (mystruct->matrix[i] == NULL)
			{
				ft_putstr("no dinamic memory for col");
			}
			i++;
		}
	}
}

void	ft_fill_matrix(s_matrix *mystruct, int fd)
{
	int		bytes_read;
	int		i;	
	int		j;
	char	t;

	i = 0;
	t = '\0';
	bytes_read = read(fd, &t, 1);
	while (t != '\n')
		bytes_read = read(fd, &t, 1);
	while (i < mystruct->data.rows && bytes_read != 0)
	{
		bytes_read = read(fd, &t, 1);
		j = 0;
		while (t != '\n' && bytes_read != 0)
		{			
			//ft_putchar(t);
			mystruct->matrix[i][j] = t;
			j++;
			bytes_read = read(fd, &t, 1);
		}
		i++;
	}
}

void	ft_fill_the_data(int fd, s_matrix *my_struct)
{	
	char	t;
	int		bytes_read;	

	t = '\0';
	bytes_read = read(fd, &t, 1);
	while (t >= '0' && t <= '9')
	{
		my_struct->data.rows = (my_struct->data.rows * 10) + ft_atoi(&t);
		bytes_read = read(fd, &t, 1);
	}
	my_struct->data.empty = t;
	bytes_read = read(fd, &t, 1);
	my_struct->data.obs = t;
	bytes_read = read(fd, &t, 1);
	my_struct->data.fill = t;
	bytes_read = read(fd, &t, 1);
	while (t != '\n')
		bytes_read = read(fd, &t, 1);
	bytes_read = read(fd, &t, 1);
	while (bytes_read != 0 && t != '\n')
	{
		my_struct->data.cols++;
		bytes_read = read(fd, &t, 1);
	}	
}

int	read_from_std_input(void)
{	
	char	buf;
	int		fd;

	buf = '\0';
	fd = open("my_input.txt", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		close(fd);
		return (1);
	}
	while (read(0, &buf, 1) > 0)
		write (fd, &buf, 1);
	close(fd);
	return (0);
}
