/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:48:42 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/26 21:06:36 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <window.h>
# include <pthread.h>

# define FRACTALS 2
# define COLOR_MODES 5

# define MANDELBROT_TYPE 0
# define MANDELBROT_NAME "Mandelbrot"

# define JULIA_TYPE 1
# define JULIA_NAME "Julia"

# define DEFAULT_ZOOM 2
# define DEFAULT_MX 0
# define DEFAULT_MY 0
# define DEFAULT_ITERATIONS 100
# define DEFAULT_BAIL 4

# define FRACTAL_THREADS_X 4
# define FRACTAL_THREADS_Y 2

typedef struct			s_fractal
{
	t_window			*window;
	int					fractal_type;
	int					color_mode;
	float				zoom;
	float				mx;
	float				my;
	int					iter;
	int					bail;
	int					(*fractals[FRACTALS])(struct s_fractal *f,
												int i, int j);
	int					(*color_modes[COLOR_MODES])(struct s_fractal *f, int i);
}						t_fractal;

typedef struct			s_fractal_thread
{
	int					from_y;
	int					to_y;
	int					from_x;
	int					to_x;
	t_fractal			*fractal;
	pthread_t			thread;
}						t_fractal_thread;

int						init_fractal(t_fractal **f, int ac, char **av);
void					delete_fractal(t_fractal **fp);

void					update_fractal(t_fractal *f);

int						mandelbrot(t_fractal *f, int i, int j);
int						julia(t_fractal *f, int i, int j);

int						bw_color_mode(t_fractal *f, int i);
int						red_color_mode(t_fractal *f, int i);
int						green_color_mode(t_fractal *f, int i);
int						blue_color_mode(t_fractal *f, int i);
int						random_color_mode(t_fractal *f, int i);

int						mouse_move_hook(int x, int y, t_fractal *f);
int						mouse_press_hook(int btn, int x, int y, t_fractal *f);
int						mouse_release_hook(int btn, int x, int y, t_fractal *f);
int						key_press_hook(int btn, t_fractal *f);

void					print_usage(char *name);
int						get_fractal(char *name);

#endif
