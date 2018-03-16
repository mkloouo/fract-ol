/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:48:42 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/16 03:36:25 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <window.h>

# define FRACTALS 1

# define MANDELBROT_TYPE 1
# define MANDELBROT_NAME "Mandelbrot"

# define DEFAULT_ZOOM -2
# define DEFAULT_ITERATIONS 100
# define DEFAULT_BAIL 16

typedef struct			s_fwin
{
	t_window			*window;
	int					type;
	float				zoom;
	float				mx;
	float				my;
	int					iter;
	int					bail;
	int					((*fractals[FRACTALS])(struct s_fwin *,int,int));
}						t_fwin;

t_fwin					init_fw(int ac, char **av);

int						mouse_move_hook(int x, int y, t_fwin *fw);
int						key_press_hook(int btn, t_fwin *fw);
int						expose_hook(t_fwin *fw);

void					print_fractol_usage(char *name);
int						get_fractal_type(char *name);

#endif
