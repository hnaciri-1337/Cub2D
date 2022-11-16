SRCS =  main.c utils/ft_bzero.c utils/ft_itoa.c utils/ft_atoi.c utils/ft_split.c utils/ft_strchr.c utils/ft_strdup_help.c utils/ft_strlen.c utils/ft_substr.c utils/ft_calloc.c utils/ft_memset.c utils/ft_strdup.c utils/ft_strjoin.c utils/ft_strncmp.c utils/get_next_line.c
INCLUDE = include/cub3d.h
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 -fsanitize=address
OBJS = ${SRCS:.c=.o}
NAME = cub2d
INCLUDE = -I /usr/local/include
MLX = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${INCLUDE} ${OBJS} ${MLX} -o ${NAME}

.c.o : ${SRCS}    
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@rm -rf ${OBJS}

fclean: clean
	@rm -f ${NAME}

re : fclean all
	