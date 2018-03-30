/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:16:43 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/28 17:00:09 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftstdlib.h>
#include <fractal.h>

void					delete_fractal(t_fractal **fp)
{
	if (fp && *fp)
	{
		delete_window(&(*fp)->w);
		delete_window(&(*fp)->i);		
		ft_memdel((void**)fp);
	}
}
