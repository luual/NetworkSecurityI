CC		=	g++

RM		=	rm -f

VPATH	=	src \
			tests

SRCS	=	Network.cpp \
			Socket.cpp \
			SocketAnalyzer.cpp \
			Thread.cpp

SRCM	=	main.cpp

SRCT	=	main_test.cpp \
			VectorTest.cpp

OBJS	=	$(SRCS:.cpp=.o)

OBJM	=	$(SRCM:.cpp=.o)

OBJT	=	$(SRCT:.cpp=.o)

NAME	=	sniffer

NAMET	=	sniffer_test

LXXDFLAGS	=

CXXFLAGS	=	-Wall -Wextra -I./include -I./src -std=c++11

DXXFLAGS	=	-pthread

CGREEN	=	"\033[0;32m"
CNOCOLOR =	"\033[0m"
CRED	=	"\033[0;31m"

all:		$(NAME)

test: $(NAMET)

$(NAME):	$(OBJS) $(OBJM)
	@echo "[" $(CGREEN) "Compiling sources" $(CNOCOLOR) "]"
	@$(CC) $(LDFLAGS) $(OBJS) $(OBJM) -o $(NAME) $(DXXFLAGS)
	@echo "------>" $(CGREEN) $(NAME) "created" $(CNOCOLOR)

$(NAMET): $(OBJS) $(OBJT)
	@echo "[" $(CGREEN) "Compiling sources for test" $(CNOCOLOR) "]"
	@$(CC) $(LDFLAGS) $(OBJS) $(OBJT) -o $(NAMET) $(DXXFLAGS)
	@echo "------>" $(CGREEN) $(NAMET) "created" $(CNOCOLOR)

clean:
	@echo "[" $(CRED) "Remove .o files" $(CNOCOLOR) "]"
	@$(RM) $(OBJS) $(OBJM) $(OBJT)

fclean: clean
	@echo "[" $(CRED) "Remove" $(NAME) / $(NAMET) $(CNOCOLOR) "]"
	@$(RM) $(NAME) $(NAMET)

re:	fclean all



.PHONY: all clean fclean re test
