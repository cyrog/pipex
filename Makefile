# COMPILATION FLAGS

CFLAGS	=	-Wall -Wextra -Werror $(IFLAGS)

IFLAGS	=	$(addprefix -I,$(IDIR))

# DIRECTORIES

DIR		=	./
ODIR	=	objs/
LDIR	=	libft/
IDIR	=	includes/
SDIR	=	./srcs/

# SOURCES

SRC		=	pipex.c		\
			cmd_path.c	\
			error.c		\

LSRC	=		ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \

SRCS	=	$(addprefix $(SDIR), $(SRC))
LSRCS	=	$(addprefix $(LDIR), $(LSRC))

# OBJECTS

OBJS	=	$(addprefix $(ODIR), $(OBJ))
LOBJS	=	$(addprefix $(ODIR), $(LOBJ))

OBJ		=	$(SRC:.c=.o)
LOBJ	=	$(LSRC:.c=.o)

# COMMANDS

CC		=	gcc
RM		=	rm -rf
RMDIR	=	rmdir
MKDIR	=	mkdir

# NAME

NAME	=	pipex
LNAME	=	libft

# MANDATORY

all:		$(NAME)

$(NAME):	$(ODIR) $(LOBJS) $(OBJS)
	@$(CC) $(IFLAGS) $(OBJS) $(LOBJS) -o $(NAME)


clean:
	@$(RM) $(addprefix $(ODIR), $(LOBJS:$(LDIR)%=%))
	@$(RM) $(addprefix $(ODIR), $(LOBJS:$(LDIR)%=%))
	@if [ -d "$(ODIR)" ]; then rm -rf $(ODIR); fi

fclean: clean
		$(RM) $(NAME)

re:		fclean all

# EXTRA

$(ODIR):
		@$(MKDIR) $(ODIR)

# IMPLICIT

$(ODIR)%.o:	$(LDIR)%.c
					@$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

$(ODIR)%.o:	$(SDIR)%.c
					@$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

.PHONY: all, clean, fclean, re
