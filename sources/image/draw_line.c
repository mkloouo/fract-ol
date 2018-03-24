/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:11:29 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/24 17:43:29 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <image.h>
#include <ftmath.h>

/*
** Reminder
** dx == data[0] --> will be swapped with dy if dy > dx
** dy == data[1]
** sx == data[2] --> will be swapped with sy if dy > dx
** sy == data[3]
** d == data[4]
** d1 == data[5]
** d2 == data[6]
** x == data[7] --> will be swapped with y if dy > dx
** y == data[8]
** i == data[9]
** swap == data[10] --> 1 if swapped, 0 otherwise
*/

static void				init_data(int *data, t_vec3i *v1, t_vec3i *v2)
{
	int					swap;

	data[0] = ft_fabs(v2->x - v1->x);
	data[1] = ft_fabs(v2->y - v1->y);
	data[2] = (v2->x >= v1->x) ? (1) : (-1);
	data[3] = (v2->y >= v1->y) ? (1) : (-1);
	swap = !(data[1] <= data[0]);
	if (swap)
	{
		ft_swap((data), (data + 1));
		ft_swap((data + 2), (data + 3));
	}
	data[5] = data[1] << 1;
	data[4] = data[5] - data[0];
	data[6] = (data[1] - data[0]) << 1;
	data[7] = ((swap) ? (v1->y) : (v1->x)) + data[2];
	data[8] = ((swap) ? (v1->x) : (v1->y));
	data[9] = 1;
	data[10] = swap;
}

void					draw_line(t_image *img, t_vec3i *p1, t_vec3i *p2)
{
	static int			data[11];
	t_vec3i				v;

	if (IN_IMAGE(p1->x, p1->y, img->width, img->height) ||
		IN_IMAGE(p2->x, p2->y, img->width, img->height))
	{
		init_data(data, p1, p2);
		v = get_vec3i(p1->x, p1->y, p1->z);
		put_pixel(img, &v);
		while (data[9] <= data[0])
		{
			if (data[4] > 0)
			{
				data[4] += data[6];
				data[8] += data[3];
			}
			else
				data[4] += data[5];
			set_vec3i(&v, (data[10] ? data[8] : data[7]),
						(data[10] ? data[7] : data[8]),
						map_color(p1->z, p2->z, ((float)data[9] / data[0])));
			put_pixel(img, &v);
			data[9]++;
			data[7] += data[2];
		}
	}
}
