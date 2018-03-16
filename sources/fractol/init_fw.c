/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 18:13:46 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/16 03:33:06 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_fwin					init_fw(int ac, char **av)
{
	t_fwin				fw;

	fw.window = get_window(av[0], WIN_DEF_WIDTH, WIN_DEF_HEIGHT);
	fw.zoom = DEFAULT_ZOOM;
	fw.mx = 0;
	fw.my = 0;
	fw.iter = DEFAULT_ITERATIONS;
	fw.bail = DEFAULT_BAIL;
	add_hook(fw.window, MOUSE_MOVE, &mouse_move_hook, &fw);
	add_hook(fw.window, KEY_PRESS, &key_press_hook, &fw);
}
