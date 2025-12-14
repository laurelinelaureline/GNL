# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laureline.pierre <laureline.pierre@lear    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/10 19:58:41 by laureline.p       #+#    #+#              #
#    Updated: 2025/12/14 20:13:46 by laureline.p      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = get_next_line.a

SOURCES = get_next_line_utils.c \
    
     
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -D BUFFER_SIZE=42

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

.PHONY: all clean fclean re bonus


    
