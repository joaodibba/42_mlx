/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste9.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:08:24 by jalves-c          #+#    #+#             */
/*   Updated: 2023/05/11 14:44:23 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mlxtest.h"

#define PLAYER_SIZE 10
#define PLAYER_SPEED 100

		//if (img->endian != 0)
		//big endian, MSB is the leftmost bit
		//little endian, LSB is the leftmost bit
		//else
void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

//The x and y coordinates of the rect correspond to its upper left corner.
int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			img_pix_put(img, j++, i, color);
		++i;
	}
}

int	handle_keypress(int keysym, t_data *data)
{
	t_player	*player;
	int			y;
	int			x;

	player = data->player;
	x = player->x;
	y = player->y;
	if (keysym == ESCAPE)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	else if (keysym == 'w')
		y -= PLAYER_SPEED;
	else if (keysym == 's')
		y += PLAYER_SPEED;
	else if (keysym == 'a')
		x -= PLAYER_SPEED;
	else if (keysym == 'd')
		x += PLAYER_SPEED;
	if (x < 0)
		x = 0;
	if (x > WINDOW_WIDTH - PLAYER_SIZE)
		x = WINDOW_WIDTH - PLAYER_SIZE;
	if (y < 0)
		y = 0;
	if (y > WINDOW_HEIGHT - PLAYER_SIZE)
		y = WINDOW_HEIGHT - PLAYER_SIZE;
	player->x = x;
	player->y = y;
	return (0);
}

int	render(t_data *data)
{
	int	x;
	int	y;

	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, WHITE_PIXEL);
	x = data->player->x;
	y = data->player->y;
	render_rect(&data->img, (t_rect){x, y, PLAYER_SIZE, \
								PLAYER_SIZE, RED_PIXEL});
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
								data->img.mlx_img, 0, 0);
	return (0);
}

int	main(void)
{
	t_data		data;
	t_player	player;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, \
		WINDOW_WIDTH, WINDOW_HEIGHT, "my window");
	if (data.win_ptr == NULL)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (MLX_ERROR);
	}
	player.x = 100;
	player.y = 100;
	data.player = &player;
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, \
									&data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, 2, 1L << 0, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
