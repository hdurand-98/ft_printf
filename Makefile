NAME		=	libftprintf.a
DIRSRC		=	./
DIROBJ		=	./
INCLUDE		=	./
SRC			=	ft_itoa_base.c ft_putnbr.c ft_putstr.c ft_printf.c ft_atoi.c ft_code.c ft_code2.c ft_putils.c ft_putnbr_base.c

OBJB		=	$(SRCB:.c=.o)
OBJ			=	$(SRC:.c=.o)
OBJS		=	$(OBJ:%=$(DIROBJ)/%)

CFLAGS		=	-Wall -Wextra -Werror

CC			=	gcc
RM			=	rm -f


$(NAME)	:		$(OBJ)
				ar rc $(NAME) $(OBJS) 
				ranlib $(NAME)

clean	:
				cd $(DIROBJ) && $(RM) $(OBJ) $(OBJB)

all		:		$(NAME)

fclean	:		clean
				$(RM) $(NAME)

re		:		fclean all

.PHONY	:		all clean fclean re bonus

%.o		:		$(DIRSRC)/%.c
				$(CC) $(CFLAGS) -I$(INCLUDE) -o $(DIROBJ)/$@ -c $<
