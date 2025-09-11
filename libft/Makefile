# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/25 12:13:34 by ddo-carm          #+#    #+#              #
#    Updated: 2024/11/05 16:05:51 by ddo-carm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#		   ________________________________________________        
#  _______|                                               |_______
# \       |                 NAMES & PATHS                 |      /
#  \      |                                               |     /
#  /      |_______________________________________________|     \ 
# /__________)                                        (__________\ 


NAME = libft.a

HEADER_PATH = ./libft.h
BASIC_PATH = ./basic
PRINTF_PATH = ./printf
GNL_PATH = ./gnl
EXT_PATH = ./extras
DPRINTF_PATH = ./dprintf

#source files
SRCS = $(addprefix $(BASIC_PATH)/, ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
		ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
		ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_strtrim.c ft_split.c \
		ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c)

EXT_SRCS = $(addprefix $(EXT_PATH)/, free_arrays.c free_matrix.c errors.c \
			close_pipe.c ft_atoi_base.c ft_is_space.c ft_atol.c \
			ft_is_directory.c )

PRINTF_SRCS = $(addprefix $(PRINTF_PATH)/, ft_printf.c ft_printf_utils.c \
			ft_hex_utils.c)

GNL_SRCS = $(addprefix $(GNL_PATH)/, get_next_line.c get_next_line_utils.c \
			get_next_line_bonus.c get_next_line_utils_bonus.c)

DPRINTF_SRCS = $(addprefix $(DPRINTF_PATH)/, ft_dprintf.c ft_dprintf_utils.c \
				ft_hex_utils.c)

#object files
OBJ = $(SRCS:.c=.o)
EXT_OBJ = $(EXT_SRCS:.c=.o)
PRINTF_OBJ = $(PRINTF_SRCS:.c=.o)
GNL_OBJ = $(GNL_SRCS:.c=.o)
DPRINTF_OBJ = $(DPRINTF_SRCS:.c=.o)

#		   ________________________________________________
#  _______|                                               |_______
# \       |                FLAGS & COMMANDS               |      /
#  \      |                                               |     /
#  /      |_______________________________________________|     \ 
# /__________)                                        (__________\ 

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
AR = ar rcs

#          ________________________________________________
# ________|                                               |_______
# \       |                    LIB RULES                  |      /
#  \      |                                               |     /
#  /      |_______________________________________________|     \ 
# /__________)                                        (__________\ 


all: $(NAME)

#compile the lib
$(NAME): $(OBJ) $(EXT_OBJ) $(PRINTF_OBJ) $(GNL_OBJ) $(DPRINTF_OBJ)
	$(AR) $(NAME) $(OBJ) $(EXT_OBJ) $(PRINTF_OBJ) $(GNL_OBJ) $(DPRINTF_OBJ)
	@echo "$(BGRN)✨Compilation completed✨"

#compile .o files
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BMAG)Compiling..."

#          ________________________________________________
# ________|                                               |_______
# \       |                  CLEAN RULES                  |      /
#  \      |                                               |     /
#  /      |_______________________________________________|     \ 
# /__________)                                        (__________\ 

#remove .o
clean:
	$(RM) $(OBJ) $(EXT_OBJ) $(PRINTF_OBJ) $(GNL_OBJ) $(DPRINTF_OBJ)
	@echo "$(BMAG)✨Objects removed $(BGRN)successfully✨"


#clean and remove
fclean: clean
	$(RM) $(NAME)
	@echo "$(BMAG)✨Program removed $(BGRN)successfully✨"
	
#remake
re: fclean all
	@echo "$(BMAG)✨Re-compile was $(BGRN)successfull✨"

#          ________________________________________________
# ________|                                               |_______
# \       |                  HELP RULES                   |      /
#  \      |                                               |     /
#  /      |_______________________________________________|     \ 
# /__________)                                        (__________\ 

#help
help:
	@echo "✳$(BMAG) make  $(BWHI)    -> $(BMAG)compiles the lib"

	@echo "$(BWHI)✳$(BMAG) clean    $(BWHI) -> $(BMAG)removes all objects"
	@echo "$(BWHI)✳$(BMAG) fclean    $(BWHI)-> $(BMAG)removes all objects plus the program"
	@echo "$(BWHI)✳$(BMAG) re        $(BWHI)-> $(BMAG)removes all objects plus the program and recompiles the lib"

#Phony targets to avoid clashes
.PHONY: all clean fclean re

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
