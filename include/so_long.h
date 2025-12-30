/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:13:51 by barmarti          #+#    #+#             */
/*   Updated: 2025/07/19 19:36:48 by barmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft/libft.h"
# include <stdbool.h>
# include <sys/time.h>

# define ANIM_FRAMES 3
# define ANIM_SPEED 200000

typedef struct s_point
{
	int	x;
	int	y;
}t_point;

typedef struct s_game
{
	int			collectible;
	int			exit;
	int			player;
	char		**map;
	int			move;
	t_point		*pl_pos;
	t_point		*ext_pos;
	t_point		*size;
}t_game;

typedef struct s_mlx_img
{
	void			*img_ptr;
	char			*img_pixel_ptr;
	int				bits_per_pixel;
	int				endian;
	int				line_len;
	void			*player[ANIM_FRAMES];
	void			*exit;
	void			*cons[ANIM_FRAMES];
	void			*wall;
	void			*floor;
	int				player_frame;
	int				cons_frame;
	struct timeval	last_anim;
	t_game			*game;
}t_mlx_img;

typedef struct s_mlx_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_mlx_img	*img_ptr;
}t_mlx_data;

void		change_data(t_game *g, int new_y, int new_x);
void		print_image(t_mlx_data *d);
bool		final_check(t_game *m);
void		init_image(t_mlx_data *data);
bool		check_pos(t_game *game, int y, int x);
void		get_height(int fd, t_game *m);
bool		init_fd(char *av, t_game *m);
bool		init_struct(t_mlx_data *data, char *av);
bool		init_window(t_mlx_data *data);
void		dup_error(char *src);
void		init_struct_null(t_game *m);
bool		check_size(char *line);
bool		init_game(t_game *m);
bool		parse_map(char *map_av, t_mlx_data *d);
bool		check_ext(char *map);
bool		check_len(t_game *m);
bool		check_char(t_game *m, char c, int y, int x);
bool		is_target(char	*target, char c);
void		flood_fill(t_game *m, bool use);
void		rfill(char **map, t_point *size, int pos_y, int pos_x);
bool		check_fill(char **m);
char		change_it(char c, bool use);
bool		didit_change(char c, bool use);
bool		check_double(t_game *m);
bool		check_outline(t_game *m);
bool		check_access(t_game *m);
void		free_dble_str(char **ptr);
void		free_map(t_game *m);
void		free_gnl(int fd);
void		exit_game(t_mlx_data *data, int exit_code);
int			end_game(t_mlx_data *data);
int			handle_input(int keysym, t_mlx_data *data);
void		destroy_image(t_mlx_data *d);
int			animate_sprites(t_mlx_data *data);

#endif