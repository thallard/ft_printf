SRCS =	ft_printf.c \
		srcs/ft_printers.c \
		srcs/ft_checkers.c \
		srcs/ft_setters.c \
		srcs/ft_set_flags.c \
		srcs/ft_utils.c \
		srcs/ft_printers2.c \
		srcs/ft_fillers.c \
		srcs/ft_utils2.c \
		\
		srcs/printers_each_type/ft_print_char.c \
		srcs/printers_each_type/ft_print_int.c \
		srcs/printers_each_type/ft_print_hexa.c \
		srcs/printers_each_type/ft_print_unsigned_int.c

OBJBONUS = ${SRCBONUS:.c=.o}

OBJS = ${SRCS:.c=.o}

HEADER = ./includes/printf.h

NAME = libftprintf.a

CC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

%.o: %.c	${HEADER}
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

bonus:
			${NAME}
clean:
			${RM} ${OBJS} 

fclean:		clean
			${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re