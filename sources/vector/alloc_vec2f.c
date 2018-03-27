/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_vec2f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 06:16:22 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/27 06:16:45 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <ftstdlib.h>

t_vec2f					*alloc_vec2f(float x, float y)
{
	t_vec2f			*v;

	if ((v = (t_vec2f*)ft_memalloc(sizeof(t_vec2f))))
	{
		v->x = x;
		v->y = y;
	}
	return (v);
}
