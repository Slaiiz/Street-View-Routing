/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/00/13 13:04:58 by marvin            #+#    #+#             */
/*   Updated: 2016/00/13 13:04:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static int	expect(const char **s, const char *format, ...)
{
	va_list	argp;
	char	c;
	int		i;

	va_start(argp, format);
	while ((c = *format++) != '\0')
	{
		if (c == '$')
		{
			if ((c = *format) == '\0')
				return (0);
			i = 0;
			switch (c)
			{
				case 'i':
					while (isdigit((*s)[i]))
						i++;
					if (i < 1)
						return (0);
					*va_arg(argp, int*) = atoi(*s);
					break ;
				case 'f':
					while (isdigit((*s)[i]) || (*s)[i] == '.')
						i++;
					if (i < 1)
						return (0);
					*va_arg(argp, double*) = atof(*s);
					break ;
			}
			++format;
			*s += i;
		}
		else
		{
			if (c != **s)
				return (0);
			(*s)++;
		}
	}
	return (1);
}

int			parse_file(t_map *in, const char *src)
{
	t_junction	*junction;
	t_street	*street;
	int			index;

	if (!expect(&src, "$i $i $i $i $i\n",
		&in->junctions,
		&in->streets,
		&in->seconds,
		&in->cars,
		&in->start))
		return (0);
	index = in->junctions;
	if ((in->a_junctions = malloc(sizeof(t_junction) * index)) == NULL)
		return (0);
	while (index--)
	{
		junction = &in->a_junctions[index];
		if (!expect(&src, "$f $f\n",
			&junction->latitude,
			&junction->longitude))
			return (0);
	}
	index = in->streets;
	if ((in->a_streets = malloc(sizeof(t_street) * index)) == NULL)
		return (0);
	while (index--)
	{
		street = &in->a_streets[index];
		if (!expect(&src, "$i $i $i $i $i\n",
			&street->junction_a,
			&street->junction_b,
			&street->directions,
			&street->time_cost,
			&street->distance))
			return (0);
	}
	return (1);
}
