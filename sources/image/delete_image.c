/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 19:44:42 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/13 21:35:15 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <image.h>
#include <mlx.h>
#include <ftstdlib.h>

void					delete_image(t_image **ip)
{
	if (ip && *ip)
	{
		if ((*ip)->server != NULL)
			mlx_destroy_image((*ip)->server, (*ip)->ip);
		ft_memdel((void**)ip);
	}
}
