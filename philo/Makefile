# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/21 15:04:38 by jpiquet           #+#    #+#              #
#    Updated: 2025/09/26 11:08:42 by gaducurt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -MMD -MP -I$(INCLUDE) -g3 -pthread

INCLUDE = inc

BIN = bin/
			
DIR_SRC = src/

SRC =	main.c	\
		mutex/manage_mutex.c	\
		parsing/init_struct.c	\
		parsing/parsing_utils.c	\
		parsing/parsing.c	\
		threads/display_move.c	\
		threads/handle_threads.c	\
		threads/actions.c	\
		clean.c	\
		print_test.c	\

OBJ = $(SRC: .c=.o)
OBJ := $(addprefix $(BIN), $(SRC:.c=.o))
DEPS =   $(OBJ:.o=.d)

all: .print_header $(BIN) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(BIN)%.o: $(DIR_SRC)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN):
	mkdir -p $(BIN)

clean:
	rm -rf $(BIN)

fclean: clean
	rm -f $(NAME)

re: fclean all

.print_header:
	$(call DISPLAY_TITLE)

.PHONY: all clean fclean re libs

-include $(DEPS)

########################################################################################################################
#                                                       COLORS                                                         #
########################################################################################################################

DEF_COLOR 	= \033[0;39m
GREEN		= \033[1;92m
BLUE		= \033[0;94m

########################################################################################################################
#                                                       DISPLAY                                                        #
########################################################################################################################

define DISPLAY_TITLE
						@echo "$(BLUE) _____  _     _ _	"           
						@echo "|  __ \| |   (_) |		"          
						@echo "| |__) | |__  _| | ___  	"  
						@echo "|  ___/| '_ \| | |/ _ \ 	" 
						@echo "| |    | | | | | | (_) |	"
						@echo "|_|    |_| |_|_|_|\___/ 	"
                        @echo "$(GREEN)		by gaducurt$(DEF_COLOR)" 
                        @printf "\n"
endef
