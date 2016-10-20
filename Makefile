CC		=	g++

RM		=	rm -f

VPATH	=	src \
			tests

SRCS	=	Network.cpp

SRCM	=	main.cpp

SRCT	=	main_test.cpp

OBJS	=	$(SRCS:.cpp=.o)

OBJM	=	$(SRCM:.cpp=.o)

OBJT	=	$(SRCT:.cpp=.o)

NAME	=	sniffer

NAMET	=	sniffer_test

LXXDFLAGS	=		

CXXFLAGS	=	-Wall -Wextra -I./include -std=c++11

CGREEN	=	"\033[0;32m"
CNOCOLOR =	"\033[0m"
CRED	=	"\033[0;31m"

all:		$(NAME)

test: $(NAMET)

$(NAME):	$(OBJS) $(OBJM)
	@echo "[" $(CGREEN) "Compiling sources" $(CNOCOLOR) "]"
	@$(CC) $(LDFLAGS) $(OBJS) $(OBJM) -o $(NAME)
	@echo "------>" $(CGREEN) $(NAME) "created" $(CNOCOLOR)

$(NAMET): $(OBJS) $(OBJT)
	@echo "[" $(CGREEN) "Compiling sources for test" $(CNOCOLOR) "]"
	@$(CC) $(LDFLAGS) $(OBJS) $(OBJT) -o $(NAMET)
	@echo "------>" $(CGREEN) $(NAMET) "created" $(CNOCOLOR)

clean:
	@echo "[" $(CRED) "Remove .o files" $(CNOCOLOR) "]"
	@$(RM) $(OBJS) $(OBJM) $(OBJT)

fclean: clean
	@echo "[" $(CRED) "Remove" $(NAME) / $(NAMET) $(CNOCOLOR) "]"
	@$(RM) $(NAME) $(NAMET)

re:	fclean all



.PHONY: all clean fclean re test
