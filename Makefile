NAME = philo
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread
CC = cc
SRCS =	main.c \
		memory.c \
		thread.c \
		helpers.c \
		monitoring.c \
		philo_actions.c \
		initialization.c

HEADER = 	philosophers.h \

VALIDATION = validation.c

SRCS_DIR = ./sources/program/
HEADER_DIR = ./headers/
VALIDATION_DIR = ./sources/validation/

SRCS := $(addprefix $(SRCS_DIR), $(SRCS))
HEADER := $(addprefix $(HEADER_DIR), $(HEADER)) 
VALIDATION := $(addprefix $(VALIDATION_DIR), $(VALIDATION)) 

SRCS += $(VALIDATION)

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
