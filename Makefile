# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/10 17:05:56 by ddo-carm          #+#    #+#              #
#    Updated: 2025/09/15 21:57:34 by ddo-carm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#		   ________________________________________________        
#  _______|                                               |_______
# \       |                 NAMES & PATHS                 |      /
#  \      |                                               |     /
#  /      |_______________________________________________|     \ 
# /__________)                                        (__________\ 


NAME = cub3D
MINILIBX_D = ./inc/minilibx_linux
MINILIBX = $(MINILIBX_D)/libmlx.a
LIBFT_D = ./inc/libft
LIBFT = $(LIBFT_D)/libft.a
SRCS_D = ./src
INCLUDES = ./inc

#source files
SRC = $(SRCS_D)/main.c \
	$(SRCS_D)/init.c \
	$(SRCS_D)/render.c \
	$(SRCS_D)/events.c \
	$(SRCS_D)/clean.c \
	$(SRCS_D)/utils.c

#		   ________________________________________________
#  _______|                                               |_______
# \       |                FLAGS & COMMANDS               |      /
#  \      |                                               |     /
#  /      |_______________________________________________|     \ 
# /__________)                                        (__________\ 

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MINILIBX_FLAGS = -L$(MINILIBX_D) -lmlx -lXext -lX11 -lm
HEADER = -I$(INCLUDES) -I$(MINILIBX_D) -I$(LIBFT_D)
RM = rm -f
VAL = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

#          ________________________________________________
# ________|                                               |_______
# \       |                    LIB RULES                  |      /
#  \      |                                               |     /
#  /      |_______________________________________________|     \ 
# /__________)                                        (__________\ 

all: $(NAME) 

$(NAME): $(SRC) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(HEADER) $(SRC) $(LIBFT) $(MINILIBX_FLAGS) -o $(NAME)
	@echo "$(BGRN)✨Compilation completed✨"

$(LIBFT):
	@make -C $(LIBFT_D)	
	@echo "$(BGRN)✨libft compilation completed✨"

$(MINILIBX):
	@if [ ! -d "$(MINILIBX_D)" ]; then \
	@echo "$(BGRN)Cloning MiniLibX..."; \
	git clone https://github.com/42Paris/minilibx-linux.git $(MINILIBX_D); \
	fi
	@$(MAKE) -C $(MINILIBX_D)

val: all
	@$(VAL) ./$(NAME)


#          ________________________________________________
# ________|                                               |_______
# \       |                  CLEAN RULES                  |      /
#  \      |                                               |     /
#  /      |_______________________________________________|     \ 
# /__________)                                        (__________\ 

#remove .o
clean:
	@make clean -C $(LIBFT_D)
	@make clean -C $(MINILIBX_D)
	@echo "$(BMAG)✨Objects removed $(BGRN)successfully✨"

#clean and remove
fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS) $(MINILIBX)
	@make fclean -C $(LIBFT_D)
	@rm -rf $(MINILIBX_D)
	@echo "$(BMAG)✨Program removed $(BGRN)successfully✨"

#remake
re: fclean
	make all
	@echo "$(BMAG)✨Re-compile was $(BGRN)successfull✨"

#          ________________________________________________
# ________|                                               |_______
# \       |                  HELP RULES                   |      /
#  \      |                                               |     /
#  /      |_______________________________________________|     \ 
# /__________)                                        (__________\ 

#help
help:
	@echo "✳$(BMAG) make      $(BWHI)-> $(BMAG)compiles the lib"
	@echo "$(BWHI)✳$(BMAG) clean    $(BWHI) -> $(BMAG)removes all objects"
	@echo "$(BWHI)✳$(BMAG) fclean    $(BWHI)-> $(BMAG)removes all objects plus the program"
	@echo "$(BWHI)✳$(BMAG) re        $(BWHI)-> $(BMAG)removes all objects plus the program and recompiles the lib"

#Phony targets to avoid clashes
.PHONY: all clean fclean re help

#          ________________________________________________
# ________|                                               |_______
# \       |                    COLORS                     |      /
#  \      |                                               |     /
#  /      |_______________________________________________|     \ 
# /__________)                                        (__________\ 

#color list for foreground
#bash -c 'for c in {0..255}; do tput setaf $c; tput setaf $c | cat -v; echo =$c; done'

BLA		:= $(echo "u001b[30m")
RED		:= $(echo "\u001b[31m")
GRN		:= $(echo "\u001b[32m")
YEL		:= $(echo "\u001b[33m")
BLU		:= $(echo "\u001b[34m")
MAG		:= $(echo "\u001b[35m")
CYA		:= $(echo "\u001b[36m")
WHI		:= $(echo "\u001b[37m")
GRE		:= $(echo "\u001b[0m")
BBLA	:= $(echo "\u001b[30;1m")
BRED 	:= $(echo "\u001b[31;1m")
BGRN	:= $(echo "\u001b[32;1m")
BYEL	:= $(echo "\u001b[33;1m")
BBLU	:= $(echo "\u001b[34;1m")
BMAG	:= $(echo "\u001b[35;1m")
BCYA	:= $(echo "\u001b[36;1m")
BWHI	:= $(echo "\u001b[37;1m")
Reset	:= $(echo "\u001b[0m")
