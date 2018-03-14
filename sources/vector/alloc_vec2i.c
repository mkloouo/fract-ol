/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_vec2i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 17:49:54 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/14 17:53:27 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <ftstdlib.h>

t_vec2i					*alloc_vec2i(int x, int y)
{
	t_vec2i			*v;

	if ((v = (t_vec2i*)ft_memalloc(sizeof(t_vec2i))))
	{
		v->x = x;
		v->y = y;
	}
	return (v);
}
