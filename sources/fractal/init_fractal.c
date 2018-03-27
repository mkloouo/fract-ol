/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:01:29 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/27 08:05:37 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftstdlib.h>
#include <fractal.h>

static void				init_fractal_functions(t_fractal *f)
{
	f->fractals[0] = &mandelbrot;
	f->fractals[1] = &julia;
	f->fractals[2] = &newton;
	f->fractals[3] = &burning_ship;
}

static void				init_color_functions(t_fractal *f)
{
	f->color_mode = 0;
	f->color_modes[0] = &bw_color_mode;
	f->color_modes[1] = &red_color_mode;
	f->color_modes[2] = &green_color_mode;
	f->color_modes[3] = &blue_color_mode;
	f->color_modes[4] = &noise_color_mode;
	f->color_modes[5] = &twenty_seven_color_mode;
}

static void				init_hooks(t_fractal *f)
{
	add_hook(f->window, MOUSE_MOVE, &mouse_move_hook, f);
	add_hook(f->window, KEY_PRESS, &key_press_hook, f);
	add_hook(f->window, MOUSE_BUTTON_PRESS, &mouse_press_hook, f);
	add_hook(f->window, MOUSE_BUTTON_RELEASE, &mouse_release_hook, f);
}

static void				init_info(t_fractal *f)
{
	add_hook(f->info, KEY_PRESS, &info_key_press, f);
}

int						init_fractal(t_fractal **f, int ac, char **av)
{
	if (ac == 2 && f && (*f = (t_fractal*)ft_memalloc(sizeof(t_fractal))))
	{
		if (((*f)->fractal_type = get_fractal(av[1])) == -1)
		{
			ft_memdel((void**)f);
			return (0);
		}
		(*f)->window = get_window(av[0], WIN_DEF_WIDTH, WIN_DEF_HEIGHT);
		(*f)->info = get_window("Information", 300, 150);
		init_default_values(*f);
		init_hooks(*f);
		init_info(*f);
		init_fractal_functions(*f);
		init_color_functions(*f);
		update_fractal(*f);
		return (1);
	}
	return (0);
}
