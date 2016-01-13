/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/00/13 17:32:50 by marvin            #+#    #+#             */
/*   Updated: 2016/00/13 17:32:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int			build_links(t_map *map)
{
	t_street	*street;
	t_junction	*node;
	int			links;
	int			index;

	index = map->streets;
	while (index--)
	{
		street = &map->a_streets[index];
		node = &map->a_junctions[street->junction_a];
		links = ++(node->links);
		if ((node->a_links = realloc(node->a_links, sizeof(int) * links)) == NULL)
			return (0);
		node->a_links[links - 1] = *street;
		node = &map->a_junctions[street->junction_b];
		links = ++(node->links);
		if ((node->a_links = realloc(node->a_links, sizeof(int) * links)) == NULL)
			return (0);
		node->a_links[links - 1] = *street;
	}
	return (1);
}

int			load_cars(t_map *map, t_car **in)
{
	t_car	*cars;
	int		index;

	if ((cars = malloc(sizeof(t_car) * map->cars)) == NULL)
		return (0);
	*in = cars;
	index = map->cars;
	while (index--)
	{
		cars->timequota = map->seconds;
		cars->position = map->start;
		if ((cars->route = malloc(sizeof(int))) == NULL)
			return (0);
		cars++;
	}
	return (1);
}

static int	drive_to_best_node(t_map *map, t_car *car)
{
	t_junction	current;

	current = map->a_junctions[car->position];
	return (1);
}

int			solve_route(t_map *map, t_car *cars)
{
	int		index;

	index = map->cars;
	while (index--)
		if (!drive_to_best_node(map, cars++))
			return (0);
	return (1);
}
