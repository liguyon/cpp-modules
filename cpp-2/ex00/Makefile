# Compiler
###########################
CPPC		= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

CPPLFLAGS	=
# Debug
CPPFLAGS 	+= -g -DDEBUG


# Project files
###########################
SRCDIR	= src
OBJDIR	= build
OBJ		= $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))
NAME	= a.out
SRC		= main.cpp \
		  Fixed.cpp \


# Build
###########################
.PHONY:	all clean fclean re debug

all: $(NAME)

$(NAME): $(OBJ)
	$(CPPC) $(CPPFLAGS) -o $(NAME) $^ $(CPPLFLAGS)

clean:
	rm -rf $(OBJDIR)

fclean:	clean
	rm -f $(NAME)

re:	fclean all


# project srcs build
###########################
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CPPC) $(CPPFLAGS) -o $@ -c $<
