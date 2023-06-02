#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <sys/stat.h>
# include <sys/time.h> 
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../get_next_line/get_next_line.h"
# include "libft.h"
# include <stddef.h>
# include "../mlx_linux/mlx.h"

# define DP printf("%s %d\n", __FILE__, __LINE__);

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

# define IMG_SIZE  64
# define WAIT	80
# define SUCCESS 0
# define FAILURE 1
# define ERROR -1
# define ERRBER "Error extension not .ber"
# define ERREXIT "Error exit not accessible"
# define ERREDGES "Error edge"
# define ERRREC " This is not a rectangle"
# define ERRPLAYER " Error Player"
# define ERRCHARS "One of the characters \"0, 1, P, C, E\" is missing.\n"
# define ERROTHER "Other Error"


typedef struct s_map
{
    int     fd;
    int     line_count;
    size_t line_len;
    int     count_p;
    int     count_e;
    int     count_c;
	char    *path;
    char    **map;
    int     can_exit;
    int     collected;
	int		enemy_kill;
}             t_map;

typedef struct s_img
{
	int		cicle;
	void	*mlx_img;
	int		width;
	int		height;
	int		line_length;
	void	*wall;
	void	*exit_l;
	void	*sea;
	void	*player_up;
	void	*player_down;
	void	*player_left;
	void	*player_right;
	void	*yellow_ping;
	void	*enemy;
	char	*img_type;
	char	**tab_img;
	char	*list_adress;
	char	*yellow_ping_adress;
	char	*enemy_adress;
	char	**tab_img_enemy;
	char	**tab_img_yellow_ping;
	char	*img_adress;
	}	        t_img;

typedef struct s_data
{
	char	direction;
	int		check_exit;
	void	*mlx;
	void	*win;
	int		steps_count;
	int		count_zero;
	int		p_i;
	int		p_j;
	int		e_i;
	int		e_j;
	int		i;
	int		j;
	int		win_height;
	int		win_width;
	t_img	img;
	t_map	map;
}				t_data;

# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define RESET "\033[0m"

# define TITRE "U-42 STRIKE BOAT"
# define SEA "assets/xpm/Sea64.xpm"
# define EXIT "assets/xpm/Exit64.xpm"
# define WALL "assets/xpm/Wall64.xpm"
# define ENEMY1 "assets/xpm/Enemy164.xpm"
# define ENEMY2 "assets/xpm/Enemy264.xpm"
# define ENEMY3 "assets/xpm/Enemy364.xpm"
# define ENEMY4 "assets/xpm/Enemy464.xpm"
# define ENEMY5 "assets/xpm/Enemy564.xpm"
# define YELLOW1 "assets/xpm/yellow_ping164.xpm"
# define YELLOW2 "assets/xpm/yellow_ping264.xpm"
# define YELLOW3 "assets/xpm/yellow_ping364.xpm"
# define YELLOW4 "assets/xpm/yellow_ping464.xpm"
# define YELLOW5 "assets/xpm/yellow_ping564.xpm"
# define PLAYER_UP "assets/xpm/jpj_up64.xpm"
# define PLAYER_DOWN "assets/xpm/jpj_down64.xpm"
# define PLAYER_RIGHT "assets/xpm/jpj_right64.xpm"
# define PLAYER_LEFT "assets/xpm/jpj_left64.xpm"
# define ENEMY_LIST "srcs/02_Graphics/enemy_list2.txt"
//# define ENEMY_LIST "srcs/02_Graphics/yellow_ping_list.txt"
# define YELLOW_PING_LIST "srcs/02_Graphics/yellow_ping_list2.txt"


/* Init Parsing*/
int 	count_line_number(char *path);
void    ft_free(char **tab);
void    get_map(int row, int column, int i, t_data *data);
void    create_map(char *path, t_data *data);
void    init_map(t_data *data);
void    init_player(t_data *data);
void	init_enemy(t_data *data);
int 	render(t_data *data);

/* Errors*/
int		check_extension(char *path);
int		check_chars(t_data *data);
int		check_top_bot(int row, char **map);
int		check_edges(int row, char **map);
int		check_rectangle(t_data *data);



void    error_msg(char *str, t_data *data);
void	check_around_x(t_data *data);
void 	count_zero(t_data *data);
int		check_around_exit(t_data *data);
int		check_path(t_data *data);
void    parse_chars(t_data *data, int width, int i, int j);
int 	check_map(t_data *data);

/* Graphics*/
int     init_window(t_data *data);
void    init_images(t_data *data);
void    loop_images(t_data data);
void    destroy_images(t_data *data);
void    ft_free_img(t_data *data);
void    destroy(t_data *data);

/*Events*/
int 	handle_resize(t_data *data);
int 	handle_keypress(int keysym, t_data *data);
int 	handle_btnrealease(t_data *data);
int 	check_next_tile(t_data *data, char direction, char tile);
int 	win_game(t_data *data);
void    collect_coins(t_data *data, char direction);
void    turn_ship(t_data *data, int width, int i);
void    move_player(t_data *data, char direction);
void    move_msg(t_data *data);
void    loss_move_msg(t_data *data);
void    player_lose(t_data *data);
void	compute_enemy_move_up_down(t_data *data);
void	compute_enemy_move_right_left(t_data *data);

/*Bonus*/
char  	**create_img_tab(t_data *data, char *list_adress);
char    **fill_tab(t_data *data, char *list_adress);
void    get_img_adress(t_data *data);
void    mlx_wait(t_data *data);
int     size_of_tab(char *list_adress);

void	free_all(t_data *data);

#endif
