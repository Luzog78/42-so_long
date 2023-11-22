/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:00:44 by ysabik            #+#    #+#             */
/*   Updated: 2023/11/22 10:28:00 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <X11/keysym.h>

# define HEIGHT 480 // 920
# define WIDTH 720 // 1080
# define NAME "So Long"

typedef long long			t_ll;
typedef unsigned long long	t_ull;

typedef enum e_bool {
	FALSE,
	TRUE
}	t_bool;

typedef struct s_vec2 {
	int	x;
	int	y;
}	t_vec2;

typedef struct s_frame {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		width;
	int		endian;
}	t_frame;

typedef enum e_mob_type {
	CREATURE
}	t_mob_type;

typedef struct s_mobs {
	t_mob_type		type;
	t_vec2			pos;
	int				health;
	struct s_mobs	*next;
}	t_mobs;

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	t_frame	frame;

	char	**map;
	int		map_width;
	int		map_height;

	t_vec2	player;
	t_bool	can_move;

	t_mobs	*mobs;

	t_vec2	enter;
	t_vec2	exit;
	t_bool	can_exit;

	t_ull	moves;
	t_ull	frames;
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

/* *************************************** */
/* === ->>  Data struct functions  <<- === */
/* *************************************** */

void	ft_data_init(t_data *data);

/* *********************************** */
/* === ->>  Drawing functions  <<- === */
/* *********************************** */

void	ft_draw_pixel(t_frame *frame, t_vec2 point, int color);
void	ft_draw_rect(t_frame *frame, t_vec2 start, t_vec2 size, int color);

/* ******************************** */
/* === ->>  Game functions  <<- === */
/* ******************************** */

void	ft_game_init(t_data *data);
int		ft_game_keydown(int keycode, t_data *data);
int		ft_game_loop(t_data *data);
int		ft_game_quit(t_data *data);

/* **************************************** */
/* === ->>  Miscellanous functions  <<- === */
/* **************************************** */

int		ft_argb(int a, int r, int g, int b);
int		ft_color_progression(int i, int max);
int		ft_grad_color(int i, int max, int color1, int color2);
int		ft_max(int a, int b);
int		ft_min(int a, int b);

#endif