/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_key_press.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 07:44:03 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/27 07:58:27 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

int						info_key_press(int btn, t_fractal *f)
{
	if (QUIT_BUTTON(btn))
		delete_window(&(f->info));
	return (1);
}
