/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:01:29 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/31 14:02:16 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftstdlib.h>
#include <fractal.h>
#include <ftio.h>

static void				init_fractal_functions(t_fractal *f)
{
	f->f[0] = &mandelbrot;
	f->f[1] = &julia;
	f->f[2] = &newton;
	f->f[3] = &burning_ship;
}

static void				init_color_functions(t_fractal *f)
{
	f->mode = 0;
	f->c[0] = &bw_color_mode;
	f->c[1] = &red_color_mode;
	f->c[2] = &green_color_mode;
	f->c[3] = &blue_color_mode;
	f->c[4] = &noise_color_mode;
	f->c[5] = &twenty_seven_color_mode;
}

static void				init_hooks(t_fractal *f)
{
	add_hook(f->window, MOUSE_MOVE, &mouse_move_hook, f);
	add_hook(f->window, KEY_PRESS, &key_press_hook, f);
	add_hook(f->window, MOUSE_BUTTON_PRESS, &mouse_press_hook, f);
	add_hook(f->window, MOUSE_BUTTON_RELEASE, &mouse_release_hook, f);
}

int						init_fractal(int ac, char **av)
{
	t_fractal			*f;

	if (ac == 2 && (f = (t_fractal*)ft_memalloc(sizeof(t_fractal))))
	{
		if ((f->type = get_fractal(av[1])) == -1)
			return (0);
		f->window = get_window(av[0], WIN_DEF_WIDTH,
									WIN_DEF_HEIGHT);
		init_default_values(f);
		init_hooks(f);
		init_fractal_functions(f);
		init_color_functions(f);
		update_fractal(f);
		return (1);
	}
	return (0);
}
