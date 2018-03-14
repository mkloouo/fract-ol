/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:37:28 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/14 18:13:32 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <server.h>

int						main(int ac, char **av)
{
	t_fwin				fw;

	if (ac == 2 && (fw.type = get_fractal_type(av[1])) != -1)
	{
		fw = init_fw(ac, av);
		fw.window = get_window(av[0], WIN_DEF_WIDTH, WIN_DEF_HEIGHT);
		fw.zoom = DEFAULT_ZOOM;
		fw.mx = 0;
		fw.my = 0;
		fw.iter = DEFAULT_ITERATIONS;
		fw.bail = DEFAULT_BAIL;
		add_hook(fw.window, MOUSE_MOVE, &mouse_move_hook, &fw);
		add_hook(fw.window, KEY_PRESS, &key_press_hook, &fw);
		start_server();
	}
	print_fractol_usage(av[0]);
    return (1);
}
