CC      = cc
CFLAGS  = -Wall -Wextra -Werror -MMD -g3
INCLUDES= -Iincludes -Ilib/ft_printf -Ilib/libft

SRC_DIR        = src
SRC_BONUS_DIR  = src_bonus
OBJ_DIR        = objs/normal
OBJ_BONUS_DIR  = objs/bonus

LIBFT      = lib/libft/libft.a
LIBPRINTF  = lib/ft_printf/libftprintf.a

NAME        = pipex
NAME_BONUS  = pipex_bonus

SRCS        = $(wildcard $(SRC_DIR)/*.c)
SRCS_BONUS  = $(wildcard $(SRC_BONUS_DIR)/*.c)

OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS  = $(SRCS_BONUS:$(SRC_BONUS_DIR)/%.c=$(OBJ_BONUS_DIR)/%.o)

DEPS        = $(OBJS:.o=.d)
DEPS_BONUS  = $(OBJS_BONUS:.o=.d)

-include $(DEPS)
-include $(DEPS_BONUS)

.PHONY: all bonus clean fclean re

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS) $(LIBFT) $(LIBPRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT) $(LIBPRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C lib/libft

$(LIBPRINTF):
	$(MAKE) -C lib/ft_printf

clean:
	rm -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)
	$(MAKE) -C lib/libft clean
	$(MAKE) -C lib/ft_printf clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	$(MAKE) -C lib/libft fclean
	$(MAKE) -C lib/ft_printf fclean

re: fclean all
