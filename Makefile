SRCS			= utils/stack.c utils/helpers.c algorithms/ft_stack_of_three.c algorithms/ft_populate_stack_a.c  algorithms/ft_populate_stack_b.c \
				  algorithms/ft_quick_sort.c algorithms/ft_binary_search.c algorithms/ft_to_binary.c \
				  commands/push.c  commands/swap.c commands/rotate.c commands/rev_rotate.c ft_push_swap.c main.c

OBJS			= $(SRCS:.c=.o)

CC				= cc -g
RM				= rm -f
CFLAGS			= -Wall -Wextra

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
