# Colors
RESET			= "\033[0m"
BLACK    		= "\033[30m"    # Black
RED      		= "\033[31m"    # Red
GREEN    		= "\033[32m"    # Green
YELLOW   		= "\033[33m"    # Yellow
BLUE     		= "\033[34m"    # Blue
MAGENTA  		= "\033[35m"    # Magenta
CYAN     		= "\033[36m"    # Cyan
WHITE    		= "\033[37m"    # White

# Compiler
NAME			= miniRT
CC				= cc
CFLAGS			= -Wall -Wextra -Werror #-g3 -fsanitize=address
# - g3: Include debugging information
# - fsanitize=address: Enable address sanitization for debugging

# Get the operating system name
OS				= $(shell uname)
# Suppress output from make calls
MAKE			= make -sC
# Create directories if they don't exist
MKDIR			= mkdir -p
# Remove files or directories recursively
RM				= rm -rf

# Libft Files
LIBFT_DIR		= libft
LIBFT			= $(LIBFT_DIR)/libft.a
LINKER			= -lft -L $(LIBFT_DIR)

# Includes Files
INCLUDES_DIR	= includes
INCLUDES_FLAG	= -I$(INCLUDES_DIR) \
				  -I$(LIBFT_DIR) \

INCLUDES		= $(wildcard $(INCLUDES_DIR)/*.h) \
				  $(LIBFT_DIR)/libft.h \

# Sources
SRCS_DIR			= srcs/
DEBUG_FILES			= $(addprefix debug/, draw_sil.c draw_sphere.c print.c)
TEST_FILES			= $(addprefix debug/tests/, test_rays.c test_normal_at.c test_transform.c \
									test_tuples.c test_projectile.c test_circle.c test_clock.c \
									test_phong.c test_world.c view_transform_test.c)
MAIN_FILES			= $(addprefix main/, main.c main_rays.c main_phong.c main_transform.c main_tuples.c main_world.c main_view.c)
ENGINE_FILES		= $(addprefix make_engine/, clean_engine.c draw_pixel.c make_engine.c)
MATRIX_FILES		= $(addprefix matrices/, determinant.c matrix_create.c matrix_free.c matrix_invert.c matrix_utils.c)
RAYS_FILES			= $(addprefix rays/, hits.c intersect.c ray_sphere.c rays.c transform.c)
REFLECTION_FILES	= $(addprefix reflection/, pre_compute.c normal_at.c ft_material.c ft_reflect.c ft_shading.c)
SCENE_FILES			= $(addprefix scene/, world.c objects.c)
TRANSFORM_FILES		= $(addprefix transformations/, conversion.c transformations.c)
TUPLE_FILES			= $(addprefix tuple/, operations.c product.c \
						tuples.c tuple_utils.c)
UTILS_FILES			= $(addprefix utils/, colours.c free_utils.c messages.c ft_utils.c)
VIEW_FILES			= $(addprefix view/, view_transform.c)


SRC_FILES		= 	$(MATRIX_FILES) $(TUPLE_FILES) $(DEBUG_FILES) $(TEST_FILES) \
					$(MAIN_FILES) $(ENGINE_FILES) $(TRANSFORM_FILES) \
					$(RAYS_FILES) $(SCENE_FILES) $(UTILS_FILES) \
					$(REFLECTION_FILES) $(VIEW_FILES)


SRCS			= $(addprefix $(SRCS_DIR), $(SRC_FILES))



# Objects
OBJS_DIR		= objs/
OBJ_FILES		= $(SRC_FILES:.c=.o)
OBJS			= $(addprefix $(OBJS_DIR), $(OBJ_FILES))

# Objects
OBJS_DIR		= objs/
OBJ_FILES		= $(SRC_FILES:.c=.o)
OBJS			= $(addprefix $(OBJS_DIR), $(OBJ_FILES))

# Platform-dependent compilation
ifeq ($(OS), Linux)
	MLX_DIR			= mlx_linux
	MLX				= $(MLX_DIR)/libmlx.a
	LINKER			+= -lmlx -lm -lz -lXext -lX11 -L $(MLX_DIR)
	INCLUDES_FLAG	+= -I$(MLX_DIR)
else
	MLX_DIR			= mlx_macos
	MLX				= $(MLX_DIR)/libmlx.a
	LINKER			+= -lmlx -lm -framework OpenGl -framework Appkit -L $(MLX_DIR)
	INCLUDES_FLAG	+= -I$(MLX_DIR)
endif

# Default target to build everything
all : $(LIBFT) $(MLX) $(OBJS_DIR) $(NAME)

$(LIBFT) :
	@echo $(CYAN) " - Making Libft..." $(RESET)
	@$(MAKE) $(LIBFT_DIR)
	@echo $(GREEN) " - Libft Ready!" $(RESET)

$(MLX) :
	@echo $(CYAN) " - Making mlx..." $(RESET)
	@$(MAKE) $(MLX_DIR) > /dev/null 2>&1;
	@echo $(GREEN) " - Made mlx!" $(RESET)

$(OBJS_DIR):
	@$(MKDIR) $(OBJS_DIR)
	@$(MKDIR) $(OBJS_DIR)/debug
	@$(MKDIR) $(OBJS_DIR)/debug/tests
	@$(MKDIR) $(OBJS_DIR)/main
	@$(MKDIR) $(OBJS_DIR)/make_engine
	@$(MKDIR) $(OBJS_DIR)/matrices
	@$(MKDIR) $(OBJS_DIR)/rays
	@$(MKDIR) $(OBJS_DIR)/reflection
	@$(MKDIR) $(OBJS_DIR)/scene
	@$(MKDIR) $(OBJS_DIR)/transformations
	@$(MKDIR) $(OBJS_DIR)/tuple
	@$(MKDIR) $(OBJS_DIR)/utils
	@$(MKDIR) $(OBJS_DIR)/view




$(NAME) : $(OBJS) Makefile
	@echo $(CYAN) " - Compiling $(NAME)..." $(RESET)
	@$(CC) $(CFLAGS) $(OBJS) $(LINKER) -lm -o $(NAME)
	@echo $(GREEN) " - "$(NAME)" Ready!" $(RESET)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c $(INCLUDES)
	@$(CC) $(CFLAGS) $(INCLUDES_FLAG) -c $< -o $@

#Clean Targets
#Removes Objects Files
clean :
	@$(RM) $(OBJS_DIR)
	@ make -C $(LIBFT_DIR) clean > /dev/null 2>&1
	@echo $(MAGENTA) " - Files & Directory Deleted " $(RESET)

#Removes Objects files, the executable, and cleans the libraries
fclean : clean
	@$(RM) $(NAME)
	@$(MAKE) $(MLX_DIR) clean > /dev/null 2>&1;
	@$(MAKE) $(LIBFT_DIR) fclean
	@echo $(GREEN) " - Fully Cleaned!" $(RESET)
#Performs a full clean and rebuilds everything.
re: fclean all

#Declares targets that are not actual files, ensuring they run regardless of file status.
.PHONY: all clean fclean re
