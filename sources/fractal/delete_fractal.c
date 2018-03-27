/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:16:43 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/27 06:24:12 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftstdlib.h>
#include <fractal.h>

void					delete_fractal(t_fractal **fp)
{
	if (fp && *fp)
	{
		delete_window(&(*fp)->window);
		del_vec2f(&(*fp)->scale_x);
		del_vec2f(&(*fp)->scale_y);		
		ft_memdel((void**)fp);
	}
}
