/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_vec3f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 17:52:05 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/14 17:53:31 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <ftstdlib.h>

t_vec3f					*alloc_vec3f(float x, float y, float z)
{
	t_vec3f			*v;

	if ((v = (t_vec3f*)ft_memalloc(sizeof(t_vec3f))))
	{
		v->x = x;
		v->y = y;
		v->z = z;
	}
	return (v);
}
