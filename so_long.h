/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:00:44 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/27 03:55:21 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <X11/keysym.h>

# define NAME			"So Long"
# define HEIGHT			920
# define WIDTH			1080
// # define HEIGHT			480
// # define WIDTH			720

# define TYPE_ENTRY		'P'
# define TYPE_EXIT		'E'
# define TYPE_WALL		'1'
# define TYPE_EMPTY		'0'
# define TYPE_ITEM		'C'
# define TYPES			"PE10C"

# define TILE_SIZE			64
# define PLAYER_SIZE		32
# define ASSETS_COUNT		4

typedef long long			t_ll;
typedef unsigned long long	t_ull;
typedef unsigned int		t_ui;

typedef enum e_bool {
	FALSE,
	TRUE
}	t_bool;

typedef enum e_mob_type {
	MOC_CREATURE
}	t_mob_type;

typedef enum e_direction {
	DIR_UP = 3,
	DIR_DOWN = 0,
	DIR_LEFT = 1,
	DIR_RIGHT = 2
}	t_direction;

typedef struct s_vec2 {
	int	x;
	int	y;
}	t_vec2;

typedef struct s_list_vec2 {
	int					x;
	int					y;
	struct s_list_vec2	*next;
}	t_list_vec2;

typedef struct s_frame {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_size;
	int		width;
	int		height;
	int		endian;
}	t_frame;

typedef struct s_asset {
	t_frame	*frames;
	int		tot_frames;
}	t_asset;

typedef struct s_tile {
	char	type;
	int		asset_idx;
	int		curr_frame;
	t_bool	has_changed;
	int		item_idx;
}	t_tile;

typedef struct s_mobs {
	t_mob_type		type;
	t_vec2			pos;
	int				health;
	struct s_mobs	*next;
}	t_mobs;

typedef struct s_data {
	void		*mlx;
	void		*mlx_win;
	t_asset		*assets;

	t_tile		**map;
	int			map_width;
	int			map_height;

	t_vec2		player;
	t_direction	player_direction;
	t_bool		can_move;
	t_asset		*player_assets;
	t_tile		player_tile;

	t_tile		*items;
	int			items_collected;
	int			items_count;
	t_mobs		*mobs;

	t_vec2		entry;
	t_vec2		exit;
	t_bool		can_exit;

	t_ull		moves;
	t_ull		frames;
}	t_data;

enum e_mlx_events {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum e_mlx_masks {
	MASK_NO_MASK = 0L,
	MASK_KEY_PRESS = 1L<<0,
	MASK_KEY_RELEASE = 1L<<1,
	MASK_BUTTON_PRESS = 1L<<2,
	MASK_BUTTON_RELEASE = 1L<<3,
	MASK_ENTER_WINDOW = 1L<<4,
	MASK_LEAVE_WINDOW = 1L<<5,
	MASK_MOUSE_MOVE = 1L<<6,
	MASK_MOUSE_MOVE_HINT = 1L<<7,
	MASK_BUTTON1_MOTION = 1L<<8,
	MASK_BUTTON2_MOTION = 1L<<9,
	MASK_BUTTON3_MOTION = 1L<<10,
	MASK_BUTTON4_MOTION = 1L<<11,
	MASK_BUTTON5_MOTION = 1L<<12,
	MASK_BUTTON_MOTION = 1L<<13,
	MASK_KEYMAP_STATE = 1L<<14,
	MASK_EXPOSE = 1L<<15,
	MASK_VISIBILITY_CHANGE = 1L<<16,
	MASK_DESTROY = 1L<<17,
	MASK_RESIZE_REDIRECT = 1L<<18,
	MASK_SUBSTRUCTURE_NOTIFY = 1L<<19,
	MASK_SUBSTRUCTURE_REDIRECT = 1L<<20,
	MASK_FOCUS_CHANGE = 1L<<21,
	MASK_PROPERTY_CHANGE = 1L<<22,
	MASK_COLORMAP_CHANGE = 1L<<23,
	MASK_OWNER_GRAB_BUTTON = 1L<<24
};

/* ******************************************* */
/* === ->>  Map arrangement functions  <<- === */
/* ******************************************* */

void	ft_arrange_map(t_data *data);
void	ft_arrange_tile(t_data *data, t_vec2 point);

/* ****************************************** */
/* === ->>  Assets loading functions  <<- === */
/* ****************************************** */

int		ft_load_assets(t_data *data);
int		ft_load_player(t_data *data);
int		ft_load_simple_asset(t_data *data, int idx, char *paths);
int		ft_load_simple_player_asset(t_data *data, int idx, char *path);

/* *********************************** */
/* === ->>  Drawing functions  <<- === */
/* *********************************** */

void	ft_put_blend_frame(t_data *data, t_frame *drawing,
			t_vec2 point_win, t_vec2 point_offset);
void	ft_put_blend_pixel(t_data *data, t_vec2 point_win,
			t_vec2 point_offset, t_ui color);
void	ft_draw_frame(t_frame *base, t_frame *drawing, t_vec2 point);
void	ft_draw_pixel(t_frame *frame, t_vec2 point, t_ui color);
void	ft_put_player(t_data *data);
void	ft_draw_rect(t_frame *frame, t_vec2 start, t_vec2 size, t_ui color);
void	ft_put_tile(t_data *data, t_vec2 point);
void	ft_put_tiles(t_data *data);
void	ft_put_item(t_data *data, t_vec2 point, int item_tile_idx);

/* ******************************** */
/* === ->>  Game functions  <<- === */
/* ******************************** */

int		ft_game_init(t_data *data);
int		ft_game_keydown(int keycode, t_data *data);
int		ft_game_loop(t_data *data);
int		ft_game_quit(t_data *data);
void	ft_move_player(t_data *data, t_direction direction);

/* ******************************* */
/* === ->>  get_next_line  <<- === */
/* ******************************* */

char	*get_next_line(int fd);

/* *********************************** */
/* === ->>  Parsing functions  <<- === */
/* *********************************** */

t_bool	ft_check_dfs(t_data *data, t_vec2 curr, t_vec2 to, t_list_vec2 **list);
int		ft_check_map(t_data *data);
int		ft_check_path(t_data *data);
int		ft_parse_char(t_data *data, char c, int i, int j);
int		ft_parse_height(t_data *data, char *map_path);
int		ft_parse_line(t_data *data, char *line, int i);
int		ft_parse_map(t_data *data, int fd);
int		ft_parse(t_data *data, char *map_path);

/* **************************************** */
/* === ->>  Miscellanous functions  <<- === */
/* **************************************** */

t_ui	ft_argb(int a, int r, int g, int b);
t_ui	ft_blend(t_ui a, t_ui b);
void	*ft_calloc(size_t count, size_t size);
t_ui	ft_color_progression(int i, int max);
void	ft_data_init(t_data *data);
t_ui	ft_grad_color(int i, int max, t_ui color1, t_ui color2);
void	ft_list_vec2_add_front(t_list_vec2 **list, t_vec2 vec);
t_bool	ft_list_vec2_contains(t_list_vec2 *list, t_vec2 vec);
int		ft_error(t_data *data, char *str);
void	ft_free_assets(t_data *data);
void	ft_free_list_vec2(t_list_vec2 **list);
void	ft_free_map(t_tile **map);
void	ft_free_player(t_data *data);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		ft_str_contains(char *str, char c);
size_t	ft_strlen(char *str);
void	ft_free_items(t_tile *items);

#endif