# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/03 15:46:16 by vmoreau           #+#    #+#              #
#    Updated: 2021/06/10 15:39:13 by vmoreau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_one

####################################COLOR######################################
#----------------reset----------------#
NC = \033[0m

#-----------Regular Colors------------#
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[32m
YELLOW = \033[33;33m
BLUE = \033[0;34m
PURPLE = \033[35m
CYAN = \033[1;36m
WHITE = \033[0;37m

#####################################PATH######################################


################################COMMON  SOURCES################################

SRCS += ./srcs/main.c		./srcs/check_args.c		./srcs/exit_err.c		\
		./srcs/utils.c		./srcs/time.c			./srcs/init.c			\
		./srcs/action.c

####################################BASIC######################################

CFLAGS = -Wall -Wextra -Werror -pthread
# CFLAGS += -g3 -fsanitize=address

CC = clang

INC = Header/

HEADER = $(INC)philo_one.h

OBJ = $(SRCS:.c=.o)

#####################################RULE######################################

all : $(NAME)

$(NAME) : echoCPO $(OBJ) echoOK echoCS
	$(CC) $(CFLAGS) -o $@ $(OBJ)


%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) -I $(INC) $< -o $@
	printf "$(GREEN)██"

clean :	echoCLEAN
	$(RM) $(OBJ)

fclean : clean echoFCLEAN
	$(RM) $(NAME)

re : fclean all

####################################ECHO######################################

echoCPO:
	echo "$(YELLOW)===> Compiling Philo_One$(NC)"
echoOK:
	echo "$(GREEN)OK$(NC)"
echoCS :
	echo "$(GREEN)===> Compilation Success$(NC)"
echoCLEAN :
	echo "$(PURPLE)===> Cleanning OBJ$(NC)"
echoFCLEAN :
	echo "$(PURPLE)===> Cleanning Execs$(NC)"


.PHONY : all clean fclean re

.SILENT :