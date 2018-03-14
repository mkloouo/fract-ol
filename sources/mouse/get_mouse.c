/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 19:56:31 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/14 17:52:47 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mouse.h>
#include <ftstdlib.h>

t_mouse					*get_mouse(void)
{
	t_mouse				*ms;

	if ((ms = (t_mouse*)ft_memalloc(sizeof(t_mouse))))
	{
		ms->pv = alloc_vec2i(0, 0);
		ms->rv = alloc_vec2i(0, 0);
		ms->cv = alloc_vec2i(0, 0);
		ms->btn = 0;
		ms->pressed = 0;
	}
	return (ms);
}
