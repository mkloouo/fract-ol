#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Mlx.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: modnosum <modnosum@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/26 15:38:12 by modnosum          #+#    #+#              #
#    Updated: 2018/03/16 03:12:16 by modnosum         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Variables for mlx library compilation

UNAME					?= $(shell uname)

MLX_NAME				:= libmlx.a

MLX_PATH				?= ./mlx

MLX_I					:= 
MLX_L					:= -l mlx

ifeq (Darwin,$(UNAME))
	DARWIN_MINOR_VERSION		:= $(shell sw_vers -productVersion | cut -d . -f 2)
	ifeq (1,$(shell echo "$(DARWIN_MINOR_VERSION) >= 13" | bc))
		MLX_PATH				:= ./mlx/mlx_macos/
	else
		MLX_PATH				:= 1
	endif
	MLX_L					+= -framework OpenGL -framework AppKit
else
	MLX_PATH				:= ./mlx/mlx_other/
	MLX_L					+= -l Xext -l X11
endif

ifneq (1,$(MLX_PATH))
	MLX_I					+= -I $(MLX_PATH)
	MLX_L					+= -L $(MLX_PATH)
	MLX_DEP					:= $(shell find $(MLX_PATH) -type f -name "*.c"\
-o -name "*.h")
endif

ifndef LFLAGS
	LFLAGS					:=
	IFLAGS					:=
endif

LFLAGS					+= $(MLX_L)
IFLAGS					+= $(MLX_I)
