/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:37:28 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/13 22:18:30 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>
#include <server.h>
#include <ftio.h>
#include <stdio.h>
#include <ftmath.h>

int						main(void)
{
	t_window			*w;
	int					iter;

	w = get_window("Mandelbrot", WIN_DEF_WIDTH, WIN_DEF_HEIGHT);
	iter = 100;
	for (int x = 0; x < WIN_DEF_WIDTH; x++) {
		for (int y = 0; y < WIN_DEF_HEIGHT; y++) {
			
			t_range fromx = {.min = 0, .max = WIN_DEF_WIDTH};
			t_range fromy = {.min = 0, .max = WIN_DEF_HEIGHT};
			t_range to = {.min = -2, .max = 2};
			
			double original_a = ft_map(x, &fromx, &to);
			double original_b = ft_map(y, &fromy, &to);
			
			double a = original_a;
			double b = original_b;
			
			int n = 0;
			while (n < iter)
			{
				double aa = (a * a  - b * b);
				double bb = 2 * a * b;
				a = aa + original_a;
				b = bb + original_b;
				if (a + b > (iter / 3))
					break ;
				n++;
			}
			t_range from = {.min = 0, .max = 100};
			t_range tb = {.min = 0, .max = 1};
			int bright = ft_map(n, &from, &tb);
			tb.min = 0;
			tb.max = 255;
			from.min = 0;
			from.max = 1;
			bright = ft_map(n, &from, &tb);
			if (n == iter)
				bright = 0;
			t_vec3i p = {.x = x, .y = y, .z = RGB_COLOR(0, 0, ((bright * 3) % 255), ((bright / 16) % 255))};
			put_pixel(w->image, &p);
		}
	}
	update_window(w);
	start_server();
    return (0);
}
