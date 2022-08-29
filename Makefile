C_NAME = client
S_NAME = server

C_SRCS_DIR = ./c_srcs
S_SRCS_DIR = ./s_srcs

C_OBJS_DIR = ./c_objs
S_OBJS_DIR = ./s_objs

C_SRCS_FILE = client.c
S_SRCS_FILE = server.c

C_SRCS = $(addprefix $(C_SRCS_DIR)/,$(C_SRCS_FILE))
S_SRCS = $(addprefix $(S_SRCS_DIR)/,$(S_SRCS_FILE))

LIBFT = ./libft
PRINTF = ./ft_printf

INCLUDES = includes/minitalk.h

C_OBJS = $(patsubst $(C_SRCS_DIR)/%, $(C_OBJS_DIR)/%, $(C_SRCS:.c=.o))
S_OBJS = $(patsubst $(S_SRCS_DIR)/%, $(S_OBJS_DIR)/%, $(S_SRCS:.c=.o))

LIBFT_ARC = ./libft/libft.a
PRINTF_ARC = ./ft_printf/libftprintf.a

CFLAGS = -Wall -Wextra -Werror
#-MP -MMD

all: $(S_NAME) $(C_NAME)

$(S_NAME): $(S_OBJS)
		$(MAKE) -C $(PRINTF)
		$(CC) $(CFLAGS) $(S_OBJS) $(LIBFT_ARC) $(PRINTF_ARC) -o $(S_NAME)

$(S_OBJS_DIR)/%.o: $(S_SRCS_DIR)/%.c
		mkdir -p $(S_OBJS_DIR)
		$(CC) $(CFLAGS) -c $< -o $@

$(C_NAME): $(C_OBJS)
		$(CC) $(CFLAGS) $(C_OBJS) $(LIBFT_ARC) -o $(C_NAME)

$(C_OBJS_DIR)/%.o: $(C_SRCS_DIR)/%.c
		mkdir -p $(C_OBJS_DIR)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) -r $(C_OBJS_DIR) $(S_OBJS_DIR)
		$(MAKE) -C $(LIBFT) clean

fclean: clean
		$(MAKE) -C $(LIBFT) fclean
		$(RM) $(C_NAME) $(S_NAME)

re: fclean all

.PHONY: all clean fclean re server client