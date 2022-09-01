/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarnero <rcarnero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 21:02:28 by rcarnero          #+#    #+#             */
/*   Updated: 2022/08/28 19:46:06 by rcarnero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_mylibs.h"

int		ft_get_file_size(int fd, int *max_size_line);
char	*ft_get_key_value(int fd, char *c, char to_compare, int max_size_line);
void	ft_fill_dict(s_dict *aux_dict, int fd, int size, int max_size_line);
void	ft_check_dict_error(int fd);

s_dict	*ft_get_dict_from_file(char *file)
{
	s_dict	*aux_dict;
	int		dict_size;
	int		max_size_line;
	int		fd;

	max_size_line = 0;
	fd = open(file, O_RDONLY);
	ft_check_dict_error(fd);
	dict_size = ft_get_file_size(fd, &max_size_line);
	close(fd);
	aux_dict = (s_dict *)malloc(dict_size * sizeof(s_dict));
	if (aux_dict == NULL)
		write (1, "Error\n", 7);
	else
	{
		fd = open(file, O_RDONLY);
		ft_check_dict_error(fd);
		ft_fill_dict(aux_dict, fd, dict_size, max_size_line);
		close(fd);
	}
	return (aux_dict);
}

void	ft_fill_dict(s_dict *aux_dict, int fd, int size, int max_size_line)
{
	int		bytes_read;
	char	*temp;	
	int		i;
	char	t;

	i = 0;
	t = '\0';
	while (i < size)
	{	
		bytes_read = read(fd, &t, 1);
		while (t == ' ')
			bytes_read = read(fd, &t, 1);
		temp = ft_get_key_value(fd, &t, ':', max_size_line);
		aux_dict[i].key = ft_atoi(temp);
		free(temp);
		bytes_read = read(fd, &t, 1);
		while (t == ' ')
			bytes_read = read(fd, &t, 1);
		temp = ft_get_key_value(fd, &t, '\n', max_size_line);
		aux_dict[i].value = ft_strdup(temp);
		free(temp);
		i++;
	}
}

char	*ft_get_key_value(int fd, char *c, char to_compare, int max_size_line)
{
	int		i;
	char	*str;
	int		bytes_read;

	str = (char *)malloc(max_size_line * sizeof(char));
	i = 0;
	bytes_read = 1;
	while (*c != to_compare && bytes_read != 0)
	{
		str[i] = *c;
		bytes_read = read(fd, c, 1);
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_get_file_size(int fd, int *max_size_line)
{
	int		size;	
	char	t;
	int		bytes_read;
	int		max_size_line_aux;

	size = 0;
	t = '\0';
	bytes_read = read(fd, &t, 1);
	while (bytes_read != 0)
	{
		if (t == '\n')
		{
			if (*max_size_line < max_size_line_aux)
				*max_size_line = max_size_line_aux;
			max_size_line_aux = 0;
			size++;
		}
		max_size_line_aux++;
		bytes_read = read(fd, &t, 1);
	}
	return (size);
}

void	ft_check_dict_error(int fd)
{
	if (fd == -1)
	{
		write (1, "Dict Error\n", 12);
		exit (0);
	}
}
