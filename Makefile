# CC = cc
# CFLAGS = -Werror -Wextra -Wall -MMD -g3
# INCLUDES = -Iincludes -I./lib/ft_printf -I./lib/libft
# SRC_DIR = src
# OBJ_DIR = objs.
# LIBPRINTF = lib/ft_printf/libftprintf.a
# LIBFT = lib/libft/libft.a

# SRCS = $(shell find $(SRC_DIR) $(SRC_DIR) -name '*.c')
# SRCS_BONUS = $(shell find $(SRC_DIR_BONUS) -name '*.c')

# OBJS = $(addprefix $(OBJ_DIR)/,$(addsuffix .o,$(notdir $(basename $(SRCS)))))
# OBJS_BONUS = $(addprefix $(OBJ_DIR_BONUS)/,$(addsuffix .o,$(notdir $(basename $(SRCS_BONUS)))))

# DEPENDS = $(OBJS:.o=.d)

# NAME = pipex
# NAME_BONUS = pipex_bonus

# -include $(DEPEND)

# .PHONY: all
# all: $(MLX) $(NAME)

# .PHONY: bonus
# bonus: $(NAME_BONUS)

# $(NAME): $(OBJS) $(LIBPRINTF) $(LIBFT)
# 			$(CC) $^ -o $@

# $(NAME_BONUS): $(OBJS_BONUS) $(LIBPRINTF) $(LIBFT) $(GNL)
# 			$(CC) $^ -o $@

# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
# 	$(CC)  $(CFLAGS) $(INCLUDES) -c $< -o $@
	
# $(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c | $(OBJ_DIR_BONUS)
# 	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# $(OBJ_DIR):
# 	mkdir -p $(OBJ_DIR)

# $(OBJ_DIR_BONUS):
# 	mkdir -p $(OBJ_DIR_BONUS)

# $(LIBPRINTF):
# 	$(MAKE) -C lib/ft_printf

# $(LIBFT):
# 	$(MAKE) -C lib/libft

# .PHONY: clean
# clean:
# 	rm -rf $(OBJ_DIR)
# 	$(MAKE) -C lib/ft_printf clean
# 	$(MAKE) -C lib/libft clean
# .PHONY: fclean
# fclean: clean
# 	rm -rf $(NAME)
# 	$(MAKE) -C lib/ft_printf fclean
# 	$(MAKE) -C lib/libft fclean

# .PHONY:
# re: fclean all

# Compiler & options
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -MMD -g3
INCLUDES= -Iincludes -Ilib/ft_printf -Ilib/libft

# Répertoires sources
SRC_DIR        = src
SRC_BONUS_DIR  = src_bonus
OBJ_DIR        = objs/normal
OBJ_BONUS_DIR  = objs/bonus

# Libs
LIBFT      = lib/libft/libft.a
LIBPRINTF  = lib/ft_printf/libftprintf.a

# Noms exécutables
NAME        = pipex
NAME_BONUS  = pipex_bonus

# Sources & objets
SRCS        = $(wildcard $(SRC_DIR)/*.c)
SRCS_BONUS  = $(wildcard $(SRC_BONUS_DIR)/*.c)

OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS  = $(SRCS_BONUS:$(SRC_BONUS_DIR)/%.c=$(OBJ_BONUS_DIR)/%.o)

DEPS        = $(OBJS:.o=.d)
DEPS_BONUS  = $(OBJS_BONUS:.o=.d)

-include $(DEPS)
-include $(DEPS_BONUS)

##########################
# CIBLES PRINCIPALES
##########################

.PHONY: all bonus clean fclean re

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS) $(LIBFT) $(LIBPRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT) $(LIBPRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

##########################
# Compilation objets
##########################

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

##########################
# Librairies externes
##########################

$(LIBFT):
	$(MAKE) -C lib/libft

$(LIBPRINTF):
	$(MAKE) -C lib/ft_printf

##########################
# Nettoyage
##########################

clean:
	rm -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)
	$(MAKE) -C lib/libft clean
	$(MAKE) -C lib/ft_printf clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	$(MAKE) -C lib/libft fclean
	$(MAKE) -C lib/ft_printf fclean

re: fclean all
