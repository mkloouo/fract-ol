/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 19:56:11 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/13 20:06:45 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mouse.h>
#include <ftstdlib.h>

void					delete_mouse(t_mouse **mp)
{
	if (mp && *mp)
	{
		del_vec2i(&(*mp)->pv);
		del_vec2i(&(*mp)->rv);
		del_vec2i(&(*mp)->cv);
		ft_memdel((void**)mp);
	}
}
