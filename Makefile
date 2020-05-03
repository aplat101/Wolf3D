# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/11/26 16:49:34 by aplat        #+#   ##    ##    #+#        #
#    Updated: 2019/12/20 22:07:29 by aplat       ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = wolf3d

# OS DEFINITION #

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)

CC = gcc

FRAMEWORK_PATH = minilibx_macos

FRAMEWORK = -framework OpenGL -framework AppKit

LIBX = minilibx_macos/libmlx.a

endif

ifeq ($(UNAME), Linux)

CC = clang

FRAMEWORK_PATH = libxlinux

LIBX = libxlinux/libmlx_Linux.a

MLX_L = -lX11 -lXext -lm -lbsd -lmlx

endif

#export CC = gcc
export CC_FLAGS = -Wall -Wextra -Werror #-fsanitize=address

LIBFT = libft/libft.a

# SRCS #

SRC_PATH = src

SRC_WIN_NAME = ft_window.c
SRC_WIN_PATH = window
SRC_WIN = $(addprefix $(SRC_WIN_PATH)/, $(SRC_WIN_NAME))

SRC_ERROR_NAME = ft_error.c
SRC_ERROR_PATH = error
SRC_ERROR = $(addprefix $(SRC_ERROR_PATH)/, $(SRC_ERROR_NAME))

SRC_PARSER_NAME = ft_parser.c
SRC_PARSER_PATH = parser
SRC_PARSER = $(addprefix $(SRC_PARSER_PATH)/, $(SRC_PARSER_NAME))

SRC_EVENT_NAME = ft_mlx.c\
					ft_bind_keys.c\
					ft_move.c
SRC_EVENT_PATH = event
SRC_EVENT = $(addprefix $(SRC_EVENT_PATH)/, $(SRC_EVENT_NAME))

SRC_RENDER_NAME = ft_render.c\
					ft_textures.c
SRC_RENDER_PATH = render
SRC_RENDER = $(addprefix $(SRC_RENDER_PATH)/, $(SRC_RENDER_NAME))

SRC_UTILS_NAME = ft_utils.c\
					ft_utils_error.c\
					ft_utils_debug.c\
					ft_utils_parser.c\
					ft_utils_render.c
SRC_UTILS_PATH = utils
SRC_UTILS = $(addprefix $(SRC_UTILS_PATH)/, $(SRC_UTILS_NAME))

SRC_NAME = main.c \
			$(SRC_WIN)\
			$(SRC_ERROR)\
			$(SRC_PARSER)\
			$(SRC_EVENT)\
			$(SRC_RENDER)\
			$(SRC_UTILS)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

# INCLUDES #

INC_NAME = info.h\
			wolf3d.h\

INC_PATH = includes

INCLUDES = -I $(INC_PATH)

INC = $(addprefix $(INC_PATH)/, $(INC_NAME))

# OBJECTS #

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = obj

SUB_PATH = $(SRC_PATH)\
			$(SRC_WIN_PATH)\
			$(SRC_ERROR_PATH)\
			$(SRC_EVENT_PATH)\
			$(SRC_PARSER_PATH)\
			$(SRC_RENDER_PATH)\
			$(SRC_UTILS_PATH)\

OBJ_SUB = $(addprefix $(OBJ_PATH)/, $(SUB_PATH))

OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

# RULES #

all : $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(LIBX)
		@printf "\033[1mCompilation du projet \033[34m$@\033[0m \033[1men \033[31m$@\033[0m ✅\n"
ifeq ($(UNAME), Darwin)
	@$(CC) $(CC_FLAGS) -o $@ $(OBJ) -L./libft -lft $(INCLUDES) $(LIBX) $(FRAMEWORK)
else
	@$(CC) $(CC_FLAGS) -o $@ $(OBJ) -L./libft -lft $(INCLUDES) -L./libxlinux $(MLX_L) #$(MLX)
endif

$(LIBFT):
		@make -C libft

$(LIBX) :
ifeq ($(UNAME), Darwin)	
	@make -C minilibx_macos
else	
	@make -C libxlinux
endif


$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
		@ mkdir -p $(OBJ_SUB) 2> /dev/null || true
		@ printf "\033[1mCompilation de \033[36m%-20s\033[37m\ten \033[32m%-20s\033[0m ✅\n" $< $@
		@ $(CC) $(CC_FLAGS) $(INCLUDES) -c $< -o $@

clean:
		@ /bin/rm -rf $(OBJ_PATH)
		@make clean -C libft
		@make clean -C minilibx_macos
		@make clean -C libxlinux

fclean: clean
		@ /bin/rm -f $(NAME)
		@make fclean -C libft

re: fclean all

norme: 
	@norminette $(SRC_PATH)
	@norminette $(INC_PATH)
	@make norme -C libft

.PHONY: all, clean, fclean, re, norme
