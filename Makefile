# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/11/26 16:49:34 by aplat        #+#   ##    ##    #+#        #
#    Updated: 2019/11/27 19:25:24 by aplat       ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = wolf3d

# OS DEFINITION #

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)

FRAMEWORK_PATH = frameworks

SDL = SDL2
SDL_INC = $(FRAMEWORK_PATH)/$(SDL).framework/Headers
FLAG_SDL2F = -F$(FRAMEWORK_PATH) -framework $(SDL) -rpath $(FRAMEWORK_PATH)

SDL_TTF = SDL2_ttf
SDL_TTF_INC = $(FRAMEWORK_PATH)/$(SDL_TTF).framework/Headers
FLAG_SDLTTF = -F$(FRAMEWORK_PATH) -framework $(SDL_TTF) -rpath $(FRAMEWORK_PATH)

SDL_IMAGE = SDL2_image
SDL_IMAGE_INC = $(FRAMEWORK_PATH)/$(SDL_IMAGE).framework/Headers
FLAG_SDLIMAGE = -F$(FRAMEWORK_PATH) -framework $(SDL_IMAGE) -rpath $(FRAMEWORK_PATH)

FLAG_SDL = $(FLAG_SDL2F) $(FLAG_SDLTTF) $(FLAG_SDLIMAGE)

endif

ifeq ($(UNAME), Linux)

endif

export CC = gcc
export CC_FLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

# SRCS #

SRC_PATH = src

SRC_WIN_NAME = 
SRC_WIN_PATH = window
SRC_WIN = $(addprefix $(SRC_WIN_PATH)/, $(SRC_WIN_NAME))

SRC_ERROR_NAME = 
SRC_ERROR_PATH = error
SRC_ERROR = $(addprefix $(SRC_ERROR_PATH)/, $(SRC_ERROR_NAME))

SRC_PARSER_NAME = 
SRC_PARSER_PATH = parser
SRC_PARSER = $(addprefix $(SRC_PARSER_PATH)/, $(SRC_PARSER_NAME))

SRC_EVENT_NAME = 
SRC_EVENT_PATH = event
SRC_EVENT = $(addprefix $(SRC_EVENT_PATH)/, $(SRC_EVENT_NAME))

SRC_RENDER_NAME = 
SRC_RENDER_PATH = render
SRC_RENDER = $(addprefix $(SRC_RENDER_PATH)/, $(SRC_RENDER_NAME))

SRC_UTILS_NAME =
SRC_UTILS_PATH = utils
SRC_UTILS = $(addprefix $(SRC_UTILS_PATH)/, $(SRC_UTILS_NAME))

SRC_NAME = main.c\
			$(SRC_WIN)\
			$(SRC_ERROR)\
			$(SRC_PARSER)\
			$(SRC_EVENT)\
			$(SRC_RENDER)\
			$(SRC_UTILS)\

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

# INCLUDES #

INC_NAME = 

INC_PATH = includes

INCLUDES = -I$(INC_PATH) -I$(SDL_INC) -I$(SDL_TTF_INC) -I$(SDL_IMAGE_INC)

INC = $(addprefix $(INC_PATH)/, $(INC_NAME))

# OBJECTS #

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = obj

SUB_PATH = $(SRC_WIN_PATH)\
			$(SRC_ERROR_PATH)\
			$(SRC_EVENT_PATH)\
			$(SRC_PARSER_PATH)\
			$(SRC_RENDER_PATH)\
			$(SRC_UTILS_PATH)\

OBJ_SUB = $(addprefix $(OBJ_PATH)/, $(SUB_PATH))

OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

# RULES #

all : $(NAME)

$(NAME): $(OBJ) $(LIBFT)
		@printf "\033[1mCompilation du projet \033[34m$@\033[0m \033[1men \033[31m$@\033[0m ✅\n"
		@$(CC) $(CC_FLAGS) -o $@ $(OBJ) -L./libft -lft $(INCLUDES) $(FLAG_SDL)

$(LIBFT):
		@make -C libft

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
		@ mkdir -p $(OBJ_SUB) 2> /dev/null || true
		@ printf "\033[1mCompilation de \033[36m%-20s\033[37m\ten \033[32m%-20s\033[0m ✅\n" $< $@
		@ $(CC) $(CC_FLAGS) $(INCLUDES) -c $< -o $@

clean:
		@ /bin/rm -rf $(OBJ_PATH)
		@make clean -C libft

fclean: clean
		@ /bin/rm -f $(NAME)
		@make fclean -C libft

re: fclean all

norme: 
	@norminette $(SRC_PATH)
	@norminette $(INC_PATH)
	@norminette $(LIBFT)

.PHONY: all, clean, fclean, re

#NAME = wolf3d
#
#SRC_PATH =		./src
#INCLUDE_PATH = ./include
#WIN_DIR =	/window/
#REND_DIR = /render/
#EVENT_DIR = /events/
#PHYS_DIR = /physics/
#PARSE_DIR = /parsing/
#ERROR_DIR = /error/
#UTIL_DIR = /utils/
#
#SRC = main.c 
#
#CC = gcc
#
#DEPENDENCES = $(SRC:.c=.o)
#
#CFLAGS = -Wall -Wextra -Werror -fsanitize=address
#
#BIN_PATH = ./bin
#HEADERS = $(INCLUDE_PATH)\
#			-I./$(libft)\
#			-I$(FW_PATH)/SDL2_image.framework/Headers/\
#			-I$(FW_PATH)/SDL2_ttf.framework/Headers/\
			-I$(FW_PATH)/SDL2.framework/Headers/\


#FW_PATH = ./frameworks
#LIBSDL2 = -framework SDL2 -F $(FW_PATH) -framework SDL2_image -framework SDL2_ttf -rpath $(FW_PATH)
#LIBFT = libft
#LIBRARIES = $(LIBSDL2) ./$(LIBFT)/$(LIBFT).a

#all : directory $(NAME)

#(NAME) : $(LIBFT) $(DEPENDENCES) $(INFO)
#	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIBSDL2) -I $(HEADERS)
#	@echo "\033[32mCompilation ==> DONE\033[0m"

#$(LIBFT) :
#	@make -C libft

#clean:
#	@rm -f $(DEPENDENCES)
#	@rm -rf $(BIN_PATH)
#	@make clean -C libft
#	@make clean -C frameworks
#	@echo "\033[32mSuppression .o ==> DONE\033[0m"

#directory:
#		@mkdir $(BIN_PATH) 2> /dev/null || true
#		@mkdir $(BIN_PATH)/$(WIN_DIR) 2> /dev/null || true
#		@mkdir $(BIN_PATH)/$(REND_DIR) 2> /dev/null || true
#		@mkdir $(BIN_PATH)/$(EVENT_DIR) 2> /dev/null || true
#		@mkdir $(BIN_PATH)/$(PHYS_DIR) 2> /dev/null || true
#		@mkdir $(BIN_PATH)/$(PARSE_DIR) 2> /dev/null || true
#		@mkdir $(BIN_PATH)/$(ERROR_DIR) 2> /dev/null || true
#		@mkdir $(BIN_PATH)/$(UTIL_DIR) 2> /dev/null || true

#fclean:clean
#	@rm -f $(NAME)
#	@make fclean -C libft
#	@echo "\033[32mSuppression binaires ==> DONE"
#
#re:fclean $(NAME)
#
#norme:
#	@norminette $(SRC_PATH)
#	@norminette $(INCLUDE_PATH)
#	@norminette $(LIBFT)

#.PHONY: all clean fclean re directory

#.SILENT: $(DEPENDENCES)
