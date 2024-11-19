.SILENT:

CC			=	cc
CFLAGS 		= -Wall -Wextra -Werror -I$(INC_DIR) -I$(MLX_PATH) 
RM			=	rm -rf

SRC_DIR		= ./src
OBJ_DIR 	= ./obj
INC_DIR		= ./inc
BIN_DIR		= ./bin
LIB_DIR		= ./lib
NAME			=	${BIN_DIR}/fractol
NAME_BONUS		=	${BIN_DIR}/fractol

LIFT_PATH		=	$(addprefix $(LIB_DIR)/, libft/)

MLX_PATH		=	$(addprefix $(LIB_DIR)/, minilibx-linux/)

LINKS = -lmlx -lXext -lX11 -L$(MLX_PATH) -lmlx -L$(LIFT_PATH)lib -lft -lm

SRC				=	$(addprefix $(SRC_DIR)/math/, math_aux.c) $(addprefix $(SRC_DIR)/math/, double_aux.c) $(addprefix $(SRC_DIR)/math/, custom_itoa_f.c)	\
					$(addprefix $(SRC_DIR)/t_fractal/, t_fractal_aux.c) $(addprefix $(SRC_DIR)/t_fractal/, t_fractal_init.c)								\
					$(addprefix $(SRC_DIR)/parser/, parser.c)																								\
					$(addprefix $(SRC_DIR)/t_graphics/, t_graphics_init.c) $(addprefix $(SRC_DIR)/t_graphics/, t_graphics_free.c)							\
					$(addprefix $(SRC_DIR)/events/, events_aux.c) $(addprefix $(SRC_DIR)/events/, events_init.c) 											\
					$(addprefix $(SRC_DIR)/events/, events_color_a.c) $(addprefix $(SRC_DIR)/events/, events_color_b.c)										\
					$(addprefix $(SRC_DIR)/asc_strings/, digits_0_4.c) $(addprefix $(SRC_DIR)/asc_strings/, digits_5_9.c) 									\
					$(addprefix $(SRC_DIR)/asc_strings/, letters_a_e.c) $(addprefix $(SRC_DIR)/asc_strings/, letters_f_j.c) 								\
					$(addprefix $(SRC_DIR)/asc_strings/, letters_k_o.c) $(addprefix $(SRC_DIR)/asc_strings/, letters_p_t.c) 								\
					$(addprefix $(SRC_DIR)/asc_strings/, letters_u_x.c) $(addprefix $(SRC_DIR)/asc_strings/, letters_y_z.c) 								\
					$(addprefix $(SRC_DIR)/asc_strings/, patterns.c) $(addprefix $(SRC_DIR)/asc_strings/, symbols.c) 										\
					$(addprefix $(SRC_DIR)/asc_strings/, write_string.c) 																					\
					$(addprefix $(SRC_DIR)/render/, render_gui.c) $(addprefix $(SRC_DIR)/render/, render_fractal.c) 										\
					$(addprefix $(SRC_DIR)/render/, render_aux.c) $(addprefix $(SRC_DIR)/render/, render_dynamic.c) 										\
					$(addprefix $(SRC_DIR)/, fractol.c)

SRC_BONUS		=	$(addprefix $(SRC_DIR)/math/, math_aux_bonus.c) $(addprefix $(SRC_DIR)/math/, double_aux_bonus.c) $(addprefix $(SRC_DIR)/math/, custom_itoa_f_bonus.c)	\
					$(addprefix $(SRC_DIR)/t_fractal/, t_fractal_aux_bonus.c) $(addprefix $(SRC_DIR)/t_fractal/, t_fractal_init_bonus.c)								\
					$(addprefix $(SRC_DIR)/parser/, parser_bonus.c)																								\
					$(addprefix $(SRC_DIR)/t_graphics/, t_graphics_init_bonus.c) $(addprefix $(SRC_DIR)/t_graphics/, t_graphics_free_bonus.c)							\
					$(addprefix $(SRC_DIR)/events/, events_aux_bonus.c) $(addprefix $(SRC_DIR)/events/, events_init_bonus.c) 											\
					$(addprefix $(SRC_DIR)/events/, events_color_a_bonus.c) $(addprefix $(SRC_DIR)/events/, events_color_b_bonus.c)										\
					$(addprefix $(SRC_DIR)/asc_strings/, digits_0_4_bonus.c) $(addprefix $(SRC_DIR)/asc_strings/, digits_5_9_bonus.c) 									\
					$(addprefix $(SRC_DIR)/asc_strings/, letters_a_e_bonus.c) $(addprefix $(SRC_DIR)/asc_strings/, letters_f_j_bonus.c) 								\
					$(addprefix $(SRC_DIR)/asc_strings/, letters_k_o_bonus.c) $(addprefix $(SRC_DIR)/asc_strings/, letters_p_t_bonus.c) 								\
					$(addprefix $(SRC_DIR)/asc_strings/, letters_u_x_bonus.c) $(addprefix $(SRC_DIR)/asc_strings/, letters_y_z_bonus.c) 								\
					$(addprefix $(SRC_DIR)/asc_strings/, patterns_bonus.c) $(addprefix $(SRC_DIR)/asc_strings/, symbols_bonus.c) 										\
					$(addprefix $(SRC_DIR)/asc_strings/, write_string_bonus.c) 																					\
					$(addprefix $(SRC_DIR)/render/, render_gui_bonus.c) $(addprefix $(SRC_DIR)/render/, render_fractal_bonus.c) 										\
					$(addprefix $(SRC_DIR)/render/, render_aux_bonus.c) $(addprefix $(SRC_DIR)/render/, render_dynamic_bonus.c) 										\
					$(addprefix $(SRC_DIR)/, fractol_bonus.c)

OBJS 		= 		${patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRC}}

OBJS_BONUS	= 		${patsubst ${SRC_DIR}/.c, ${OBJ_DIR}/%.o, ${SRC_BONUS}}


$(NAME):			$(OBJS) | $(BIN_DIR)
					printf 'Compiling $(NAME)\n'
					$(CC) $(CFLAGS) $^ -o $@ $(LINKS)

$(NAME_BONUS):		$(OBJS_BONUS) | $(BIN_DIR)
					printf 'Compiling $(NAME_BONUS)\n'
					$(CC) $(CFLAGS) $^ -o $@ $(LINKS)

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
					make libs
					printf "Compiling $(NAME) objects... %-33.33s\r" $(notdir $@)
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

info: 	
		$(info OBJS: $(OBJS))
		$(info OBJS_BONUS: $(OBJS_BONUS))

all:				$(NAME)

libs:
					make -C $(MLX_PATH)
					make -C $(LIFT_PATH)

bonus: 				$(NAME_BONUS)



clean:
					@if [ -d $(OBJ_DIR) ]; then $(RM) $(OBJ_DIR); fi
					@if [ -f $(NAME) ]; then $(RM) $(NAME); fi

fclean:				clean
					$(RM) $(NAME)
					make fclean -C $(LIFT_PATH)
					make clean -C $(MLX_PATH)

re:					fclean all

.PHONY:				all clean fclean re
