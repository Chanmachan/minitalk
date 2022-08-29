C_NAME = client
S_NAME = server

SRCS_DIR = ./srcs

OBJS_DIR = ./objs

C_SRCS_FILE = client.c
S_SRCS_FILE = server.c

C_SRCS = $(addprefix $(SRCS_DIR)/,$(C_SRCS_FILE))
S_SRCS = $(addprefix $(SRCS_DIR)/,$(S_SRCS_FILE))

PRINTF = ./ft_printf

INCLUDES = includes/minitalk.h

C_OBJS = $(patsubst $(SRCS_DIR)/%, $(OBJS_DIR)/%, $(C_SRCS:.c=.o))
S_OBJS = $(patsubst $(SRCS_DIR)/%, $(OBJS_DIR)/%, $(S_SRCS:.c=.o))

LIBFT_ARC = ./libft/libft.a
PRINTF_ARC = ./ft_printf/libftprintf.a

CFLAGS = -Wall -Wextra -Werror
#-MP -MMD

all: $(S_NAME) $(C_NAME)

bonus: all

$(S_NAME): $(S_OBJS)
		$(MAKE) -C $(PRINTF)
		$(CC) $(CFLAGS) $(S_OBJS) $(LIBFT_ARC) $(PRINTF_ARC) -o $(S_NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
		mkdir -p $(OBJS_DIR)
		$(CC) $(CFLAGS) -c $< -o $@

$(C_NAME): $(C_OBJS)
		$(CC) $(CFLAGS) $(C_OBJS) $(LIBFT_ARC) -o $(C_NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
		mkdir -p $(OBJS_DIR)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) -r $(OBJS_DIR) $(OBJS_DIR)
		$(MAKE) -C $(PRINTF) clean

fclean: clean
		$(MAKE) -C $(PRINTF) fclean
		$(RM) $(C_NAME) $(S_NAME)

re: fclean all

.PHONY: all clean fclean re