MAKEFLAGS += --silent


RM = rm -rf
CFLAGS	=	-Wall -Wextra -Werror
NAME = push_swap
NAME_BONUS = checker

SRCS_LIBFT = ./src/utils/libft/
GNL = ./src/utils/get_next_line/get_next_line.c\
	./src/utils/get_next_line/get_next_line_utils.c
SRCS = $(shell find ./src/main -name '*.c')
SRCS_BONUS = ./src/checker/checker.c 

 
INC = ./src/main/push_swap.h

BONUS =  $(SRCS_BONUS:.c=.o)
OBJS	=	$(SRCS:.c=.o)
OBJS_BONUS = $(filter-out ./src/main/main.o, $(OBJS))
LIBFT_OBJS = ./src/utils/libft/ft_split.o\
			./src/utils/libft/ft_atoi.o \
			./src/utils/libft/ft_strjoin.o\
			./src/utils/libft/ft_isdigit.o\
			./src/utils/libft/ft_putstr_fd.o\
			./src/utils/libft/ft_substr.o\
			./src/utils/libft/ft_strlen.o\
			./src/utils/libft/ft_strncmp.o\

all: $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -c $^ -o $@ 

$(NAME): $(OBJS)
	$(MAKE) -C $(SRCS_LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_OBJS) -o $(NAME)

bonus : $(NAME) $(BONUS) $(OBJS_BONUS) $(GNL) $(OBJS)
		$(CC) $(OBJS_BONUS) $(BONUS) $(GNL) $(LIBFT_OBJS) -o $(NAME_BONUS)

clean:
	$(MAKE) clean -C $(SRCS_LIBFT)
	$(RM) $(OBJS) $(BONUS)

fclean: clean
	$(RM) $(SRCS_LIBFT)libft.a $(NAME) $(NAME_BONUS)
		

re:			clean all

.PHONY:		re clean fclean all