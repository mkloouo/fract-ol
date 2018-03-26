/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 19:56:31 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/26 19:53:24 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mouse.h>
#include <ftstdlib.h>

t_mouse					*get_mouse(void)
{
	t_mouse				*ms;

	if ((ms = (t_mouse*)ft_memalloc(sizeof(t_mouse))))
	{
		ms->press = alloc_vec2i(0, 0);
		ms->release = alloc_vec2i(0, 0);
		ms->previous = alloc_vec2i(0, 0);
		ms->current = alloc_vec2i(0, 0);
		ms->btn = 0;
		ms->pressed = 0;
	}
	return (ms);
}
