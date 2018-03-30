/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:19:39 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/30 22:05:49 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
# define KEYBOARD_H

# if defined(__APPLE__)

#  define ESC_KC 53

#  define Q_KC 12
#  define W_KC 13
#  define E_KC 14
#  define R_KC 15
#  define A_KC 0
#  define S_KC 1
#  define D_KC 2
#  define Z_KC 6
#  define X_KC 7
#  define C_KC 8
#  define F_KC -1

#  define SHIFT_KC 257

#  define UP_ARR_KC 126
#  define LEFT_ARR_KC 123
#  define DOWN_ARR_KC 125
#  define RIGHT_ARR_KC 124

#  define NUM_PLUS_KC 69
#  define NUM_MINUS_KC 78
#  define NUM_ONE_KC 83
#  define NUM_TWO_KC 84
#  define NUM_THREE_KC 85

# elif defined(__linux__)

#  define ESC_KC 65307

#  define Q_KC 113
#  define W_KC 119
#  define E_KC 101
#  define R_KC 114
#  define A_KC 97
#  define S_KC 115
#  define D_KC 100
#  define Z_KC 122
#  define X_KC 120
#  define C_KC 99
#  define F_KC 102

#  define SHIFT_KC 65505

#  define UP_ARR_KC 65362
#  define LEFT_ARR_KC 65361
#  define DOWN_ARR_KC 65364
#  define RIGHT_ARR_KC 65363

#  define NUM_PLUS_KC 65451
#  define NUM_MINUS_KC 65453
#  define NUM_ONE_KC 65436
#  define NUM_TWO_KC 65433
#  define NUM_THREE_KC 65435

# endif

typedef struct			s_keyboard
{
	int					shift_pressed;
	int					ck;
}						t_keyboard;

t_keyboard				*get_keyboard(void);
void					delete_keyboard(t_keyboard **kp);

#endif
