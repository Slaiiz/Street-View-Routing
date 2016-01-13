/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/00/13 12:50:25 by marvin            #+#    #+#             */
/*   Updated: 2016/00/13 12:50:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static int	read_data(const char *name, char **in)
{
	int		len;
	int		fd;

	if ((fd = open(name, O_RDONLY)) == -1)
		return (0);
	if ((len = lseek(fd, 0, SEEK_END)) == -1)
		return (0);
	if ((*in = malloc(sizeof(char) * len)) == NULL)
		return (0);
	lseek(fd, 0, SEEK_SET);
	if (read(fd, *in, len) == -1)
		return (0);
	close(fd);
	return (1);
}

static int	process_data(const char *in, char **out)
{
	t_car	*cars;
	t_map	map;

	printf("Parsing file ... ");
	if (!parse_file(&map, in))
		return (0);
	printf("Ok!\nBuilding links ... ");
	if (!build_links(&map))
		return (0);
	printf("Ok!\nLoading cars ... ");
	if (!load_cars(&map, &cars))
		return (0);
	printf("Ok!\nSolving best route ... ");
	if (!solve_route(&map, cars))
		return (0);
	printf("Ok!\nStored end results.\n");
	*out = *out;
	return (1);
}

int			main(int argc, char **argv)
{
	char	*data;
	char	*out;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	if (!read_data(argv[1], &data))
	{
		printf("Error\n");
		return (2);
	}
	if (!process_data(data, &out))
	{
		printf("Error\n");
		return (4);
	}
/*	printf("%s\n", out); */
	return (0);
}
