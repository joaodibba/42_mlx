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
/*
#include "../include/mlxtest.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define MLX_ERROR 1
#define ESCAPE 65307

//colors
#define RED_PIXEL 0XFF0000

//dataa because i'm defining data in the header file
typedef struct s_dataa
{
    void    *mlx_ptr;
    void    *win_ptr;
}   t_dataa;

int handle_keypress(int keysym, t_dataa *data)
{
    if (keysym == ESCAPE)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        data->win_ptr = NULL;
    }
    printf ("Keypress: %d\n", keysym);
    return (0);
}

int handle_keyrelease(int keysym, void *data)
{
    (void)data;
    printf("keyrelease: %d\n", keysym);
    return (0);
}

int render(t_data *data)
{
    if(data->win_ptr != NULL)
        mlx_pixel_put(data->mlx_ptr, data->win_ptr,
            WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, RED_PIXEL);
    return (0);
}
int	main(void)
{
    t_dataa data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr,WINDOW_WIDTH, WINDOW_HEIGHT, "Window :)");
	if (data.mlx_ptr == NULL)
    {
        free(data.win_ptr);
        return (MLX_ERROR);
    }
    mlx_loop_hook(data.mlx_ptr, &render, &data);
    mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
    mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);

    mlx_loop(data.mlx_ptr);

	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
*/