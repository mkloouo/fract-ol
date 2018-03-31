/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:48:42 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/31 19:39:30 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <window.h>
# include <pthread.h>

# define FRACTALS 9
# define COLOR_MODES 6
# define FRACTAL_THREADS 4

# define FRACTAL_WIDTH 900
# define FRACTAL_HEIGHT 900

# define INFO_OFFSET 10

# define MANDELBROT_TYPE 0
# define MANDELBROT_NAME "Mandelbrot"

# define JULIA_TYPE 1
# define JULIA_NAME "Julia"

# define NEWTON_TYPE 2
# define NEWTON_NAME "Newton"

# define BURNING_SHIP_TYPE 3
# define BURNING_SHIP_NAME "Burning Ship"

# define TRICORN_TYPE 4
# define TRICORN_NAME "Tricorn"

# define SPIDER_TYPE 5
# define SPIDER_NAME "Spider"

# define CIRCLE_TYPE 6
# define CIRCLE_NAME "Circle"

# define BIOMORPH_TYPE 7
# define BIOMORPH_NAME "Biomorph"

# define MANDELBROT_CUSTOM_TYPE 8
# define MANDELBROT_CUSTOM_NAME "Mandelbrot Custom"

# define DEFAULT_ZOOM 2
# define DEFAULT_MAX_ITER 20
# define DEFAULT_BAIL 16
# define DEFAULT_MIN 1e-6
# define DEFAULT_MAX 1e+6
# define DEFAULT_SCALE 2

# define QUIT_BUTTON(B) (B == ESC_KC)
# define RESET_BUTTON(B) (B == R_KC)
# define COLOR_BUTTON(B) (B == C_KC)
# define FRACTAL_BUTTON(B) (B == F_KC)
# define ITERATION_UP(B) (B == NUM_PLUS_KC)
# define ITERATION_DOWN(B) (B == NUM_MINUS_KC)
# define ITERATION_BUTTON(B) (ITERATION_UP(B) || ITERATION_DOWN(B))
# define NOISE_BUTTON(B) (B == N_KC)

typedef struct			s_fractal
{
	t_window			*window;
	int					type;
	int					mode;
	int					(*f[FRACTALS])(struct s_fractal *f,
									long double i, long double j);
	int					(*c[COLOR_MODES])(struct s_fractal *f, int iter);
	int					max_iter;
	int					bail;
	int					mx;
	int					my;
	int					noise;
	long double			min;
	long double			max;
	long double			sx;
	long double			sy;
	long double			sxf;
	long double			sxt;
	long double			syf;
	long double			syt;
}						t_fractal;

typedef struct			s_fractal_thread
{
	int					fx;
	int					tx;
	t_fractal			*f;
	pthread_t			thread;
}						t_fractal_thread;

int						init_fractal(int ac, char **av);
void					init_default_values(t_fractal *f);
void					delete_fractal(t_fractal **fp);

void					update_fractal(t_fractal *f);
void					zoom_fractal(int in, t_fractal *f);

int						mandelbrot(t_fractal *f, long double i, long double j);
int						julia(t_fractal *f, long double i, long double j);
int						newton(t_fractal *f, long double i, long double j);
int						burning_ship(t_fractal *f, long double i,
						long double j);
int						tricorn(t_fractal *f, long double i, long double j);
int						spider(t_fractal *f, long double i, long double j);
int						circle(t_fractal *f, long double i, long double j);
int						biomorph(t_fractal *f, long double i, long double j);
int						mandelbrot_custom(t_fractal *f, long double i,
						long double j);

int						bw_color_mode(t_fractal *f, int iter);
int						red_color_mode(t_fractal *f, int iter);
int						green_color_mode(t_fractal *f, int iter);
int						blue_color_mode(t_fractal *f, int iter);
int						sixteen_color_mode(t_fractal *f, int iter);
int						twenty_seven_color_mode(t_fractal *f, int iter);

int						mouse_move_hook(int x, int y, t_fractal *f);
int						mouse_press_hook(int btn, int x, int y, t_fractal *f);
int						mouse_release_hook(int btn, int x, int y, t_fractal *f);
int						key_press_hook(int btn, t_fractal *f);

int						info_key_press(int btn, t_fractal *f);

void					print_usage(char *name);
int						get_fractal(char *name);
char					*get_fractal_by_number(int n);

#endif
