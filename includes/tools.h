/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/00/13 13:05:34 by marvin            #+#    #+#             */
/*   Updated: 2016/00/13 13:05:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include <ctype.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_car
{
	int			timequota;
	int			position;
	int			*route;
}				t_car;

typedef	struct	s_street
{
	int			junction_a;
	int			junction_b;
	int			directions;
	int			time_cost;
	int			distance;
	int			visited;
}				t_street;

typedef struct	s_junction
{
	int			links;
	double		latitude;
	double		longitude;
	t_street	*a_links;
}				t_junction;

typedef struct	s_map
{
	int			junctions;
	int			streets;
	int			seconds;
	int			cars;
	int			start;
	t_junction	*a_junctions;
	t_street	*a_streets;
}				t_map;

int				parse_file(t_map *in, const char *src);
int				build_links(t_map *map);
int				load_cars(t_map *map, t_car **in);
int				solve_route(t_map *map, t_car *cars);

#endif
