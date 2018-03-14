/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:11:33 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/14 17:40:45 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <image.h>

void					put_pixel(t_image *img, t_vec3i v)
{
	int					opp;
	int					temp;
	char				*p;

	if (IN_IMAGE(v.x, v.y, img->width, img->height))
	{
		opp = img->bp / 8;
		temp = opp;
		p = (img->id + (int)v.y * img->sl);
		while (opp--)
		{
			if (img->en == img->le)
				*(p + v.x * temp + opp) = ((unsigned char *)(&v.z))[
					((img->en) ? (4 - temp + opp) : (opp))];
			else
				*(p + v.x * temp + opp) = ((unsigned char *)(&v.z))[
					((img->en) ? (temp - 1 - opp) : (3 - opp))];
		}
	}
}
