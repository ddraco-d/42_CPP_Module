# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddraco <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/07 23:20:33 by ddraco            #+#    #+#              #
#    Updated: 2021/01/26 17:49:13 by ddraco           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= FragTrap.cpp main.cpp ScavTrap.cpp ClapTrap.cpp NinjaTrap.cpp SuperTrap.cpp
OBJS			= $(SRCS:.cpp=.o)

CXX				= clang++ --std=c++98
RM				= rm -f
CXXFLAGS		= -Wall -Wextra -Werror

NAME			= a.out

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re test