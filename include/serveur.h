/*
** serveur.h for plaza in /home/wautel_l/rendu/PSU_2014_zappy/serveur
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Tue May 12 15:10:26 2015 lucie wautelet
** Last update Sun Jul  5 16:48:54 2015 lucie wautelet
*/

# include		<stdlib.h>
# include		<stdio.h>
# include		<stdarg.h>
# include	      	<stdbool.h>
# include		<netdb.h>
# include		<sys/types.h>
# include		<sys/time.h>
# include		<sys/socket.h>
# include		<sys/select.h>
# include		<netinet/in.h>
# include		<unistd.h>
# include		<fcntl.h>
# include		<netinet/in.h>
# include		<arpa/inet.h>
# include		<string.h>
# include		<signal.h>
# include		<errno.h>
# include		<time.h>


#define				MAX_CLIENTS 48
#define				BUFFER_SIZE 1000
# define			MAX_CHANNELS 50

typedef struct			s_egg {
  int				team;
  float				beg;
  float				end;
  int				id;
  struct s_egg			*next;
}				t_egg;

typedef struct			s_buffer {
  int				id;
  int				used;
  char				*buffer;
  float				end;
  float				beg;
  struct s_buffer		*prev;
  struct s_buffer		*next;
}				t_buffer;

typedef struct			s_server {
  t_egg				*egg;
  int				port;
  struct sockaddr_in		server_sin;
  char				*team[MAX_CHANNELS];
  int				nbteam[MAX_CHANNELS];
  int				width;
  int				height;
  int				client;
  int				totteam;
  int				delay;
  int				***map;
  char				*stone[7];
  t_buffer			*list;
  char				*instr[11];
  int				graph;
  int				(*elevation[7])(struct s_server *, int, int, int);
}				t_server;

typedef struct			s_info_c {
  int				socket;
  char				*team;
  char				*username;
  int				inventaire[7];
  float				pv;
  char				*buffer;
  // double			begin;
  float				end;
  int				level;
  int				x;
  int				y;
  int				direction;
}				t_info_c;

extern int			socket_s;
extern t_info_c			socket_com[MAX_CLIENTS];

int				handl_team(char *, t_server *, int);
void				handler_s(t_server *, char *, int);
void				select_s(t_server *, fd_set *, struct timeval *);
void				my_init_serveur(t_server *);
void				create_socket_s(t_server *);
void				add_socket(int, struct sockaddr_in *, t_server *);
int				socket_com_size();
void				my_init_verifarg(int *);
int				my_strlenint(int *);
void				my_perror(char *);
void				handl_write(int, char *);
char				*my_cutn(char *, char);
void				my_putchar(char, int);
int				my_putnbr(int, int);
char				*my_reverse(char *);
void				handl_writeint(int, int , int);
void				my_stock_larg(char *, t_server *, char, int *);
void				my_stock_timeplay(char *, t_server *, char, int *);
void				my_stock_team(char **, int, t_server *, int *);
void				my_verif_second(char **, int *, t_server *);
void				my_init_arg(char **, t_server *);
void				my_full_map(t_server *);
void				my_gener_map(t_server *);
void				my_print_map(t_server *);
void				my_gener_inv(t_server *);
t_buffer			*stock_list(t_server *s_info, char *buffer, int n);
float				definetim(char *, t_server *);
int				check_victory(t_server *);
int				check_first(t_server *, int, int, int);
int				check_second(t_server *, int, int, int);
int				check_third(t_server *, int, int, int);
int				check_fourth(t_server *, int, int, int);
int				check_fifth(t_server *, int, int, int);
int				check_sixth(t_server *, int, int, int);
int				check_seventh(t_server *, int, int, int);
void				verif_cours(t_server *, char *, int);
t_buffer			*delete_in_list(t_buffer *, int);
t_buffer			*stock_list_cours(t_server *, char *, int);
t_buffer			*check_next(t_buffer *, int, t_server *);
t_buffer			*parse_list(t_server *);
t_buffer			*list_parc(t_buffer *, int, t_server *);
t_egg				*add_list_egg(t_server *, int, int);
