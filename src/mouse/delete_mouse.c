/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 19:56:11 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/26 19:52:36 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mouse.h>
#include <ftstdlib.h>

void					delete_mouse(t_mouse **mp)
{
	if (mp && *mp)
	{
		del_vec2i(&(*mp)->press);
		del_vec2i(&(*mp)->release);
		del_vec2i(&(*mp)->previous);
		del_vec2i(&(*mp)->current);
		ft_memdel((void**)mp);
	}
}
