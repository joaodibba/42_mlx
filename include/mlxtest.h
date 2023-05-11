/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxtest.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:23:08 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/11 22:03:44 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLXTEST_H
# define MLXTEST_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500

#define MLX_ERROR 1
#define ESCAPE 65307
#define KeyPress 2
#define KeyPressMask 1L << 0
#define NoEventMask 0
#define DestroyNotify 17

//colors
#define RED_PIXEL 0XFF0000
#define GREEN_PIXEL 0XFF00
#define WHITE_PIXEL 0XFFFFFF

typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}		t_rect;

typedef struct s_img
{
    void    *mlx_img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
}   t_img;

typedef struct s_player
{
    int x;
    int y;
}   t_player;

typedef struct s_data
{
    void	*mlx_ptr;
    void   	*win_ptr;
    t_img      img;
    t_player    *player;
    int     cur_img;
}		t_data;



#endif
