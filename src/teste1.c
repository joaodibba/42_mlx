/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:08:24 by jalves-c          #+#    #+#             */
/*   Updated: 2023/03/22 14:46:30 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mlxtest.h"

int	main(void)
{
	void    *mlx_ptr;
    void    *win_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (MLX_ERROR);
	win_ptr = mlx_new_window(mlx_ptr,WINDOW_WIDTH, WINDOW_HEIGHT, "Window :)");
	if (mlx_ptr == NULL)
    {
        free(win_ptr);
        return (MLX_ERROR);
    }
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
