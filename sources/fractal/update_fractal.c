/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 19:27:39 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/27 08:18:31 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>
#include <ftstdlib.h>
#include <stdlib.h>
#include <stdio.h>

static void				*update_image_part(void *arg)
{
	int					i;
	int					j;
	t_vec3i				pixel;
	t_fractal_thread	*ft;

	ft = (t_fractal_thread*)arg;
	i = ft->from_y;
	// TODO: map from_y and to_y and from_x and to_x to scale_y and scale_x
	// to get faster calculus
	// need to get steps = (top - bottom) / (prev_top - prev_bottom)
	while (i < ft->to_y)
	{
		j = ft->from_x;
		while (j < ft->to_x)
		{
			pixel = get_vec3i(j, i,
			ft->fractal->fractals[ft->fractal->fractal_type](ft->fractal,
				i - ft->fractal->my, j - ft->fractal->mx));
			pixel.z = ft->fractal->color_modes
				[ft->fractal->color_mode](ft->fractal, pixel.z);
			put_pixel(ft->fractal->window->image, &pixel);
			j++;
		}
		i++;
	}
	return (NULL);
}

static t_fractal_thread	set_fractal_thread_props(int i, int j, int width,
int height)
{
	t_fractal_thread	ft;
	int					step_y;
	int					step_x;

	step_y = height / FRACTAL_THREADS_Y;
	ft.from_y = i * step_y;
	ft.to_y = ft.from_y + step_y;
	step_x = width / FRACTAL_THREADS_X;
	ft.from_x = j * step_x;
	ft.to_x = ft.from_x + step_x;
	return (ft);
}

static void				update_info(t_fractal *f)
{
	char				str[100];

	clear_window(f->info);
	ft_memset(str, 0, 100);
	sprintf(str, "MX: %g", f->mx);
	put_string_to_window(f->info, str, get_vec2i(10, 10), 0xffffff);
	ft_memset(str, 0, 100);
	sprintf(str, "MY: %g", f->my);
	put_string_to_window(f->info, str, get_vec2i(10, 30), 0xffffff);
	ft_memset(str, 0, 100);
	sprintf(str, "ITERATIONS: %d", f->iter);
	put_string_to_window(f->info, str, get_vec2i(10, 50), 0xffffff);
	ft_memset(str, 0, 100);
	sprintf(str, "FRACTAL: %s", get_fractal_by_number(f->fractal_type));
	put_string_to_window(f->info, str, get_vec2i(10, 70), 0xffffff);
}

void					update_fractal(t_fractal *f)
{
	int					i;
	int					j;
	t_fractal_thread	ft[FRACTAL_THREADS_X * FRACTAL_THREADS_Y];

	i = 0;
	while (!(j = 0) && i < FRACTAL_THREADS_Y)
	{
		while (j < FRACTAL_THREADS_X)
		{
			ft[i * FRACTAL_THREADS_X + j] = set_fractal_thread_props(i,
									j, f->window->width, f->window->height);
			ft[i * FRACTAL_THREADS_X + j].fractal = f;
			pthread_create(&(ft[i * FRACTAL_THREADS_X + j].thread), NULL,
					&update_image_part, &ft[i * FRACTAL_THREADS_X + j]);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < FRACTAL_THREADS_X * FRACTAL_THREADS_Y)
		pthread_join(ft[i++].thread, NULL);
	update_window(f->window);
	update_info(f);
}
