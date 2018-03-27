/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 19:13:40 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/27 04:06:13 by modnosum         ###   ########.fr       */
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
		w->mouse = get_mouse();
		w->keyboard = get_keyboard();
		w->width = width;
		w->height = height;
		w->image = get_image(width, height);
	}
	return (w);
}
