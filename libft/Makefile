NAME		= libft.a

CC			= clang

CFLAGS		= -Wall -Wextra -Werror

SRCS		= ft_atoi.c\
				ft_atoi_long_long.c\
				ft_bzero.c\
				ft_calloc.c\
				ft_check_extension.c\
				ft_check_file.c\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_itoa.c\
				ft_lstadd_back.c\
				ft_lstadd_front.c\
				ft_lstclear.c\
				ft_lstdelone.c\
				ft_lstiter.c\
				ft_lstlast.c\
				ft_lstmap.c\
				ft_lstnew.c\
				ft_lstsize.c\
				ft_memccpy.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memmove.c\
				ft_memset.c\
				ft_print_str_array.c\
				ft_putchar_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_putstr_fd.c\
				ft_sort_int_tab.c\
				ft_split.c\
				ft_strchr.c\
				ft_strdup.c\
				ft_strjoin.c\
				ft_strlcat.c\
				ft_strlcpy.c\
				ft_strlen.c\
				ft_strmapi.c\
				ft_strncat.c\
				ft_strncmp.c\
				ft_strnstr.c\
				ft_strrchr.c\
				ft_strtrim.c\
				ft_substr.c\
				ft_tolower.c\
				ft_toupper.c\

OBJS		= ${SRCS:.c=.o}

INCLUDES	= ./

RM			= rm -f

.c.o:
				${CC} ${CFLAGS} -I${INCLUDES} -c $< -o ${<:.c=.o}

all: 		${NAME}

$(NAME):	${OBJS}
				ar -crs ${NAME} ${OBJS}

clean:
				${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
				${RM} ${NAME}

re:			fclean all

.PHONY:     all clean fclean re bonus