/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_string_to_window.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 19:58:16 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/27 07:59:33 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>
#include <mlx.h>

void					put_string_to_window(t_window *w, char *str,
											t_vec2i pos, unsigned int color)
{
	mlx_string_put(w->server, w->window, pos.x, pos.y, color, str);
}
