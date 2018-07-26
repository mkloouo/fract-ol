/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_keyboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 19:55:34 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/13 20:05:57 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <keyboard.h>
#include <ftstdlib.h>

t_keyboard				*get_keyboard(void)
{
	t_keyboard			*kb;

	if ((kb = (t_keyboard*)ft_memalloc(sizeof(t_keyboard))))
	{
		kb->shift_pressed = 0;
		kb->ck = 0;
	}
	return (kb);
}
