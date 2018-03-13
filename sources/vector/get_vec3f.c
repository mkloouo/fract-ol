/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vec3f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 03:24:10 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/13 20:10:09 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <ftstdlib.h>

t_vec3f					*get_vec3f(float x, float y, float z)
{
	t_vec3f				*p;

	if ((p = (t_vec3f*)ft_memalloc(sizeof(t_vec3f))))
	{
		p->x = x;
		p->y = y;
		p->z = z;
	}
	return (p);
}
