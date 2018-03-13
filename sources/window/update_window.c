/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 19:35:57 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/13 21:35:42 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>
#include <mlx.h>

void					update_window(t_window *w)
{
	t_image				*image;

	image = get_image(w->image->width, w->image->height);
	if (w->image)
	{
		mlx_put_image_to_window(w->server, w->window,
								w->image->ip, 0, 0);
		delete_image(&w->image);
	}
	w->image = image;
}
