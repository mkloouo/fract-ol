/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_keyboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 04:14:40 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/13 19:55:18 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <keyboard.h>
#include <ftstdlib.h>

void					delete_keyboard(t_keyboard **kp)
{
	if (kp && *kp)
		ft_memdel((void**)kp);
}
