/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:01:29 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/24 17:53:09 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftstdlib.h>
#include <fractal.h>

int							init_fractal(t_fractal **f, int ac, char **av)
{
	if (ac == 2 && f && (*f = (t_fractal*)ft_memalloc(sizeof(t_fractal))))
	{
		if (((*f)->type = get_fractal(av[1])) == -1)
		{
			ft_memdel((void**)f);
			return (0);
		}
		(*f)->window = get_window(av[0], WIN_DEF_WIDTH, WIN_DEF_HEIGHT);
		(*f)->zoom = DEFAULT_ZOOM;
		(*f)->mx = 0;
		(*f)->my = 0;
		(*f)->iter = DEFAULT_ITERATIONS;
		(*f)->bail = DEFAULT_BAIL;
		add_hook((*f)->window, MOUSE_MOVE, &mouse_move_hook, *f);
		add_hook((*f)->window, KEY_PRESS, &key_press_hook, *f);
		init_fractals(*f);
		update_fractal_window(*f);
		return (1);
	}
	return (0);
}
