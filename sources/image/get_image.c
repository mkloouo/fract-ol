/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:11:31 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/13 21:35:58 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <image.h>
#include <mlx.h>
#include <server.h>
#include <ftstdlib.h>

t_image					*get_image(int width, int height)
{
	t_image				*i;

	if ((i = (t_image*)ft_memalloc(sizeof(t_image))))
	{
		i->server = get_server();
		i->ip = mlx_new_image(i->server, width, height);
		i->id = mlx_get_data_addr(i->ip, &i->bp,
											&i->sl, &i->en);
		i->le = 0x11223344;
		i->le = (((unsigned char*)&i->le)[0] == 0x11) ? (1) : (0);
		i->width = width;
		i->height = height;
	}
	return (i);
}
