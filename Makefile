# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/22 15:38:18 by kahoumou          #+#    #+#              #
#    Updated: 2025/08/22 15:38:40 by kahoumou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftcpp

CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -Iincludes

SRCS	= srcs/StringUtils.cpp
OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
