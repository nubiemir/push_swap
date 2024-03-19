SRCS			= utils/stack.c utils/index.c utils/ft_stack_of_three.c utils/ft_populate_stack_a.c  utils/ft_populate_stack_b.c \
				  operations/push.c  operations/swap.c operations/rotate.c operations/rev_rotate.c ft_push_swap.c main.c

OBJS			= $(SRCS:.c=.o)

CC				= cc -g
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= swap.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

bonus:			$(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
