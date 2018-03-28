/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_key_press.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 07:44:03 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/28 17:00:04 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

int						info_key_press(int btn, t_fractal *f)
{
	if (QUIT_BUTTON(btn))
	{
		delete_window(&(f->i));
		f->i = NULL;
	}
	return (1);
}
