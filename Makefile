# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 07:59:02 by ysabik            #+#    #+#              #
#    Updated: 2023/11/29 22:47:47 by ysabik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC					= cc
CFLAGS				= -Werror -Wall -Wextra -g -lm -I . \
						-I ./minilibx-linux -L ./minilibx-linux \
						-lmlx_Linux -lXext -lX11
NAME				= so_long
SRC_FILES			= \
						src/arrangement/ft_arrange_map.c \
						src/arrangement/ft_arrange_tile.c \
						src/arrangement/ft_arrange_wall.c \
						\
						src/assets/ft_load_asset.c \
						src/assets/ft_load_assets.c \
						src/assets/ft_load_frame.c \
						src/assets/ft_load_player_asset.c \
						src/assets/ft_load_player_assets.c \
						src/assets/ft_load_simple_asset.c \
						\
						src/drawing/ft_draw_frame.c \
						src/drawing/ft_draw_pixel.c \
						src/drawing/ft_draw_rect.c \
						src/drawing/ft_put_blend_frame.c \
						src/drawing/ft_put_blend_pixel.c \
						src/drawing/ft_put_frame.c \
						src/drawing/ft_put_item.c \
						src/drawing/ft_put_mob.c \
						src/drawing/ft_put_mobs.c \
						src/drawing/ft_put_player.c \
						src/drawing/ft_put_score.c \
						src/drawing/ft_put_tile.c \
						src/drawing/ft_put_tiles.c \
						\
						src/game/ft_game_init.c \
						src/game/ft_game_keydown.c \
						src/game/ft_game_loop.c \
						src/game/ft_game_quit.c \
						src/game/ft_grab_item.c \
						src/game/ft_move_mob.c \
						src/game/ft_move_mobs.c \
						src/game/ft_move_player.c \
						src/game/ft_open_portal.c \
						src/game/ft_post_mob_move.c \
						src/game/ft_post_player_move.c \
						src/game/ft_smooth_mob_move.c \
						src/game/ft_smooth_player_move.c \
						\
						src/gnl/get_next_line.c \
						src/gnl/get_next_line_utils.c \
						\
						src/misc/color/ft_argb.c \
						src/misc/color/ft_blend.c \
						src/misc/color/ft_color_progression.c \
						src/misc/color/ft_grad_color.c \
						\
						src/misc/free/ft_free_assets.c \
						src/misc/free/ft_free_items.c \
						src/misc/free/ft_free_list_vec2.c \
						src/misc/free/ft_free_map.c \
						src/misc/free/ft_free_mobs.c \
						src/misc/free/ft_free_player.c \
						\
						src/misc/libc/ft_calloc.c \
						src/misc/libc/ft_itoa.c \
						src/misc/libc/ft_max.c \
						src/misc/libc/ft_min.c \
						src/misc/libc/ft_put_ull.c \
						src/misc/libc/ft_str_contains.c \
						src/misc/libc/ft_strjoin.c \
						src/misc/libc/ft_strlen.c \
						\
						src/misc/ft_data_init.c \
						src/misc/ft_error.c \
						src/misc/ft_list_vec2_add_front.c \
						src/misc/ft_list_vec2_contains.c \
						src/misc/ft_mobs_add_front.c \
						src/misc/ft_mobs_create.c \
						\
						src/mob-generation/ft_calc_difficulty.c \
						src/mob-generation/ft_rand_mob.c \
						\
						src/parsing/ft_check_dfs.c \
						src/parsing/ft_check_inverse_dfs.c \
						src/parsing/ft_check_map.c \
						src/parsing/ft_check_path.c \
						src/parsing/ft_parse.c \
						src/parsing/ft_parse_char.c \
						src/parsing/ft_parse_height.c \
						src/parsing/ft_parse_line.c \
						src/parsing/ft_parse_map.c \
						\
						main.c
OBJ_FILES			= $(SRC_FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES)

bonus : all

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ_FILES)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
