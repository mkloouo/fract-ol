# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/20 14:34:22 by modnosum          #+#    #+#              #
#    Updated: 2018/03/26 18:41:48 by modnosum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler Configuration
CC						= gcc
CFLAGS					= -Wall -Wextra -Werror -pedantic

# Make Flags
MFLAGS					= --no-print-directory -C

# Target binary name
NAME					:= fractol

# Directories
SRC_DIR					= ./sources
OBJ_DIR					= ./objects
INC_DIR					= ./includes

# Source and object lists as well as directories for objects
SRCS					:= $(shell find $(SRC_DIR) -type f -name "*.c")
OBJS					:= $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRCS:.c=.o))
OBJ_DIRS				:= $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(shell\
find $(SRC_DIR) -type d))

# Add outside variables
FT_PATH					:= ./libft
MLX_PATH				:= ./mlx
include $(FT_PATH)/Libft.mk
include $(MLX_PATH)/Mlx.mk

# Add dirs and libs
IFLAGS					+= -I $(INC_DIR)
ifneq (Darwin,$(UNAME))
LFLAGS					+= -lm -pthread
else
LFLAGS					+= -lm
endif

# Phony rules
.PHONY: all clean fclean re c f

# Colored output
include ColorOut.mk 

# Named rules
all: $(MLX_NAME) $(NAME)
clean:
	@rm -fR $(OBJ_DIR)
	@rm -fR $(MLX_NAME)
	@rm -fR $(FT_NAME)
	$(call PRINT,$(MAGENTA),"Removed $(OBJ_DIR) $(MLX_NAME) $(FT_NAME).")
fclean: clean
	@rm -fR $(NAME)
	@$(MAKE) $(MFLAGS) $(FT_PATH) fclean
ifneq (1,$(MLX_PATH))
	@$(MAKE) $(MFLAGS) $(MLX_PATH) clean
endif
	$(call PRINT,$(MAGENTA),"Removed $(NAME).")
re: fclean all

# Variable rules
$(NAME): $(FT_NAME) $(OBJS)
	@$(CC) -o $@ $(OBJS) *.a $(CFLAGS) $(IFLAGS) $(LFLAGS)
	$(call PRINT,$(GREEN),"Build $@.")

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) -o $@ -c $< $(CFLAGS) $(IFLAGS)
	$(call PRINT,$(BLUE),"$< ->",$(GREEN),"$@")

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIRS)
	$(call PRINT,$(BLUE),"Created $@ directory.")

$(FT_NAME): $(FT_DEP)
	@$(MAKE) $(MFLAGS) $(FT_PATH)
	@cp $(FT_PATH)/$@ ./$@

$(MLX_NAME): $(MLX_DEP)
ifneq (1,$(MLX_PATH))
	@$(MAKE) $(MFLAGS) $(MLX_PATH)
	@cp $(MLX_PATH)/$@ ./$@
endif

# Shortcuts
c: clean
f: fclean
