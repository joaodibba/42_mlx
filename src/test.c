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