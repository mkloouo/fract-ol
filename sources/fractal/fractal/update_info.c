/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 19:44:15 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/30 21:48:12 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

void					update_info(t_fractal *f)
{
	t_vec2i				pos;

	clear_window(f->info);
	pos = get_vec2i(10, 10);
	put_string_to_window(f->info, "Iterations: ", pos, COLOR_WHITE);
	set_vec2i(&pos, 10, 30);	
	put_string_to_window(f->info, "Iterations: ", pos, COLOR_RED);
	set_vec2i(&pos, 10, 50);	
	put_string_to_window(f->info, "Iterations: ", pos, COLOR_BLUE);
	set_vec2i(&pos, 10, 70);	
	put_string_to_window(f->info, "Iterations: ", pos, COLOR_GREEN);
	set_vec2i(&pos, 10, 90);	
	put_string_to_window(f->info, "Iterations: ", pos, COLOR_GREEN | COLOR_BLUE);	
}
