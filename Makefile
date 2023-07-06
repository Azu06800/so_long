NAME   = so_long

SOURCES			:=	./sources
INCLUDES		:=	./includes
OBJECTS			:=	./bin
LIBFT			:=	./libft

SRCS 			:=	so_long.c \
					so_long_utils.c \
					so_long_utils2.c \
					so_long_utils3.c \
					parsing.c \
					free_all.c \
					mlx_utils.c \
					mlx_utils2.c

OBJS			:=	$(addprefix ${OBJECTS}/, $(SRCS:.c=.o))

CC				:=	gcc
CFLAGS			:=	-Wall -Wextra -Werror
MLX				:=	-lmlx -framework OpenGL -framework AppKit
CINCLUDES		:=	-I ${INCLUDES}
CDEPENDENCIES	:=	-L${LIBFT} -lft

BLACK			:=	"\033[1;30m"
RED				:=	"\033[1;31m"
GREEN			:=	"\033[1;32m"
CYAN			:=	"\033[1;35m"
BLUE			:=	"\033[1;36m"
WHITE			:=	"\033[1;37m"
EOC				:=	"\033[0;0m"

${OBJECTS}/%.o: ${SOURCES}/%.c
	@mkdir -p $(dir $@)
	@echo "● Compilation de "$(BLUE)"${notdir $<}"$(EOC)"."
	@${CC} ${CFLAGS} -o $@ -c $< ${CINCLUDES}

all: ${NAME}

${NAME} : ${OBJS}
	@make -C ${LIBFT} --no-print-directory
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${CDEPENDENCIES} ${MLX}
	@printf "\e[38;5;226m./$@ successfully build\e[0m\n"

clean:
	@echo ${GREEN}"● Supression des fichiers binaires (.o)..."$(EOC)
	@make -C ${LIBFT} clean --no-print-directory
	@rm -rf ${OBJECTS}

fclean: clean
	@echo ${GREEN}"● Supression des executables et librairies..."$(EOC)
	@make -C ${LIBFT} fclean --no-print-directory
	@rm -f ${NAME}

re: fclean all

.PHONY:	all clean fclean re
