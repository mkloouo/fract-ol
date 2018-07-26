/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_vec3i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 17:51:35 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/14 17:53:34 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <ftstdlib.h>

t_vec3i					*alloc_vec3i(int x, int y, int z)
{
	t_vec3i			*v;

	if ((v = (t_vec3i*)ft_memalloc(sizeof(t_vec3i))))
	{
		v->x = x;
		v->y = y;
		v->z = z;
	}
	return (v);
}
