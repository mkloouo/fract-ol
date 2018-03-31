/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 19:27:39 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/31 19:30:03 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>
#include <ftstdlib.h>
#include <stdlib.h>
#include <ftstring.h>

static void				*update_image(void *v)
{
	int					i;
	int					j;
	t_vec3i				pixel;
	t_fractal_thread	*ft;

	ft = (t_fractal_thread*)v;
	pixel = get_vec3i(0, 0, 0);
	i = 0;
	while (i < FRACTAL_HEIGHT)
	{
		j = ft->fx;
		while (j < ft->tx)
		{
			set_vec3i(&pixel, j, i,
				(ft->f->f[ft->f->type](ft->f,
				(ft->f->syf) + (ft->f->sy * (i - ft->f->my)),
				(ft->f->sxf) + (ft->f->sx * (j - ft->f->mx)))));
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

	sx = FRACTAL_WIDTH / FRACTAL_THREADS;
	ft.fx = i * sx;
	ft.tx = ft.fx + sx;
	ft.f = f;
	return (ft);
}

static void				put_info(t_fractal *f)
{
	char				t[100];
	t_vec2i				pos;

	ft_memset(t, 0, 100);
	ft_strcpy(t, "Current fractal: ");
	ft_strcpy(&t[17], get_fractal_by_number(f->type));
	pos = get_vec2i(INFO_OFFSET, INFO_OFFSET);
	put_string_to_window(f->window, t, &pos, COLOR_WHITE);
}

void					update_fractal(t_fractal *f)
{
	int					i;
	t_fractal_thread	ft[FRACTAL_THREADS];

	i = 0;
	f->sx = (f->sxt - f->sxf) / (long double)FRACTAL_WIDTH;
	f->sy = (f->syt - f->syf) / (long double)FRACTAL_HEIGHT;
	while (i < FRACTAL_THREADS)
	{
		ft[i] = init_fractal_thread(i, f);
		pthread_create(&(ft[i].thread), NULL, &update_image, &ft[i]);
		i++;
	}
	i = 0;
	while (i < FRACTAL_THREADS)
		pthread_join(ft[i++].thread, NULL);
	update_window(f->window);
	put_info(f);
}
