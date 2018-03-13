/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 19:13:40 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/13 20:13:43 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>
#include <mlx.h>
#include <ftstdlib.h>
#include <server.h>

t_window				*get_window(char *title, int width, int height)
{
	t_window				*w;

	if ((w = (t_window*)ft_memalloc(sizeof(t_window))))
	{
		w->server = get_server();
		w->window = mlx_new_window(w->server, width, height, title);
		w->image = get_image(width, height);
	}
	return (w);
}
