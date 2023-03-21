/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:08:24 by jalves-c          #+#    #+#             */
/*   Updated: 2023/03/21 17:35:23 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mlxtest.h"

#define MLX_ERROR 1
#define ESC 0xFF1B

int	handle_input(int keysym, t_data *data)
{
	if (keysym == ESC)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 300, "Window :)");
	if (data.mlx_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	mlx_key_hook(data.win_ptr, &handle_input, &data);

	mlx_loop(data.mlx_ptr);

	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	free(data.mlx_ptr);
}

// void	put_pixel_img(t_img img, int x, int y, int color)
// {
// 	char	*dst;

// 	if (x >= 0 && y >= 0 && x < img.w && y < img.h) {
// 		dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
// 		*(unsigned int *) dst = color;
// 	}
// }

// t_img	new_img(int w, int h, t_win window)
// {
// 	t_img	image;

// 	image.win = window;
// 	image.img_ptr = mlx_new_image(window.mlx_ptr, w, h);
// 	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp), \
// 						&(image.line_len), &(image.endian));
// 	image.w = w;
// 	image.h = h;
// 	return (image);
// }

// t_win	new_program(int w, int h, char *str)
// {
// 	void	*mlx_ptr;

// 	mlx_ptr = mlx_init();
// 	return ((t_win){mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
// }

// int	main(void)
// {
// 	t_win	window;
// 	t_img	image;

// 	window = new_program(300, 300, "mlxtest");
// 	if (!window.win_ptr)
// 		return (2);
// 	image = new_img(300, 300, window);
// 	mlx_pixel_put(mlx_ptr, 150, 150, 0x00FFFFFF);
// 	mlx_loop(window.mlx_ptr);
// 	return (0);
// }

// int main(void)
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;

// 	mlx_ptr = mlx_init();
// 	if (!mlx_ptr)
// 		return (1);
// 	win_ptr = mlx_new_window (mlx_ptr, 300, 300, "Hello World");
// 	if (!win_ptr)
// 		return (2);
// 	mlx_loop (mlx_ptr);
// 	return (0);
// }



// #  define WINDOW_WIDTH 600
// # define WINDOW_HEIGHT 300

// int main(void)
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;

// 	mlx_ptr = mlx_init();
// 	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
// 	mlx_destroy_window(mlx_ptr, win_ptr);
// 	free(mlx_ptr);
// }