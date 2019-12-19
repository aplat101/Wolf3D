# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/03 16:28:38 by aplat        #+#   ##    ##    #+#        #
#    Updated: 2019/12/19 13:36:05 by aplat       ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a

COMP = ft_memset.c ft_memcpy.c ft_memccpy.c \
	   ft_bzero.c ft_memmove.c ft_memchr.c \
	   ft_memcmp.c ft_strlen.c ft_strdup.c \
	   ft_strcpy.c ft_strncpy.c ft_strcat.c \
	   ft_strncat.c ft_strlcat.c ft_strchr.c \
	   ft_strrchr.c ft_strstr.c ft_strnstr.c \
	   ft_strcmp.c ft_strncmp.c ft_atoi.c \
	   ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	   ft_isascii.c ft_isprint.c ft_toupper.c \
	   ft_tolower.c ft_memalloc.c ft_memdel.c \
	   ft_strnew.c ft_strdel.c ft_strclr.c \
	   ft_striter.c ft_striteri.c ft_strmap.c \
	   ft_strmapi.c ft_strequ.c ft_strnequ.c \
	   ft_strsub.c ft_strjoin.c ft_strtrim.c \
	   ft_strsplit.c ft_itoa.c ft_putchar.c \
	   ft_putstr.c ft_putendl.c ft_putnbr.c \
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	   ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c \
	   ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	   ft_lstmap.c ft_islower.c ft_isupper.c \
	   ft_str_is_alpha.c ft_str_is_lowercase.c \
	   ft_str_is_numeric.c ft_str_is_printable.c \
	   ft_str_is_uppercase.c ft_strcapitalize.c \
	   ft_strlowcase.c ft_strupcase.c ft_countwords.c \
	   ft_wordlen.c ft_power.c \
	   get_next_line.c\
	   \
	   aff_a.c ft_countdown.c hello.c maff_alpha.c\
	   aff_first_param.c aff_last_param.c maff_revalpha.c\
	   only_a.c only_z.c aff_z.c\
	   \
	   repeat_alpha.c search_and_replace.c ulstr.c rot_13.c rotone.c\
	   first_word.c ft_swap.c rev_print.c ft_powf.c\


HEAD = -I libft.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra

OBJS = $(COMP:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(HEAD) -c $(COMP) 

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME) 

re: fclean all

norme:
	@norminette $(COMP)

.PHONY: all re clean fclean, norme
