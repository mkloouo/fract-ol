/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:55:19 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/30 12:56:02 by modnosum         ###   ########.fr       */
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
	else if (btn == C_KC)
		f->mode = (f->mode + 1) % COLOR_MODES;
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
