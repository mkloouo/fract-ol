/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 08:02:36 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/27 08:03:13 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>
#include <mlx.h>

void                    clear_window(t_window *w)
{
	mlx_clear_window(w->server, w->window);
}
