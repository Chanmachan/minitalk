NAME = libftprintf.a

SRCS_DIR = ./srcs

OBJS_DIR = ./objs

SRCS_FILE = ft_printf.c if_conv.c put_conv_base.c put_func.c

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILE))

LIBFT = ../libft

INCLUDES = ./includes/ft_printf.h

OBJS = $(patsubst $(SRCS_DIR)/%, $(OBJS_DIR)/%, $(SRCS:.c=.o))

LIBFT_ARC = ../libft/libft.a

CFLAGS = -Wall -Wextra -Werror

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR) :
		mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS)
		$(MAKE) -C $(LIBFT)
		ar rcs $(NAME) $(OBJS) $(LIBFT_ARC)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) -r $(OBJS_DIR)
		$(MAKE) -C $(LIBFT) clean

fclean:	clean
		$(RM) $(NAME)
		$(MAKE) -C $(LIBFT) fclean

re:		fclean all

.PHONY:	all clean fclean re