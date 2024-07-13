NAME = philo
CFLAGS = -Wall -Wextra -Werror 
CC = cc #-fsanitize=address
SRCS =	validation.c \

HEADER = 	philosophers.h \
			helpers.c

SRCS_DIR = ./sources/validation/
HEADER_DIR = ./headers/

SRCS := $(addprefix $(SRCS_DIR), $(SRCS))
HEADER := $(addprefix $(HEADER_DIR), $(HEADER)) 

SRCS += $(LIBFT)

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} Makefile 
	@${CC} ${CFLAGS} -I$(HEADER_DIR) ${OBJS} -o ${NAME}

.c.o:
	$(CC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $(<:.c=.o)

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean ${NAME}

.PHONY: all clean fclean re
