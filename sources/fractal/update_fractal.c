/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 19:27:39 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/30 01:22:07 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>
#include <ftstdlib.h>
#include <stdlib.h>
#include <ftio.h>
#include <stdio.h>

static void				*update_image(void *v)
{
	int					i;
	int					j;
	t_vec3i				pixel;
	t_fractal_thread	*ft;

	ft = (t_fractal_thread*)v;
	pixel = get_vec3i(0, 0, 0);
	i = ft->fy;
	while (i < ft->ty)
	{
		j = ft->fx;
		while (j < ft->tx)
		{
			set_vec3i(&pixel, i, j,
				(ft->f->f[ft->f->type](ft->f,
			   (ft->f->sf) + (ft->f->sy * i),
			   (ft->f->sf) + (ft->f->sx * j))));
			pixel.z = ft->f->c[ft->f->mode](ft->f, pixel.z);
			put_pixel(ft->f->w->image, &pixel);
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

	ft.fy = 0;
	ft.ty = f->w->height;
	sx = f->w->width / FRACTAL_THREADS;
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
	f->sx = (f->st - f->sf) / (long double)f->w->width;
	f->sy = (f->st - f->sf) / (long double)f->w->height;
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
	update_window(f->w);
}
