##
## Makefile for zappy in /home/wautel_l/rendu/PSU_2014_zappy
##
## Made by lucie wautelet
## Login   <wautel_l@epitech.net>
##
## Started on  Tue May 12 14:52:07 2015 lucie wautelet
## Last update Sun Jul  5 17:21:18 2015 lucie wautelet
##

NAMES	= zappy_server

SRCSS	= serv/main.c \
	  serv/server.c \
	  serv/server2.c \
	  serv/parse_arg.c \
	  serv/obj.c \
	  serv/socket.c \
	  serv/list.c \
	  serv/time.c \
	  serv/team.c \
	  serv/util.c \
	  serv/map.c \
	  serv/inv.c \
	  serv/parse_act.c \
	  serv/parse_sui.c\
	  serv/printfct.c \
	  serv/inv_sui.c\
	  serv/fctserv.c \
	  serv/voir_sui.c \
	  serv/check.c \
	  serv/check_lvl.c\
	  serv/check_lastlvl.c\
	  serv/verif_cours.c\
	  serv/graph.c\
	  serv/act.c\
	  serv/utils.c \
	  serv/graph_sui.c \
	  serv/voir.c \
	  serv/fork.c \
	  serv/fork2.c \
	  serv/map2.c \
	  serv/list2.c \
	  serv/taille.c \
	  lib/my_function.c \
	  lib/my_putnbr.c \
	  lib/my_getnbr_base.c \
	  lib/my_getnbr.c \
	  lib/my_strlen.c \
	  lib/my_putchar.c \
	  lib/my_putstr.c \
	  lib/my_stock_int_in_char.c \
	  lib/my_printf.c \
	  lib/convert_base.c \
	  lib/my_revstr.c \
	  lib/my_sendrcv.c

OBJSS	= $(SRCSS:.c=.o)

NAMEC	= zappy_ai

SRCSC	= client_src/main.cpp \
	  client_src/Parse.cpp \
	  client_src/Network.cpp \
	  client_src/Ia.cpp

OBJSC	= $(SRCSC:.cpp=.o)

NAMEG	= zappy_graphic

SRCSG	= graphic_src/main.cpp\
	  graphic_src/Parse.cpp\
	  graphic_src/Network.cpp\
	  graphic_src/GameEngine.cpp\
	  graphic_src/Managers.cpp\
	  graphic_src/ImageManager.cpp\
	  graphic_src/InputManager.cpp\
	  graphic_src/EventManager.cpp\
	  graphic_src/ViewManager.cpp\
	  graphic_src/Map.cpp\
	  graphic_src/Tile.cpp\
	  graphic_src/Ressource.cpp\
	  graphic_src/Player.cpp\
	  graphic_src/Egg.cpp

OBJSG	= $(SRCSG:.cpp=.o)

SFMLINCLUDE = -I./SFML-1.6/include/

SFMLLIB = -Wl,-L./SFML-1.6/lib -Wl,--rpath=./SFML-1.6/lib/ -lsfml-window -lsfml-graphics -lsfml-system -lsfml-audio

.cpp.o:
	g++ -c $(SFMLINCLUDE) -o $@ $<

all:	$(NAMES) $(NAMEC) $(NAMEG)

$(NAMES): $(OBJSS)
	 gcc -o $(NAMES) $(OBJSS) -Wall -Werror -Wextra

$(NAMEC): $(OBJSC)
	 g++ -o $(NAMEC) $(OBJSC)

$(NAMEG): $(OBJSG)
	 g++ $(SFMLLIB) -o $(NAMEG) $(OBJSG)

clean:
	rm -f $(OBJSS)
	rm -f $(OBJSC)
	rm -f $(OBJSG)

fclean:	clean
	rm -f $(NAMES)
	rm -f $(NAMEC)
	rm -f $(NAMEG)

re:	fclean all
