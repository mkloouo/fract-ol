/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 20:12:20 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/26 21:11:48 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <mouse.h>
# include <keyboard.h>
# include <image.h>

# define WIN_DEF_WIDTH 950
# define WIN_DEF_HEIGHT 950

# define KEY_RELEASE 3
# define KEY_RELEASE_MASK (1L << 1)
# define KEY_PRESS 2
# define KEY_PRESS_MASK (1L << 0)

# define MOUSE_BUTTON_PRESS 4
# define MOUSE_BUTTON_PRESS_MASK (1L << 2)
# define MOUSE_BUTTON_RELEASE 5
# define MOUSE_BUTTON_RELEASE_MASK (1L << 3)
# define MOTION_NOTIFY 6
# define MOUSE_MOVE MOTION_NOTIFY
# define MOTION_NOTIFY_MASK (1L << 6)

# define EXPOSE 12
# define EXPOSE_MASK (1L << 15)

typedef struct			s_window
{
	void				*server;
	void				*window;
	t_mouse				*mouse;
	t_keyboard			*keyboard;
	t_image				*image;
	int					width;
	int					height;
}						t_window;

t_window				*get_window(char *title, int width, int height);
void					delete_window(t_window **wp);

void					update_window(t_window *w);
void					put_string_to_window(t_window *w, char *str,
											t_vec2i *pos, unsigned int color);

void					add_hook(t_window *w, int type, int (*func)(),
						void *func_argument);

#endif
