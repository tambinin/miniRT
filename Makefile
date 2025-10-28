GREEN		=	$(shell tput -Txterm setaf 2)
END			=	$(shell tput -Txterm sgr0)

NAME		=	miniRT

SRC_DIR		=	./source
GNL_DIR		=	./get_next_line
OBJ_DIR		=	./obj

SRCS		=	$(SRC_DIR)/main.c $(SRC_DIR)/main_utils.c $(SRC_DIR)/utils.c \
				$(SRC_DIR)/error.c $(SRC_DIR)/check.c \
				$(SRC_DIR)/cleanup/cleanup.c $(SRC_DIR)/cleanup/clean_elements.c \
				$(SRC_DIR)/cleanup/free_arrays.c $(SRC_DIR)/cleanup/utils.c \
				$(SRC_DIR)/geo_objects/cylinders.c $(SRC_DIR)/geo_objects/cylinders_utils.c \
				$(SRC_DIR)/geo_objects/planes.c $(SRC_DIR)/geo_objects/spheres.c \
				$(SRC_DIR)/geo_objects/geo_utils.c $(SRC_DIR)/geo_objects/objects_utils.c \
				$(SRC_DIR)/geo_objects/validate_sphere.c $(SRC_DIR)/geo_objects/validate_cylinder.c \
				$(SRC_DIR)/geo_objects/validate_plane.c $(SRC_DIR)/geo_objects/validate_objects.c \
				$(SRC_DIR)/math_utils/color.c $(SRC_DIR)/math_utils/matrix.c \
				$(SRC_DIR)/math_utils/matrix_part_two.c $(SRC_DIR)/math_utils/matrix_part_three.c \
				$(SRC_DIR)/math_utils/matrix_part_four.c $(SRC_DIR)/math_utils/utils.c \
				$(SRC_DIR)/math_utils/vector.c $(SRC_DIR)/math_utils/rotation.c \
				$(SRC_DIR)/math_utils/rotation_cam.c $(SRC_DIR)/math_utils/vector_aux.c \
				$(SRC_DIR)/mlx_utils/manage_hooks.c $(SRC_DIR)/mlx_utils/mouse_key.c \
				$(SRC_DIR)/mlx_utils/win_manager.c $(SRC_DIR)/mlx_utils/init_mlx.c \
				$(SRC_DIR)/mlx_utils/handle_move_obj.c $(SRC_DIR)/mlx_utils/moving_objects.c \
				$(SRC_DIR)/mlx_utils/handle_rotate_obj.c $(SRC_DIR)/mlx_utils/rotating_objects.c \
				$(SRC_DIR)/mlx_utils/resizing_obj.c $(SRC_DIR)/mlx_utils/handle_scene_move.c \
				$(SRC_DIR)/mlx_utils/moving_scene.c $(SRC_DIR)/mlx_utils/handle_rotate_camera.c \
				$(SRC_DIR)/mlx_utils/rotating_camera.c $(SRC_DIR)/mlx_utils/solving_obj.c \
				$(SRC_DIR)/mlx_utils/activate_axis.c $(SRC_DIR)/mlx_utils/quit_mode.c \
				$(SRC_DIR)/parsing/process_file.c $(SRC_DIR)/parsing/process_line.c \
				$(SRC_DIR)/parsing/parse_utils.c $(SRC_DIR)/parsing/validate_ambient.c \
				$(SRC_DIR)/parsing/validate_camera.c $(SRC_DIR)/parsing/validate_light.c \
				$(SRC_DIR)/parsing/manage_error.c \
				$(SRC_DIR)/raytracing/camera.c $(SRC_DIR)/raytracing/intersect.c \
				$(SRC_DIR)/raytracing/light.c $(SRC_DIR)/raytracing/ray.c \
				$(SRC_DIR)/raytracing/shading.c \
				$(SRC_DIR)/render/image.c $(SRC_DIR)/render/color.c \
				$(SRC_DIR)/render/render.c $(GNL_DIR)/get_next_line.c \
				$(GNL_DIR)/get_next_line_utils.c

OBJS		=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(filter $(SRC_DIR)/%, \
				$(SRCS))) \
				$(patsubst $(GNL_DIR)/%.c, $(OBJ_DIR)/%.o, $(filter $(GNL_DIR)/%, \
				$(SRCS)))

LIBFT_DIR	=	./libft
LIBFT		=	$(LIBFT_DIR)/libft.a
LIBFT_INC	=	-I$(LIBFT_DIR)/includes

MLX_DIR		=	../minilibx-linux
MLX_LIB		=	-L$(MLX_DIR) -lmlx -lXext -lX11
MLX_INC		=	-I$(MLX_DIR)

PRINTF_DIR	=	./ft_printf
PRINTF		=	$(PRINTF_DIR)/libftprintf.a
PRINTF_INC	=	-I$(PRINTF_DIR)/includes

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -Iincludes -Iminilibx-linux -g

INCS		=	$(LIBFT_INC) $(PRINTF_INC) $(MLX_INC)

RM			=	rm -rf

G			=	$(GREEN)
X			=	$(END)

OBJ_SUBDIRS	=	$(sort $(dir $(OBJS)))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_SUBDIRS)

$(OBJ_SUBDIRS):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(OBJ_SUBDIRS)
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c | $(OBJ_DIR) $(OBJ_SUBDIRS)
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJ_SUBDIRS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX_DIR)/libmlx.a
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX_LIB) -lm -o $(NAME)
	@echo "\n$(GREEN)$(NAME) compiled successfully!$(END)"

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory

$(PRINTF):
	@make -C $(PRINTF_DIR) --no-print-directory

$(MLX_DIR)/libmlx.a:
	@make -C $(MLX_DIR) --no-print-directory

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean --no-print-directory
	@make -C $(PRINTF_DIR) fclean --no-print-directory
	@make -C $(MLX_DIR) clean --no-print-directory
	@echo "$(GREEN)Full clean done!$(END)"

clean:
	@if [ -d $(OBJ_DIR) ]; then \
		$(RM) $(OBJS); \
		find $(OBJ_DIR) -type d -empty -delete; \
		$(RM) $(OBJ_DIR); \
	fi
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@make -C $(PRINTF_DIR) clean --no-print-directory
	@make -C $(MLX_DIR) clean --no-print-directory
	@echo "$(GREEN)Clean done!$(END)"

re: fclean all

.PHONY: all fclean clean re
