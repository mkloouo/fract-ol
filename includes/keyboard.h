/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:19:39 by modnosum          #+#    #+#             */
/*   Updated: 2018/03/26 20:30:24 by modnosum         ###   ########.fr       */
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
#  define MINUS_KC 27
#  define EQUAL_KC 24

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
#  define Z_KC -1
#  define X_KC -1
#  define C_KC -1
#  define MINUS_KC -1
#  define EQUAL_KC -1

#  define SHIFT_KC 65505

#  define UP_ARR_KC 65362
#  define LEFT_ARR_KC 65361
#  define DOWN_ARR_KC 65364
#  define RIGHT_ARR_KC 65363

#  define NUM_PLUS_KC 65451
#  define NUM_MINUS_KC 65453
#  define NUM_ONE_KC -1
#  define NUM_TWO_KC -1
#  define NUM_THREE_KC -1

# endif

# define QUIT_BUTTON(B) (B == ESC_KC)

# define MOVE_UP(B) (B == UP_ARR_KC || B == W_KC)
# define MOVE_LEFT(B) (B == LEFT_ARR_KC || B == A_KC)
# define MOVE_DOWN(B) (B == DOWN_ARR_KC || B == S_KC)
# define MOVE_RIGHT(B) (B == RIGHT_ARR_KC || B == D_KC)

# define MOVE_HOR(B) (MOVE_LEFT(B) || MOVE_RIGHT(B))
# define MOVE_VER(B) (MOVE_UP(B) || MOVE_DOWN(B))

# define MOVE_BUTTON(B) (MOVE_HOR(B) || MOVE_VER(B))

# define ROTATE_X_P(B) (B == W_KC)
# define ROTATE_X_M(B) (B == S_KC)
# define ROTATE_Y_P(B) (B == D_KC)
# define ROTATE_Y_M(B) (B == A_KC)
# define ROTATE_Z_P(B) (B == E_KC)
# define ROTATE_Z_M(B) (B == Q_KC)

# define ROTATE_X(B) (ROTATE_X_P(B) || ROTATE_X_M(B))
# define ROTATE_Y(B) (ROTATE_Y_P(B) || ROTATE_Y_M(B))
# define ROTATE_Z(B) (ROTATE_Z_P(B) || ROTATE_Z_M(B))

# define ROTATE(B) (ROTATE_X(B) || ROTATE_Y(B) || ROTATE_Z(B))

# define SCALE_Z_M(B) (B == Z_KC)
# define SCALE_Z_P(B) (B == X_KC)

# define SCALE_Z(B) (SCALE_Z_P(B) || SCALE_Z_M(B))

# define ZOOM_IN(B) (B == NUM_PLUS_KC)
# define ZOOM_OUT(B) (B == NUM_MINUS_KC)

# define ZOOM_BUTTON(B) (ZOOM_IN(B) || ZOOM_OUT(B))

# define RESET_BUTTON(B) (B == R_KC)

# define SHIFT_BUTTON(B) (B == SHIFT_KC)
# define CTRL_BUTTON(B) (B == CTRL_KC)
# define ALT_BUTTON(B) (B == ALT_KC)

typedef struct			s_keyboard
{
	int					shift_pressed;
	int					ck;
}						t_keyboard;

t_keyboard				*get_keyboard(void);
void					delete_keyboard(t_keyboard **kp);

#endif
