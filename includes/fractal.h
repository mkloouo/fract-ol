/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:48:42 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/25 21:27:43 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <window.h>

# define FRACTALS 2
# define COLOR_MODES 1

# define MANDELBROT_TYPE 0
# define MANDELBROT_NAME "Mandelbrot"

# define JULIA_TYPE 1
# define JULIA_NAME "Julia"

# define DEFAULT_ZOOM 1
# define DEFAULT_MX 0
# define DEFAULT_MY 0
# define DEFAULT_ITERATIONS 100
# define DEFAULT_BAIL 4

# define FRACTAL_THREADS_X 4
# define FRACTAL_THREADS_Y 2

typedef struct			s_fractal
{
	t_window			*window;
	int					type;
	float				zoom;
	float				mx;
	float				my;
	int					iter;
	int					bail;
	int					(*fractals[FRACTALS])(struct s_fractal *f,
												int i, int j);
	int					(*color_modes[COLOR_MODES])(int iterations);
}						t_fractal;

typedef struct			s_fractal_thread
{
	int					from_y;
	int					to_y;
	int					from_x;
	int					to_x;
	t_fractal			*fractal;
}						t_fractal_thread;

int						init_fractal(t_fractal **f, int ac, char **av);
void					delete_fractal(t_fractal **fp);

void					update_fractal_window(t_fractal *f);

int						mandelbrot(t_fractal *f, int i, int j);

int						blend_color_mode(int iterations);

int						mouse_move_hook(int x, int y, t_fractal *f);
int						mouse_press_hook(int btn, int x, int y, t_fractal *f);
int						mouse_release_hook(int btn, int x, int y, t_fractal *f);
int						key_press_hook(int btn, t_fractal *f);

void					print_usage(char *name);
int						get_fractal(char *name);

#endif
