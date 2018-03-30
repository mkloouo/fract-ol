/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 19:27:39 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/30 22:07:57 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>
#include <ftstdlib.h>
#include <stdlib.h>
#include <ftio.h>

static void				*update_image(void *v)
{
	int					i;
	int					j;
	t_vec3i				pixel;
	t_fractal_thread	*ft;

	ft = (t_fractal_thread*)v;
	pixel = get_vec3i(0, 0, 0);
	i = 0;
	while (i < ft->f->window->height)
	{
		j = ft->fx;
		while (j < ft->tx)
		{
			set_vec3i(&pixel, i, j,
				(ft->f->f[ft->f->type](ft->f,
			   (ft->f->syf) + (ft->f->sy * i),
			   (ft->f->sxf) + (ft->f->sx * j))));
			pixel.z = ft->f->c[ft->f->mode](ft->f, pixel.z);
			put_pixel(ft->f->window->image, &pixel);
			j++;
		}
		i++;
	}
	return (NULL);
}

static t_fractal_thread	init_fractal_thread(int i, t_fractal *f)
{
	t_fractal_thread	ft;
	int					sx;

	sx = f->window->width / FRACTAL_THREADS;
	ft.fx = i * sx;
	ft.tx = ft.fx + sx;
	ft.f = f;
	return (ft);
}

void					update_fractal(t_fractal *f)
{
	int					i;
	t_fractal_thread	ft[FRACTAL_THREADS];

	i = 0;
	f->sx = (f->sxt - f->sxf) / (long double)f->window->width;
	f->sy = (f->syt - f->syf) / (long double)f->window->height;
	while (i < FRACTAL_THREADS)
	{
		ft[i] = init_fractal_thread(i, f);
		pthread_create(&(ft[i].thread), NULL, &update_image, &ft[i]);
		i++;
	}
	i = 0;
	while (i < FRACTAL_THREADS)
		pthread_join(ft[i++].thread, NULL);
	update_info(f);
	update_window(f->window);
}
