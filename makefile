# *======== SOURCES ========*

SRCS_1	=	\
			events.c				\
			so_long.c				\
			pathfinder.c			\
			check_walls.c			\
			image_manip.c			\
			notice_reading.c		\
			notice_reading_utils.c
			

SRCSD	= srcs/

OBJS_1	= ${addprefix ${SRCSD}, ${SRCS_1:.c=.o}}

# *======== INCLUDES ========*

INC = -I ./include
INCMLX = -I ./libs/minilibx-linux
INCPRINTF = -I ./libs/printf/scrs

# *======== LIBS ========*

MLX_DIR = ./libs/minilibx-linux
MLX_FLAGS = -ldl -Lmlx_linux -lm -lXext -lX11 -Imlx libs/minilibx-linux/libmlx.a
PRINTF_DIR = ./libs/printf
PRINTF_FLAGS = -L$(PRINTF_DIR) -l ftprintf

# *======== OTHERS ========*

NAME_1	= so_long

CC		= clang
RM		= rm -rf

CFLAGS	= -g3 -Wall -Wextra -Werror

# *======== RULES ========*

all:		${NAME_1}

.c.o:	
		@clang ${CFLAGS} ${INCPRINTF} ${INC} -c $< -o $(<:.c=.o)

${NAME_1}:	${OBJS_1}
					make -C ${MLX_DIR}
					make -C ${PRINTF_DIR}
			${CC} ${CFLAGS} ${INCPRINTF} ${INCMLX} ${INC} ${OBJS_1} ${PRINTF_FLAGS} ${MLX_FLAGS} -o ${NAME_1}

clean:
			${RM} ${OBJS_1}
					make clean -C ${MLX_DIR}
					make clean -C ${PRINTF_DIR}

fclean:		clean
			${RM} ${NAME_1}
					make fclean -C ${PRINTF_DIR}
					make clean -C ${MLX_DIR}

re:			fclean all

.PHONY:		all clean fclean re