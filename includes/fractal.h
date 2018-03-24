/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:48:42 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/24 17:52:00 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <window.h>

# define FRACTALS 1

# define MANDELBROT_TYPE 0
# define MANDELBROT_NAME "Mandelbrot"

# define DEFAULT_ZOOM 0
# define DEFAULT_ITERATIONS 50
# define DEFAULT_BAIL 16

typedef struct			s_fractal
{
	t_window			*window;
	int					type;
	float				zoom;
	float				mx;
	float				my;
	int					iter;
	int					bail;
	int					(*fractals[FRACTALS])(struct s_fractal *f, int i, int j);
}						t_fractal;

int						init_fractal(t_fractal **f, int ac, char **av);
void					init_fractals(t_fractal *f);
void					delete_fractal(t_fractal **fp);

void					update_fractal_window(t_fractal *f);

int						mandelbrot(t_fractal *f, int i, int j);

int						mouse_move_hook(int x, int y, t_fractal *f);
int						key_press_hook(int btn, t_fractal *f);

void					print_usage(char *name);
int						get_fractal(char *name);

#endif
