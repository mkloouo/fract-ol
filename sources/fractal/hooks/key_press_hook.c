/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:55:19 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/30 22:05:27 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>
#include <stdlib.h>
#include <ftio.h>

int						key_press_hook(int btn, t_fractal *f)
{
	if (QUIT_BUTTON(btn))
	{
		delete_fractal(&f);
		exit(0);
	}
	else if (RESET_BUTTON(btn))
		init_default_values(f);
	else if (COLOR_BUTTON(btn))
		f->mode = (f->mode + 1) % COLOR_MODES;
	else if (FRACTAL_BUTTON(btn))
		f->type = (f->type + 1) % FRACTALS;
	else if (ITERATION_BUTTON(btn))
		f->max_iter += ITERATION_UP(btn) ? (1) : (-1);
	else
	{
		ft_putstr("key: ");
		ft_putnbr(btn);
		ft_putstr("\n");
		return (-1);
	}
	update_fractal(f);
	return (0);
}
