# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnoirot <lnoirot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 15:31:28 by lnoirot           #+#    #+#              #
#    Updated: 2022/03/12 22:33:57 by lnoirot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES	:

NAME	=	pipex
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -MMD -g3
RM		=	rm -rf

INC_PATH	=	./inc
INCLUDES	=	-I$(INC_PATH)

OBJ_PATH	=	obj/

SRCS_PATH 		=	srcs
PARSING_PATH	=	parsing/
UTILS_PATH		=	utils/
EXEC_PATH		=	exec/

PARSING_LST		=	$(addprefix $(PARSING_PATH), \
									parsing.c \
					)

EXEC_LST		=	$(addprefix $(EXEC_PATH), \
									exec.c \
					)

UTILS_LST		=	$(addprefix $(UTILS_PATH), \
									ft_putstr_fd.c \
									ft_strlen.c \
									ft_memset.c \
									ft_split.c \
									ft_strncmp.c \
									ft_strdup.c \
									free_str_table.c \
									ft_strrchr.c \
									ft_strjoin.c \
					)

SRCS			=	$(addprefix $(SRCS_PATH), \
									main.c \
									$(PARSING_LST) \
									$(UTILS_LST) \
									$(EXEC_LST) \
					)

SRCS_LIST		= main.c \
					$(PARSING_LST) \
					$(UTILS_LST) \
					$(EXEC_LST)

OBJS	=	$(addprefix $(OBJ_PATH), $(SRCS_LIST:.c=.o))

$(OBJ_PATH)%.o:		$(SRCS_PATH)/%.c
					$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

DEPS	=	$(OBJS:.o=.d)

all:	
			@mkdir -p obj obj/parsing obj/utils obj/exec
			$(MAKE) ${NAME}

${NAME}:	$(OBJS)
		$(CC) $(OBJS) -o $(NAME)
		@echo "pipex is compiled"

clean:	
		$(RM) $(OBJS)
		$(RM) $(DEPS)
		@echo "Cleaned .o !"

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(OBJ_PATH)
			$(RM) $(DEPS)
			@echo "All cleaned !"

run:		$(NAME)
			./pipex

vg:			$(NAME)
			valgrind --track-origins=yes ./pipex

re:			fclean all

.PHONY : all clean libft run vg

-include $(DEPS)