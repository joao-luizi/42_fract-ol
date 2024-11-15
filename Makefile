#.SILENT:

CC			=	cc
CFLAGS 		= -Wall -Wextra -Werror -I$(INC_DIR) -I$(MLX_PATH)
RM			=	rm -rf

SRC_DIR		= ./src
OBJ_DIR 	= ./obj
INC_DIR		= ./inc
BIN_DIR		= ./bin
LIB_DIR		= ./lib
NAME			=	${BIN_DIR}/fractol

LIFT_PATH		=	$(addprefix $(LIB_DIR)/, libft/)

MLX_PATH		=	$(addprefix $(LIB_DIR)/, minilibx-linux/)

LINKS = -lmlx -lXext -lX11 -L$(MLX_PATH) -lmlx -L$(LIFT_PATH)lib -lft -lm

SRC				=	$(addprefix $(SRC_DIR)/, fractol.c)																										\
					$(addprefix $(SRC_DIR)/math/, math_aux.c) $(addprefix $(SRC_DIR)/math/, double_aux.c) $(addprefix $(SRC_DIR)/math/, custom_itoa_f.c)	\
					$(addprefix $(SRC_DIR)/t_fractal/, t_fractal_aux.c) $(addprefix $(SRC_DIR)/t_fractal/, t_fractal_init.c)								\
					$(addprefix $(SRC_DIR)/parser/, parser.c)																								\
					$(addprefix $(SRC_DIR)/t_graphics/, t_graphics_init.c) $(addprefix $(SRC_DIR)/t_graphics/, t_graphics_free.c)							\
					$(addprefix $(SRC_DIR)/events/, events.c) $(addprefix $(SRC_DIR)/events/, events_init.c) 												\
					$(addprefix $(SRC_DIR)/asc_strings/, letters.c) $(addprefix $(SRC_DIR)/asc_strings/, digits.c) 											\
					$(addprefix $(SRC_DIR)/asc_strings/, patterns.c) $(addprefix $(SRC_DIR)/asc_strings/, write_string.c) 									\
					$(addprefix $(SRC_DIR)/render/, render_gui.c) $(addprefix $(SRC_DIR)/render/, render_fractal.c) $(addprefix $(SRC_DIR)/render/, render_aux.c)										\
					$(addprefix $(SRC_DIR)/, debug.c) 																										\

OBJS = 				${patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRC}}


$(NAME):			$(OBJS) | $(BIN_DIR)
					printf 'Compiling $(NAME)\n'
					$(CC) $(CFLAGS) $^ -o $@ $(LINKS)

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
					make libs
					printf "Compiling $(NAME) objects... %-33.33s\r" $(notdir $@)
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

all:				$(NAME)

libs:
					make -C $(MLX_PATH)
					make -C $(LIFT_PATH)

clean:
					@if [ -d $(OBJ_DIR) ]; then $(RM) $(OBJ_DIR); fi
					@if [ -f $(NAME) ]; then $(RM) $(NAME); fi

fclean:				clean
					$(RM) $(NAME)
					make fclean -C $(LIFT_PATH)
					make clean -C $(MLX_PATH)

re:					fclean all

.PHONY:				all clean fclean re
